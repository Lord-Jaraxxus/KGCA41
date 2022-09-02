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
    return false;
}

bool K_Device::Render()
{
    PreRender();
    // 삼각형 렌더링
    PostRender();
    return false;
}

bool K_Device::Release()
{
    if (m_pD3dDevice) m_pD3dDevice->Release();
    if (m_pImmediateContext) m_pImmediateContext->Release();
    if (m_pGIFactory) m_pGIFactory->Release();
    if (m_pSwapChain) m_pSwapChain->Release();
    if (m_pRTV) m_pRTV->Release();
    return false;
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
        D3D_FEATURE_LEVEL_12_0,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0
    };
    UINT FeatureLevels = 3;
    //UINT SDKVersion = D3D11_SDK_VERSION; // 묻지도 따지지도 말고 무조건 최신버전(11)
    D3D_FEATURE_LEVEL pFeatureLevel; // 대충 다이렉트 버전 몇쓸꺼? 그런느낌인듯

    hr = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        0,
        pFeatureLevels,
        FeatureLevels,
        D3D11_SDK_VERSION,
        &m_pD3dDevice,
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

    HRESULT hr = m_pGIFactory->CreateSwapChain(m_pD3dDevice, &sd, &m_pSwapChain);

    return hr;
}

// 4) 렌더타겟뷰 생성
HRESULT K_Device::CreateRenderTargetView()
{
    HRESULT hr;
    ID3D11Texture2D* pBackBuffer = nullptr;
    // 스왑체인에서 0번 버퍼를 가져와서 만들어져 있는 백버퍼에 텍스쳐로 리턴해줘
    m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
    // 나는 이 버퍼를 갖고 렌더타겟으로 만들어 쓰겠다
    hr = m_pD3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRTV);
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

bool K_Device::PreRender()
{
    m_pImmediateContext->OMSetRenderTargets(1, &m_pRTV, NULL); // 여기에 뿌려줭
    static float fGreen = 0.0f;
    fGreen += 0.00001f;
    float color[4] = { 1.0f, fGreen, 0, 1.0f };
    m_pImmediateContext->ClearRenderTargetView(m_pRTV, color);
    return false;
}

bool K_Device::PostRender()
{
    m_pSwapChain->Present(0, 0); // 백버퍼랑 프론트버퍼랑 바꿔쳐라
    return false;
}
