#include "K_BattleScene.h"

bool K_BattleScene::Init()
{
	m_iEnemyMaxHP = 30;
	m_iEnemyCurrentHP = m_iEnemyMaxHP;

	m_pBackGround = new K_BackGround;
	m_pBackGround->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/battle/background.jpg", L"../KymGameCore/DefaultShape.txt");
	m_pBackGround->SetRect({ 0, 0, 1920, 1140 });
	m_pBackGround->SetPosition({ 0, 0 });


	K_Texture* pPlayerMask = I_Tex.Load(L"../../data/img/battle/Player_Stand.png");
	m_pPlayer = new K_Character;
	m_pPlayer->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/battle/Player_Stand.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pPlayer->SetMask(pPlayerMask);
	m_pPlayer->SetRect({ 0, 0, (float)m_pPlayer->m_pTexture->m_Desc.Width, (float)m_pPlayer->m_pTexture->m_Desc.Height });
	m_pPlayer->SetPosition({ 200, 700 });
	m_pPlayer->SetDrawSize({ m_pPlayer->m_rtInit.z / g_rtClient.right, m_pPlayer->m_rtInit.w / g_rtClient.bottom});
	m_pPlayer->SetDrawPos();

	K_Texture* pEnemyMask = I_Tex.Load(L"../../data/img/enemy/GremlinLeader.png");
	m_pEnemy = new K_Character;
	m_pEnemy->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/enemy/GremlinLeader.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pEnemy->SetMask(pEnemyMask);
	m_pEnemy->SetRect({ 0, 0, (float)m_pEnemy->m_pTexture->m_Desc.Width, (float)m_pEnemy->m_pTexture->m_Desc.Height });
	m_pEnemy->SetPosition({ 1200, 700 });
	m_pEnemy->SetDrawPos();


	K_Texture* pTurnEndButtonMask = I_Tex.Load(L"../../data/img/battle/TurnEndButton.png");
	m_pTurnEndButton = new K_Button;
	m_pTurnEndButton->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/battle/TurnEndButton.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pTurnEndButton->SetMask(pTurnEndButtonMask);
	m_pTurnEndButton->SetRect({ 0, 0, 180, 70 });
	m_pTurnEndButton->SetPosition({ 800, 300 });


	K_Texture* pTextureCard0 = I_Tex.Load(L"../../data/img/card/0_Strike.png");
	K_Texture* pTextureCard1 = I_Tex.Load(L"../../data/img/card/1_Defend.png");
	K_Texture* pTextureCard2 = I_Tex.Load(L"../../data/img/card/2_PommelStrike.png");
	K_Texture* pTextureCard3 = I_Tex.Load(L"../../data/img/card/3_ShrugItOff.png");
	K_Texture* pTextureCard4 = I_Tex.Load(L"../../data/img/card/4_Hemokinesis.png");
	K_Texture* pTextureCard5 = I_Tex.Load(L"../../data/img/card/5_Bludgeon.png");
	m_pCardTextureList.push_back(pTextureCard0);
	m_pCardTextureList.push_back(pTextureCard1);
	m_pCardTextureList.push_back(pTextureCard2);
	m_pCardTextureList.push_back(pTextureCard3);
	m_pCardTextureList.push_back(pTextureCard4);
	m_pCardTextureList.push_back(pTextureCard5);

	K_Texture* pCardMask = I_Tex.Load(L"../../data/img/card/0_Strike.png");
	K_Card* Card1 = new K_Card;
	Card1->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/card/0_Strike.png", L"../KymGameCore/MaskShape_Png.txt");
	Card1->SetMask(pCardMask);
	Card1->SetRect({ 0, 0, (float)Card1->m_pTexture->m_Desc.Width, (float)Card1->m_pTexture->m_Desc.Height });
	Card1->SetPosition({ 500, 700 });
	Card1->m_vPosOrigin = {500, 700};
	Card1->m_iCardNum = 0;
	m_pCardList.push_back(Card1);

	K_Card* Card2 = new K_Card;
	Card2->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/card/0_Strike.png", L"../KymGameCore/MaskShape_Png.txt");
	Card2->SetMask(pCardMask);
	Card2->SetRect({ 0, 0, (float)Card2->m_pTexture->m_Desc.Width, (float)Card2->m_pTexture->m_Desc.Height });
	Card2->SetPosition({ 700, 700 });
	Card2->m_vPosOrigin = { 700, 700 };
	Card2->m_iCardNum = 0;
	m_pCardList.push_back(Card2);

	K_Card* Card3 = new K_Card;
	Card3->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/card/0_Strike.png", L"../KymGameCore/MaskShape_Png.txt");
	Card3->SetMask(pCardMask);
	Card3->SetRect({ 0, 0, (float)Card3->m_pTexture->m_Desc.Width, (float)Card3->m_pTexture->m_Desc.Height });
	Card3->SetPosition({ 900, 700 });
	Card3->m_vPosOrigin = { 900, 700 };
	Card3->m_iCardNum = 0;
	m_pCardList.push_back(Card3);

	K_Card* Card4 = new K_Card;
	Card4->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/card/0_Strike.png", L"../KymGameCore/MaskShape_Png.txt");
	Card4->SetMask(pCardMask);
	Card4->SetRect({ 0, 0, (float)Card4->m_pTexture->m_Desc.Width, (float)Card4->m_pTexture->m_Desc.Height });
	Card4->SetPosition({ 1100, 700 });
	Card4->m_vPosOrigin = { 1100, 700 };
	Card4->m_iCardNum = 0;
	m_pCardList.push_back(Card4);

	
	K_Texture* pTextureEnemyIntent1 = I_Tex.Load(L"../../data/img/intent/attack_intent_1.png");
	K_Texture* pTextureEnemyIntent2 = I_Tex.Load(L"../../data/img/intent/attack_intent_2.png");
	K_Texture* pTextureEnemyIntent3 = I_Tex.Load(L"../../data/img/intent/attack_intent_3.png");
	K_Texture* pTextureEnemyIntent4 = I_Tex.Load(L"../../data/img/intent/attack_intent_4.png");
	K_Texture* pTextureEnemyIntent5 = I_Tex.Load(L"../../data/img/intent/attack_intent_5.png");
	K_Texture* pTextureEnemyIntent6 = I_Tex.Load(L"../../data/img/intent/attack_intent_6.png");
	K_Texture* pTextureEnemyIntent7 = I_Tex.Load(L"../../data/img/intent/attack_intent_7.png");
	K_Texture* pTextureEnemyIntent8 = I_Tex.Load(L"../../data/img/intent/heal_intent_1.png");

	m_pEnemyIntent = new K_EnemyIntent;
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent1);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent2);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent3);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent4);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent5);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent6);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent7);
	m_pEnemyIntent->m_pEnemyIntentTextureList.push_back(pTextureEnemyIntent8);

	m_pEnemyIntent->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/intent/attack_intent_3.png", L"../KymGameCore/MaskShape_Png.txt");
	m_pEnemyIntent->SetMask(pTextureEnemyIntent3);
	m_pEnemyIntent->SetRect({ 0, 0, (float)m_pEnemyIntent->m_pTexture->m_Desc.Width, (float)m_pEnemyIntent->m_pTexture->m_Desc.Height });
	m_pEnemyIntent->SetPosition({ 1220, 300 });


	return true;
} 

