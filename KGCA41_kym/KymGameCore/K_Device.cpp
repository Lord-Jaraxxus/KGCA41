 #include "K_Device.h"

bool K_Device::Init()
{
    HRESULT hr;
    if (FAILED(hr = CreateDevice())) return false;
    if (FAILED(hr = CreateDXGIDevice())) return false;
    if (FAILED(hr = CreateSwapChain())) return false;
    if (FAILED(hr = CreateRenderTargetView())) return false;
    CreateViewport();

    return true;
}

bool K_Device::Frame()
{
    return true;
}

bool K_Device::PreRender()
{
    m_pImmediateContext->OMSetRenderTargets(1, &m_pRTV, NULL);
    float color[4] = { 0.0f,0.0f,0.0f,1.0f };
    m_pImmediateContext->ClearRenderTargetView(m_pRTV, color);
    return true;
}

bool K_Device::Render()
{
    PreRender();
    PostRender();
    return true;
}

bool K_Device::PostRender()
{
    m_pSwapChain->Present(0, 0);
    return true;
}

bool K_Device::Release()
{
    if (m_pd3dDevice) m_pd3dDevice->Release();
    if (m_pImmediateContext) m_pImmediateContext->Release();
    if (m_pGIFactory) m_pGIFactory->Release();
    if (m_pSwapChain) m_pSwapChain->Release();
    if (m_pRTV) m_pRTV->Release();
    return true;
}


// 1)디바이스 만들기
HRESULT K_Device::CreateDevice()
{
    HRESULT hr;

    // 바로밑에 얘가 그래픽카드임, nullptr로 놓으면 현재 설정된 그래픽카드를 쓰겠다는 뜼
    //IDXGIAdapter* pAdapter = nullptr; 
    //D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE; 
    //HMODULE Software = NULL;
    //UINT Flags = 0;
    D3D_FEATURE_LEVEL pFeatureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
    };
    UINT FeatureLevels = 1;
    //UINT SDKVersion = D3D11_SDK_VERSION; // 묻지도 따지지도 말고 무조건 최신버전(11)
    D3D_FEATURE_LEVEL pFeatureLevel; // 대충 다이렉트 버전 몇쓸꺼? 그런느낌인듯

    hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        D3D11_CREATE_DEVICE_BGRA_SUPPORT, // D2D를 쓰려면 플래그를 이걸로 해야한다 
        pFeatureLevels,
        FeatureLevels,
        D3D11_SDK_VERSION,
        &m_pd3dDevice,
        &pFeatureLevel,
        &m_pImmediateContext
    );

    return hr;
}

// 2) 팩토리 생성
HRESULT K_Device::CreateDXGIDevice()
{
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pGIFactory);
    return hr;
}

// 3) 스왑체인 생성
HRESULT K_Device::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));

    // 필수적인 요소들만 채움
    sd.BufferCount = 1; // 백버퍼 몇개 만들래? : 하나.
    sd.BufferDesc.Width = g_rtClient.right;
    sd.BufferDesc.Height = g_rtClient.bottom; //크기는? : 클라이언트랑 똑같이.
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // 4바이트 픽셀로

    // 주사율
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 버퍼를 렌더 타겟용으로 만들겠다
    sd.OutputWindow = g_hWnd; // 요 윈도우에게 출력하겠따

    // 샘플링, 일단 디폴트값으로 지정
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;

    sd.Windowed = true; // 창모드로 띄울래, 전체화면으로 띄울래
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

    //DXGI_MODE_DESC BufferDesc;
    //DXGI_SAMPLE_DESC SampleDesc;
    //DXGI_USAGE BufferUsage;
    //UINT BufferCount;
    //HWND OutputWindow;
    //BOOL Windowed;
    //DXGI_SWAP_EFFECT SwapEffect;
    //UINT Flags;

    return m_pGIFactory->CreateSwapChain(m_pd3dDevice, &sd, &m_pSwapChain);
}

// 4) 렌더타겟뷰 생성
HRESULT K_Device::CreateRenderTargetView()
{
    HRESULT hr;
    ID3D11Texture2D* pBackBuffer = nullptr;
    // 스왑체인에서 0번 버퍼를 가져와서 만들어져 있는 백버퍼에 텍스쳐로 리턴해줘
    m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
    // 나는 이 버퍼를 갖고 렌더타겟으로 만들어 쓰겠다
    hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRTV);
    // 이제 렌더타겟뷰(에?를?) 뿌리면 결과적으로 스왑체인의 0번버퍼가 렌더가 된다
    pBackBuffer->Release(); // 렌더타겟뷰를 만든 다음엔 반드시 릴리즈 해줘야댐

    return hr;
}

// 5) 뷰포트 설정
void K_Device::CreateViewport()
{
    D3D11_VIEWPORT vp;
    vp.Width = g_rtClient.right;
    vp.Height = g_rtClient.bottom;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    m_pImmediateContext->RSSetViewports(1, &vp);
}

HRESULT K_Device::ResizeDevice(UINT width, UINT height)
{
    HRESULT hr;
    if (m_pd3dDevice == nullptr) return S_OK; // 윈도우를 생성할 때도 VM_SIZE 메세지가 호출되기 때문, 그때는 얘가 없응꼐

    if(FAILED(hr = DeleteDXResource())) return hr; // 렌더타겟이랑 연결된 놈들 먼저 지워주고

    // 현재 설정된 랜더타겟 해제 및 소멸
    m_pImmediateContext->OMSetRenderTargets(0, nullptr, NULL); 
    if (m_pRTV != nullptr)
    {
        m_pRTV->Release();
    }

    // 백버퍼의 크기를 조정
    DXGI_SWAP_CHAIN_DESC CurrentSD, AfterSD;
    m_pSwapChain->GetDesc(&CurrentSD);
    hr = m_pSwapChain->ResizeBuffers(CurrentSD.BufferCount, width, height, CurrentSD.BufferDesc.Format, 0);

    // 변경된 백버퍼의 크기를 얻는다, 근데 쌤 코드에서는 여기가 없네? 머임? 
    // 딱히 필요가 없었나? 아 위에 윈도우에서 VM_SIZE 검거했을때 이미 해줘서그릉가
    m_pSwapChain->GetDesc(&AfterSD);
    GetClientRect(m_hWnd, &g_rtClient);

    // 변경된 백 버퍼의 크기를 얻고 렌더타켓 뷰를 다시 생성 및 적용 -> CreateRenderTargetView() 한번하면 끝 ㅎ
    if (FAILED(hr = CreateRenderTargetView())) return hr;
    // 뷰포트 재 지정
    CreateViewport();
    // 연결된 놈들 다시 살려줌
    if (FAILED(hr = CreateDXResource())) return hr;
    
    return S_OK;
}

HRESULT K_Device::CreateDXResource()
{
    return S_OK;
}

HRESULT K_Device::DeleteDXResource()
{
    return S_OK;
}


