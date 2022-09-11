//#pragma once
//#include <windows.h>
//#include <map>
#pragma once

#include <map>
#include <vector>
#include <list>
#include <set>
#include <string>
#pragma comment(lib, "winmm.lib") // timeGetTime

// 윈도우
//#include <windows.h>

// 디바이스
#include <d3d11.h>
//#pragma comment(lib, "d3d11.lib")
//#pragma comment(lib, "dxgi.lib")

// 쉐이더
//#pragma comment(lib, "d3dcompiler.lib")
//#include <d3dcompiler.h> // D3DCompileFromFile()

// 텍스처
//#include "WICTextureLoader.h"
//#include "DDSTextureLoader.h"
//#pragma comment(lib, "DirectXTK.lib")

// 베이스 오브젝트
//#include"k_Vector.h"
//#include"k_Vector2D.h"


extern HWND g_hWnd;
extern RECT g_rtClient;

extern float g_fGameTimer;
extern float g_fSecondPerFrame;

#define GAME_START	int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) { 
#define GAME_WINDOW(s,x,y)	Sample demo; demo.SetWindow(hInstance, L#s, x, y); demo.Run(); return 1;
#define GAME_END		 }
#define GAME_RUN(s,x,y)	GAME_START GAME_WINDOW(s,x,y) GAME_END


// 싱글톤 패턴
template<class T> class K_Singleton
{
public:
	static T& GetInstance() 
	{
		static T theSingleInstance;
		return theSingleInstance;
	}
};