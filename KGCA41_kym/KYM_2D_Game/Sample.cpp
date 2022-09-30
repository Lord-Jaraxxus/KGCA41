#include "Sample.h"

bool Sample::Init() 
{
	m_pTitleScene = new K_TitleScene;
	m_pTitleScene->SetDevice(m_pd3dDevice, m_pImmediateContext);
	m_pTitleScene->Init();

	m_pMapScene = new K_MapScene;
	m_pMapScene->SetDevice(m_pd3dDevice, m_pImmediateContext);
	m_pMapScene->Init();

	m_pBattleScene = new K_BattleScene;
	m_pBattleScene->SetDevice(m_pd3dDevice, m_pImmediateContext);
	m_pBattleScene->Init();
	m_pBattleScene->m_pDeck = m_pDeck;

	m_pTestScene = new K_Scene;
	m_pTestScene->SetDevice(m_pd3dDevice, m_pImmediateContext);
	m_pTestScene->Init();

	m_pCurrentScene = m_pTitleScene;
	return true; 
}

bool Sample::Frame()
{
	m_pCurrentScene->Frame();
	return true;
}

bool Sample::Render()
{
	m_pCurrentScene->Render();

	if (m_pCurrentScene == m_pTitleScene && m_pCurrentScene->m_iSceneState == 1) m_pCurrentScene = m_pMapScene;
	if (m_pCurrentScene == m_pMapScene && m_pCurrentScene->m_iSceneState == 1)
	{
		m_pCurrentScene->m_iSceneState = 0;
		m_pCurrentScene = m_pBattleScene;
	}

	return true;
}

bool Sample::Release()
{
	m_pTitleScene->Release();
	delete m_pTitleScene;
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

GAME_RUN(CreateObject, 1600, 900)
