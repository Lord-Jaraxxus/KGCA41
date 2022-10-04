#pragma once
#include "K_Scene.h"
#include "K_Deck.h"

class K_BattleScene : public K_Scene
{
public:
	virtual bool Init() override;
	virtual bool Frame() override;
	virtual bool Render() override;
	virtual bool Release() override;

public:
	K_BackGround*			m_pBackGround;
	K_Character*			m_pPlayer;
	K_Character*			m_pEnemy;
	K_Button*				m_pTurnEndButton;
	K_EnemyIntent*			m_pEnemyIntent;
	int						m_iEnemyIntentPower;
	int						m_iMaxMana = 3;
	int						m_iCurrentMana = 3;
	
	std::vector<K_Card*>	m_pCardList;
	std::vector<K_Texture*>	m_pCardTextureList;

public:
	int				m_iPlayerMaxHP;
	int				m_iPlayerCurrentHP;
	int				m_iPlayerShield = 0;
	int				m_iEnemyMaxHP;
	int				m_iEnemyCurrentHP;

public:
	void			SetDeck(K_Deck* deck);
	void			SetPlayerHP(int currentHP, int maxHP);

public:
	void			Combat(int turn);
	void			CardUsed(int card_num);
	void			EnemyTurn(int turn);
	void			CardSetting();

public:
	K_Deck*			m_pDeck;
	int				m_iTurn = 0;
	bool			m_bTurnStart = true;
};

