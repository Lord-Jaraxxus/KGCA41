#pragma once
#pragma comment(lib, "KymGameCore_d.lib")

#include "K_Scene.h"
#include "K_TitleScene.h"
#include "K_MapScene.h"
#include "K_BattleScene.h"

#include "K_Deck.h"

class Sample : public K_GameCore
{
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	K_Scene*		m_pCurrentScene;
	K_TitleScene*	m_pTitleScene;
	K_MapScene*		m_pMapScene;
	K_BattleScene*	m_pBattleScene;
	K_Scene*		m_pTestScene;
	K_Deck*			m_pDeck;

public:
	int				m_iPlayerMaxHP;
	int				m_iPlayerCurrentHP;
}; 

