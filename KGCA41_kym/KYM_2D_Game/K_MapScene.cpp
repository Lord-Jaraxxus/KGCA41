#include "K_MapScene.h"

bool K_MapScene::Init()
{
	m_vCameraPos = { 160,0 };

	K_Texture* pMapTopMask = I_Tex.Load(L"../../data/img/map/mapTop.png");
	K_Map* MapTop = new K_Map;
	MapTop->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/mapTop.png", L"../KymGameCore/MaskShape_Png.txt");
	MapTop->SetMask(pMapTopMask);
	MapTop->SetCamera(m_vCameraPos);
	MapTop->SetRect({ 0, 0, (float)MapTop->m_pTexture->m_Desc.Width, (float)MapTop->m_pTexture->m_Desc.Height });
	MapTop->SetPosition({ 0, 0 });
	m_pBackGroundList.push_back(MapTop);

	K_Texture* pMapMidMask = I_Tex.Load(L"../../data/img/map/mapMid.png");
	K_Map* MapMid = new K_Map;
	MapMid->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/mapMid.png", L"../KymGameCore/MaskShape_Png.txt");
	MapMid->SetMask(pMapMidMask);
	MapMid->SetCamera(m_vCameraPos);
	MapMid->SetRect({ 0, 0, (float)MapMid->m_pTexture->m_Desc.Width, (float)MapMid->m_pTexture->m_Desc.Height });
	MapMid->SetPosition({ 0, 1080 });
	m_pBackGroundList.push_back(MapMid);

	K_Texture* pMapBottomMask = I_Tex.Load(L"../../data/img/map/mapBot.png");
	K_Map* MapBottom = new K_Map;
	MapBottom->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/mapBot.png", L"../KymGameCore/MaskShape_Png.txt");
	MapBottom->SetMask(pMapBottomMask);
	MapBottom->SetCamera(m_vCameraPos);
	MapBottom->SetRect({ 0, 0, (float)MapBottom->m_pTexture->m_Desc.Width, (float)MapBottom->m_pTexture->m_Desc.Height });
	MapBottom->SetPosition({ 0, 2060 });
	m_pBackGroundList.push_back(MapBottom);

	K_Texture* pMonsterMask = I_Tex.Load(L"../../data/img/map/monster.png");
	K_MapObject* pMonster1 = new K_MapObject;
	pMonster1->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/monster.png", L"../../data/shader/MaskShape_Png_Black.txt");
	pMonster1->SetMask(pMonsterMask);
	pMonster1->SetCamera(m_vCameraPos);
	pMonster1->SetRect({ 0, 0, (float)pMonster1->m_pTexture->m_Desc.Width, (float)pMonster1->m_pTexture->m_Desc.Height });
	pMonster1->SetPosition({ 700, 700 });
	pMonster1->m_iStage = 0;
	m_pMapObjectList.push_back(pMonster1);

	K_MapObject* pMonster2 = new K_MapObject;
	pMonster2->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/monster.png", L"../../data/shader/MaskShape_Png_Black.txt");
	pMonster2->SetMask(pMonsterMask);
	pMonster2->SetCamera(m_vCameraPos);
	pMonster2->SetRect({ 0, 0, (float)pMonster2->m_pTexture->m_Desc.Width, (float)pMonster2->m_pTexture->m_Desc.Height });
	pMonster2->SetPosition({ 1400, 700 });
	pMonster2->m_iStage = 0;
	m_pMapObjectList.push_back(pMonster2);

	K_MapObject* pMonster3 = new K_MapObject;
	pMonster3->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/map/monster.png", L"../../data/shader/MaskShape_Png_Black.txt");
	pMonster3->SetMask(pMonsterMask);
	pMonster3->SetCamera(m_vCameraPos);
	pMonster3->SetRect({ 0, 0, (float)pMonster3->m_pTexture->m_Desc.Width, (float)pMonster3->m_pTexture->m_Desc.Height });
	pMonster3->SetPosition({ 1000, 400 });
	pMonster3->m_iStage = 1;
	m_pMapObjectList.push_back(pMonster3);

	return true;
}

bool K_MapScene::Frame()
{
	if (I_Input.GetKey('W') == KEY_HOLD) m_vCameraPos.y -= 500.0f * g_fSecondPerFrame;
	if (I_Input.GetKey('S') == KEY_HOLD) m_vCameraPos.y += 500.0f * g_fSecondPerFrame;

	k_Vector2D vMousePosMove;
	vMousePosMove.x = I_Input.m_ptPos.x - m_vMousePos.x;
	vMousePosMove.y = I_Input.m_ptPos.y - m_vMousePos.y;
	m_vMousePos.x = I_Input.m_ptPos.x;
	m_vMousePos.y = I_Input.m_ptPos.y;
	if (I_Input.GetKey(VK_LBUTTON) == KEY_PUSH) m_bLButtonState = true;
	if (I_Input.GetKey(VK_LBUTTON) == KEY_UP) m_bLButtonState = false;
	if (m_bLButtonState == true) m_vCameraPos.y += vMousePosMove.y * -1.0f;

	for (auto obj : m_pBackGroundList) 
	{ 
		obj->SetCamera(m_vCameraPos);
		obj->SetPosition(obj->m_vPos);
		obj->Frame(); 
	}

	for (auto obj : m_pMapObjectList)
	{
		obj->SetCamera(m_vCameraPos);
		obj->SetPosition(obj->m_vPos);
		obj->Frame();
	}

	return true;
}

bool K_MapScene::Render()
{
	for (auto obj : m_pBackGroundList) { obj->Render(); }
	for (auto obj : m_pMapObjectList) { obj->Render(); }

	for (auto obj : m_pMapObjectList) 
	{
		if (obj->m_bButtonPushed && obj->m_iStage == m_iStage)
		{
			m_iSceneState = 1;
			m_iStage++;
		}
	}
	return true;
}

bool K_MapScene::Release()
{
	for (auto obj : m_pBackGroundList) { obj->Release(); }
	for (auto obj : m_pMapObjectList) { obj->Release(); }

	return true;
}
