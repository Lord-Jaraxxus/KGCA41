#include "K_BattleScene.h"

bool K_BattleScene::Init()
{
	m_pBackGround = new K_BackGround;
	m_pBackGround->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/battle/background.jpg", L"../KymGameCore/DefaultShape.txt");
	m_pBackGround->SetRect({ 0, 0, 1920, 1140 });
	m_pBackGround->SetPosition({ 0, 0 });

	K_Texture* pPlayerMask = I_Tex.Load(L"../../data/img/battle/Player_Stand.png");
	m_pPlayer = new K_2dObject;
	m_pPlayer->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/battle/Player_Stand.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pPlayer->SetMask(pPlayerMask);
	m_pPlayer->SetRect({ 0, 0, (float)m_pPlayer->m_pTexture->m_Desc.Width, (float)m_pPlayer->m_pTexture->m_Desc.Height });
	m_pPlayer->SetPosition({ 200, 200 });

	K_Texture* pEnemyMask = I_Tex.Load(L"../../data/img/enemy/GremlinLeader.png");
	m_pEnemy = new K_2dObject;
	m_pEnemy->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/enemy/GremlinLeader.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pEnemy->SetMask(pEnemyMask);
	m_pEnemy->SetRect({ 0, 0, (float)m_pEnemy->m_pTexture->m_Desc.Width, (float)m_pEnemy->m_pTexture->m_Desc.Height });
	m_pEnemy->SetPosition({ 1200, 500 });

	K_Texture* pCardMask1 = I_Tex.Load(L"../../data/img/card/Strike.png");
	K_Card* Card1 = new K_Card;
	Card1->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/card/Strike.png", L"../KymGameCore/MaskShape_Png.txt");
	Card1->SetMask(pCardMask1);
	Card1->SetRect({ 0, 0, (float)Card1->m_pTexture->m_Desc.Width, (float)Card1->m_pTexture->m_Desc.Height });
	Card1->SetPosition({ 400, 500 });
	m_pCardList.push_back(Card1);

	return true;
} 

bool K_BattleScene::Frame()
{
	m_pBackGround->Frame();
	m_pPlayer->Frame();
	m_pEnemy->Frame();
	for (auto obj : m_pCardList) { obj->Frame(); }

	return true;
}

bool K_BattleScene::Render()
{
	m_pBackGround->Render();
	m_pPlayer->Render();
	m_pEnemy->Render();
	for (auto obj : m_pCardList) { obj->Render(); }

	return true;
}

bool K_BattleScene::Release()
{
	m_pBackGround->Release();
	m_pPlayer->Release();
	m_pEnemy->Release();
	for (auto obj : m_pCardList) { obj->Release(); }

	return true;
}
