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

bool K_Device::Render()
{
    m_pImmediateContext->OMSetRenderTargets(1, &m_pRTV, NULL); // ���⿡ �ѷ��a
    static float fGreen = 0.0f;
    fGreen += 0.00001f;
    float color[4] = { 1.0f, fGreen, 0, 1.0f };
    m_pImmediateContext->ClearRenderTargetView(m_pRTV, color);
    m_pSwapChain->Present(0, 0); // ����۶� ����Ʈ���۶� �ٲ��Ķ�
    return true;
}

bool K_Device::Release()
{
    if (m_pD3dDevice) m_pD3dDevice->Release();
    if (m_pImmediateContext) m_pImmediateContext->Release();
    if (m_pGIFactory) m_pGIFactory->Release();
    if (m_pSwapChain) m_pSwapChain->Release();
    if (m_pRTV) m_pRTV->Release();
    return true;
}

// 1)����̽� �����
HRESULT K_Device::CreateDevice()
{
    HRESULT hr;

    // �ٷιؿ� �갡 �׷���ī����, nullptr�� ������ ���� ������ �׷���ī�带 ���ڴٴ� ��
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
    //UINT SDKVersion = D3D11_SDK_VERSION; // ������ �������� ���� ������ �ֽŹ���(11)
    D3D_FEATURE_LEVEL pFeatureLevel; // ���� ���̷�Ʈ ���� ���? �׷������ε�

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

// 2) ���丮 ����
HRESULT K_Device::CreateDXGIDevice()
{
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pGIFactory);
    return hr;
}

// 3) ����ü�� ����
HRESULT K_Device::CreateSwapChain()
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));

    // �ʼ����� ��ҵ鸸 ä��
    sd.BufferCount = 1; // ����� � ���鷡? : �ϳ�.
    sd.BufferDesc.Width = g_rtClient.right;
    sd.BufferDesc.Height = g_rtClient.bottom; //ũ���? : Ŭ���̾�Ʈ�� �Ȱ���.
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // 4����Ʈ �ȼ���

    // �ֻ���
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ���۸� ���� Ÿ�ٿ����� ����ڴ�
    sd.OutputWindow = g_hWnd; // �� �����쿡�� ����ϰڵ�

    // ���ø�, �ϴ� ����Ʈ������ ����
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;

    sd.Windowed = true; // â���� ��﷡, ��üȭ������ ��﷡
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

// 4) ����Ÿ�ٺ� ����
HRESULT K_Device::CreateRenderTargetView()
{
    HRESULT hr;
    ID3D11Texture2D* pBackBuffer = nullptr;
    // ����ü�ο��� 0�� ���۸� �����ͼ� ������� �ִ� ����ۿ� �ؽ��ķ� ��������
    m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
    // ���� �� ���۸� ���� ����Ÿ������ ����� ���ڴ�
    hr = m_pD3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRTV);
    // ���� ����Ÿ�ٺ�(��?��?) �Ѹ��� ��������� ����ü���� 0�����۰� ������ �ȴ�
    pBackBuffer->Release(); // ����Ÿ�ٺ並 ���� ������ �ݵ�� ������ ����ߴ�

    return hr;
}

// 5) ����Ʈ ����
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