#include "Sample.h"


//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPWSTR    lpCmdLine,
//    _In_ int       nCmdShow) 
//{
//    Sample demo;
//    demo.SetWindow(hInstance);
//    demo.Run();
//    return 1;
//}  

bool Sample::Init() 
{
	return true; 
}

bool Sample::Frame()
{
	if (I_Input.GetKey(VK_SPACE) == KEY_HOLD)
	{
	}
	return true;
}

bool Sample::Render()
{

	return true;
}

bool Sample::Release()
{

	return true; 
}



GAME_RUN(CreateObject, 1024, 768)