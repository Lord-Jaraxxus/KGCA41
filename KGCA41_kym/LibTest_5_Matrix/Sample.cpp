#include "Sample.h"
#include "K_TextureManager.h"

bool Sample::Init() 
{
	m_pBG = new K_BaseObject;
	m_pBG->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map.jpg", L"../../data/shader/DefaultObject.txt");

	m_pMap = new K_Map;
	// 2*n½Â+1
	m_pMap->Build(512 + 1, 512 + 1);
	m_pMap->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/map/Tile50.jpg", L"../../data/shader/DefaultObject.txt");

	m_pBoxObjA = new K_ShapeBox;
	m_pBoxObjA->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map.jpg", L"../../data/shader/DefaultObject.txt");
	m_pBoxObjA->m_matWorld = m_pBoxObjA->m_matWorld.Translation(0, 0, 2);

	m_pBoxObjB = new K_ShapeBox;
	m_pBoxObjB->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map.jpg", L"../../data/shader/DefaultObject.txt");
	m_pBoxObjB->m_matWorld = m_pBoxObjB->m_matWorld.Translation(2, 0, 4);

	m_pMainCamera = new K_Camera;
	m_pMainCamera->CreateViewMatrix(k_Vector(0, 100, -50.0f), k_Vector(0, 0, 0), k_Vector(0, 1, 0));
	m_pMainCamera->CreateProjMatrix(1.0f, 10000.0f, 3.141592f * 0.5f, (float)g_rtClient.right / (float)g_rtClient.bottom);

	return true; 
}

bool Sample::Frame()
{
	m_pBG->Frame();
	m_pMainCamera->Frame();
	m_pBoxObjA->Frame();
	m_pBoxObjB->Frame();

	return true;
}

bool Sample::Render()
{
	//m_pBG->Render();

	m_pMap->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matProj);
	m_pMap->Render();

	m_pBoxObjA->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matProj);
	m_pBoxObjA->Render();

	m_pBoxObjB->SetMatrix(nullptr, &m_pMainCamera->m_matView, &m_pMainCamera->m_matProj);
	m_pBoxObjB->Render();

	return true;
}

bool Sample::Release()
{
	m_pBG->Release();
	delete m_pBG;
	m_pMap->Release();
	delete m_pMap;
	m_pBoxObjA->Release();
	delete m_pBoxObjA;
	m_pBoxObjB->Release();
	delete m_pBoxObjB;
	m_pMainCamera->Release();
	delete m_pMainCamera;

	return true; 
}


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

GAME_RUN(CreateObject, 800, 900)
