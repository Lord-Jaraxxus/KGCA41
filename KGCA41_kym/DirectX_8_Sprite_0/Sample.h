#pragma once
#include "K_GameCore.h"

// ��� �� Ÿ�̸� Ŭ���� ����� ������ �߶���? ������ ����� �־������� �� ���ư��µ� 
// ����! �������� Ÿ�̸� Ŭ���� ����� �ƴ϶� Ÿ�̸� Ŭ���� cpp�� ��������! �� ���밡��!
//float g_fGameTimer = 0.0f;
//float g_fSecondPerFrame = 0.0f;

class K_2dObject : public K_BaseObject 
{
public:
	POINT		m_ptImageSize;
	k_Vector4D	m_rtUV;
	k_Vector4D	m_rtInit;
	k_Vector2D	m_vPos;
	k_Vector2D	m_vSize;
private:
	k_Vector2D	m_vDrawPos;
	k_Vector2D	m_vDrawSize;

public:
	void	SetPosition(k_Vector2D pos);
	void	SetRect(k_Vector4D rt);	
	void	UpdateVertexBuffer();
	bool	Frame() override;
};

class Sample : public K_GameCore
{
public:
	K_2dObject* m_pUser;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
}; 

