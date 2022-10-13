#pragma once
#pragma comment(lib, "KymGameCore_d.lib")

#include "K_GameCore.h"
#include "K_2dObject.h"
#include "K_SoundManager.h"

class K_Map : public K_2dObject
{
public:
	virtual bool	Frame() override;
	virtual void	SetPosition(k_Vector2D pos) override;
	int				m_iStage = 0;
};

class K_Npc : public K_2dObject
{
	virtual bool	Frame() override;
};

class K_Player : public K_2dObject
{
public:
	virtual bool	Frame() override;
	virtual void	UpdateVertexBuffer() override;
};

class Sample : public K_GameCore
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	std::vector<K_BaseObject*> m_pObjectList;
	std::vector<K_BaseObject*> m_pNPCList;
	K_Map*			m_pMap;
	K_Player*		m_pUser;

public:
	K_Sound*	m_pBGM;
	K_Sound*	m_pEffect1;
	K_Sound*	m_pEffect2;
}; 