bool K_BattleScene::Frame()
{
	m_pBackGround->Frame();
	m_pPlayer->Frame();
	m_pEnemy->Frame();
	m_pTurnEndButton->Frame();
	for (auto obj : m_pCardList) { obj->Frame(); }

	if (m_pTurnEndButton->m_bButtonPushed == true)
	{
		m_pDeck->TurnEnd();
		m_iTurn++;
		m_pTurnEndButton->m_bButtonPushed = false;
	}

	Combat(m_iTurn);

	m_pEnemyIntent->Frame();

	return true;
}

bool K_BattleScene::Render()
{
	m_pBackGround->Render();
	m_pPlayer->Render();
	m_pEnemy->Render();
	m_pTurnEndButton->Render();
	m_pEnemyIntent->Render();

	for (auto obj : m_pCardList) 
	{ 
		if (obj->m_bUsed == false) { obj->Render(); }
	}

	std::wstring PlayerHP = std::to_wstring(m_iPlayerCurrentHP);
	PlayerHP += L"/";
	PlayerHP += std::to_wstring(m_iPlayerMaxHP);
	I_Write.Draw(250, 700, PlayerHP, { 1,0,0,1 });

	std::wstring PlayerShield = L"방어도 : ";
	PlayerShield += std::to_wstring(m_iPlayerShield);
	I_Write.Draw(200, 750, PlayerShield, { 0.8f, 0.8f, 0.8f, 1 });

	std::wstring EnemyHP = std::to_wstring(m_iEnemyCurrentHP);
	EnemyHP += L"/";
	EnemyHP += std::to_wstring(m_iEnemyMaxHP);
	I_Write.Draw(1300, 700, EnemyHP, { 1,0,0,1 });

	std::wstring EnemyIntentPower = std::to_wstring(m_iEnemyIntentPower);
	I_Write.Draw(1320, 340, EnemyIntentPower, { 1,1,1,1 });

	std::wstring Mana = L"마나 : "; // 이거 이미지로 교체해야하는디,,,
	Mana += std::to_wstring(m_iCurrentMana);
	Mana += L"/";
	Mana += std::to_wstring(m_iMaxMana);
	I_Write.Draw(250, 300, Mana, { 0,0,1,1 });

	return true;
}

