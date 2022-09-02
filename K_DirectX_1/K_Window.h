#pragma once
#include "K_Device.h"

class K_Window : public K_Device
{
public: 
	HINSTANCE	m_hInstance; // 접수번호
	HWND		m_hWnd;		 // 등기번호
	RECT		m_rtWindow;
	RECT		m_rtClient;
	DWORD		m_csStyle;
	UINT		m_iClientWidth;
	UINT		m_iClientHeight;

#ifdef _DEBUG
	std::vector<UINT> msglist;
#endif

public:
	bool SetWindow(HINSTANCE hInstance, const WCHAR* szTitle, UINT iWidth = 1600, UINT iHeight = 900);
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight);
	LRESULT MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	bool Run();
	void CenterWindow();

public:
	virtual bool K_CoreInit();
	virtual bool K_CoreFrame();
	virtual bool K_CoreRender();
	virtual bool K_CoreRelease();

public:
	K_Window();

}; 

