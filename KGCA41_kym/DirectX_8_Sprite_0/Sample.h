#pragma once
#include "K_GameCore.h"

// 얘들 왜 타이머 클래스 헤더에 넣으면 야랄남? 윈도우 헤더에 넣었을때도 잘 돌아가는데 
// 정답! 선생님은 타이머 클래스 헤더가 아니라 타이머 클래스 cpp에 넣으셨음! 난 빡대가리!
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

