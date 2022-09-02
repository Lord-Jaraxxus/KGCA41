#pragma once
#include "K_Std.h"

class K_Device
{
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
public:
	bool PreRender();
	bool PostRender();

public:
	// �������̽� -> �ϵ���� ���� ����
	ID3D11Device* m_pD3dDevice = nullptr; // ����̽� ��ü
	ID3D11DeviceContext* m_pImmediateContext = nullptr; // �׷��� �갡 ����?
	// m_pD3dDevice : �ٸ� �������̽� ������ ����Ѵ�
	// m_pImmediateContext : ������ �������̽��� ���(����,����) �Ҷ� ����Ѵ�
	IDXGIFactory* m_pGIFactory = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11RenderTargetView* m_pRTV = nullptr;

public:
	HRESULT CreateDevice();		// 1) ����̽� ����
	HRESULT CreateDXGIDevice(); // 2) ���丮 ����
	HRESULT CreateSwapChain();	// 3) ����ü�� ����
	HRESULT CreateRenderTargetView();	// 4) ����Ÿ�ٺ� ����
	void CreateViewport();	// 5) ����Ʈ ����

public:
	//bool K_CoreInit();
	//bool K_CoreFrame(); 
	//bool K_CorePreRender();
	//bool K_CoreRender();
	//bool K_CorePostRender();
	//bool K_CoreRelease();
};

