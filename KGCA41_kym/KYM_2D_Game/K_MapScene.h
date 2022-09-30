#pragma once
#include "K_Scene.h"

class K_MapScene : public K_Scene
{
public:
	virtual bool Init() override;
	virtual bool Frame() override;
	virtual bool Render() override;
	virtual bool Release() override;

public:
	std::vector<K_2dObject*> m_pBackGroundList;
	std::vector<K_MapObject*> m_pMapObjectList;
	k_Vector2D	m_vCameraPos;
	k_Vector2D  m_vMousePos;
	bool		m_bLButtonState = false;
	int			m_iStage = 0;
};

