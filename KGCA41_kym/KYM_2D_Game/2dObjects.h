#pragma once
#include "K_2dObject.h"

class K_BackGround : public K_2dObject
{
public:
	virtual bool	Frame() override;
	virtual void	SetPosition(k_Vector2D pos) override;
};

class K_Npc : public K_2dObject
{
public:
	virtual bool	Frame() override;
	virtual void	SetPosition(k_Vector2D pos) override;
	int				m_iMouseFlag = 0;
	int				m_iDragFlag = 0;
	float			m_fZoom = 1.0f;
	k_Vector2D		m_vMousePos;
};

class K_Player : public K_2dObject
{
	virtual bool	Frame() override;
};

class K_Button : public K_2dObject
{
public:
	virtual bool	Frame() override;
	virtual void	SetPosition(k_Vector2D pos) override;

public:
	int				m_iMouseFlag = 0;
	bool			m_bButtonPushed = false;
	float			m_fZoom = 1.2f;
};

class K_Map : public K_2dObject 
{
};

class K_MapObject : public K_2dObject 
{
public:
	virtual bool	Frame() override;
	virtual void	UpdateVertexBuffer() override;
	virtual void	SetPosition(k_Vector2D pos) override;

public:
	int				m_iMouseFlag = 0;
	bool			m_bButtonPushed = false;
	float			m_fZoom = 1.0f;
	float			m_fColor = 0.4f;
	int				m_iStage = 0;
};

class K_Card : public K_2dObject 
{
public:
	virtual bool	Frame() override;
	virtual void	SetPosition(k_Vector2D pos) override;

public:
	k_Vector2D		m_vMousePos;
	int				m_iMouseFlag = 0;
	int				m_iDragFlag = 0;
	float			m_fZoom = 1.0f;
	bool			m_bUsed = false;
};

