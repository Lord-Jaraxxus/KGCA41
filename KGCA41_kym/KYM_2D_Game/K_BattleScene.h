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
	K_BackGround*	m_pBackGround;
	K_2dObject*		m_pPlayer;
	K_2dObject*		m_pEnemy;
	std::vector<K_Card*> m_pCardList;
public:
	K_Deck*			m_pDeck;
	int				m_iTurn;
};