bool K_BattleScene::Release()
{
	m_pBackGround->Release();
	m_pPlayer->Release();
	m_pEnemy->Release();
	m_pTurnEndButton->Release();
	m_pEnemyIntent->Release();
	for (auto obj : m_pCardList) { obj->Release(); }

	return true;
}





void K_BattleScene::SetDeck(K_Deck* deck)
{
	m_pDeck = deck;
}

void K_BattleScene::SetPlayerHP(int currentHP, int maxHP)
{
	m_iPlayerCurrentHP = currentHP;
	m_iPlayerMaxHP = maxHP;
}

void K_BattleScene::Combat(int turn)
{
	if (m_bTurnStart == true) 
	{
		m_pDeck->Draw(4);
		m_bTurnStart = false;
		CardSetting();
	}

	if (turn % 2 == 0) 
	{
		for (auto obj : m_pCardList) 
		{ 
			if (obj->m_bUsed == true && obj->m_bAvailable == true)
			{
				if (m_iCurrentMana < obj->m_iCardMana)
				{
					obj->m_bUsed = false;
				}
				else 
				{
					m_iCurrentMana -= obj->m_iCardMana;
					CardUsed(obj->m_iCardNum);
					obj->m_bAvailable = false;
				}
			}
		}
		
		if (m_iTurn % 3 == 0)
		{
			m_iEnemyIntentPower = 7;
			m_pEnemyIntent->m_pTexture = m_pEnemyIntent->m_pEnemyIntentTextureList[2];
			m_pEnemyIntent->SetMask(m_pEnemyIntent->m_pEnemyIntentTextureList[2]);
		}
		else if (m_iTurn % 3 == 1) 
		{
			m_iEnemyIntentPower = 13;
			m_pEnemyIntent->m_pTexture = m_pEnemyIntent->m_pEnemyIntentTextureList[5];
			m_pEnemyIntent->SetMask(m_pEnemyIntent->m_pEnemyIntentTextureList[5]);
		}
		else
		{
			m_iEnemyIntentPower = 5;
			m_pEnemyIntent->m_pTexture = m_pEnemyIntent->m_pEnemyIntentTextureList[7];
			m_pEnemyIntent->SetMask(m_pEnemyIntent->m_pEnemyIntentTextureList[7]);
		}
	}
	else 
	{
		EnemyTurn(m_iTurn);
		m_bTurnStart = true;
		m_iCurrentMana = m_iMaxMana;
	}

	if (m_iEnemyCurrentHP < 0) 
	{ 
		m_iSceneState = 1; 
		m_iEnemyCurrentHP = m_iEnemyMaxHP;
		m_iCurrentMana = m_iMaxMana;
	} 
}

void K_BattleScene::CardUsed(int card_num)
{
	switch (card_num) 
	{
	case Strike:
		m_iEnemyCurrentHP -= 6;
		break;

	case Defend:
		m_iPlayerShield += 5;
		break;

	case PommelStrike:
		break;

	case Bludgeon:
		m_iEnemyCurrentHP -= 32;
		break;
	}

	// 플레이어 캐릭터 공격모션이 들어간다면 여기쯤?
}

void K_BattleScene::EnemyTurn(int turn)
{
	m_iTurn++;

	switch (turn % 3)
	{
	case 0:
		m_iEnemyCurrentHP += 5;
		if (m_iEnemyCurrentHP > m_iEnemyMaxHP) m_iEnemyCurrentHP = m_iEnemyMaxHP;
		break;

	case 1:
		m_iPlayerShield -= 7;
		if (m_iPlayerShield < 0)
		{
			m_iPlayerCurrentHP += m_iPlayerShield;
			m_iPlayerShield = 0;
		}
		break;

	case 2:
		m_iPlayerShield -= 13;
		if (m_iPlayerShield < 0)
		{
			m_iPlayerCurrentHP += m_iPlayerShield;
			m_iPlayerShield = 0;
		}
		break;
	}

	for (auto obj : m_pCardList)
	{
		obj->m_bUsed = false;
		obj->m_bAvailable = true;
	}

	// 적 공격 모션이 들어간다면 여기쯤?
	m_iPlayerShield = 0;
}

void K_BattleScene::CardSetting()
{
	for (int i = 0; i < m_pDeck->m_HandList.size(); i++)
	{
		m_pCardList[i]->m_iCardNum = m_pDeck->m_HandList[i]; 
		m_pCardList[i]->m_pTexture = m_pCardTextureList[m_pCardList[i]->m_iCardNum];
		if (m_pCardList[i]->m_iCardNum == 5) { m_pCardList[i]->m_iCardMana = 3; }
	}
}


