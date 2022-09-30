#include "K_TitleScene.h"

bool K_TitleScene::Init()
{
	K_BackGround* cloud = new K_BackGround;
	cloud->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/title.jpg", L"../KymGameCore/DefaultShape.txt");
	cloud->SetRect({ 0, 500, (float)g_rtClient.right, (float)g_rtClient.bottom });
	cloud->SetPosition({ 0, 0 });
	m_pBackGroundList.push_back(cloud);

	K_Texture* pTowerMaskTex = I_Tex.Load(L"../../data/img/title2.png");
	K_BackGround* tower = new K_BackGround;
	tower->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/title2.png", L"../KymGameCore/MaskShape_Png.txt");
	tower->SetMask(pTowerMaskTex);
	tower->SetRect({ 0, 860, 1920, 1118 });
	tower->SetPosition({ 0, 0 });
	m_pBackGroundList.push_back(tower);

	K_Texture* pButtonMask = I_Tex.Load(L"../../data/img/TitleButton.png");
	m_pStartButton = new K_Button;
	m_pStartButton->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/TitleButton.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pStartButton->SetMask(pButtonMask);
	m_pStartButton->SetRect({ 0, 0, 180, 50 });
	m_pStartButton->SetPosition({ 800, 450 });
	m_pBackGroundList.push_back(m_pStartButton);

	m_pSettingButton = new K_Button;
	m_pSettingButton->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/TitleButton.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pSettingButton->SetMask(pButtonMask);
	m_pSettingButton->SetRect({ 0, 50, 180, 52 });
	m_pSettingButton->SetPosition({ 800, 550 });
	m_pBackGroundList.push_back(m_pSettingButton);

	m_pEndButton = new K_Button;
	m_pEndButton->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/TitleButton.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pEndButton->SetMask(pButtonMask);
	m_pEndButton->SetRect({ 0, 102, 180, 52 });
	m_pEndButton->SetPosition({ 800, 650 });
	m_pBackGroundList.push_back(m_pEndButton);

	return true;
}

bool K_TitleScene::Frame()
{
	for (auto obj : m_pBackGroundList) { obj->Frame(); }
	if (m_pStartButton->m_bButtonPushed == true) m_iSceneState = 1;
	if (m_pEndButton->m_bButtonPushed == true) m_iSceneState = 2;
	return true;
}

bool K_TitleScene::Render()
{
	for (auto obj : m_pBackGroundList) { obj->Render(); }

	//std::wstring MousePos = std::to_wstring(I_Input.m_ptPos.x);
	//MousePos += L" ";
	//MousePos += std::to_wstring(I_Input.m_ptPos.y);
	//MousePos += L"\n";
	//I_Write.Draw(1200, 450, MousePos, { 1,0,0,1 });

	return true;
}

bool K_TitleScene::Release()
{
	for (auto obj : m_pBackGroundList) { obj->Release(); }
	return true;
}
