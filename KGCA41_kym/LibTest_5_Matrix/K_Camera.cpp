#include "K_Camera.h"
#include "K_Input.h"

void K_Camera::CreateViewMatrix(k_Vector vEye, k_Vector vAt, k_Vector vUp)
{
	m_vCameraPos = vEye;
	m_vTarget = vAt;
	m_vUp = vUp;
	m_matView.ViewLookAt(vEye, vAt, vUp);
}

void K_Camera::CreateProjMatrix(float fNear, float fFar, float fFovY, float fAspectRatio)
{
	m_fNear = fNear;
	m_fFar = fFar;
	m_fFovY = fFovY;
	m_fAspectRatio = fAspectRatio;
	m_matProj.PerspectiveFovLH(m_fNear, m_fFar, m_fFovY, m_fAspectRatio);
	//m_matProj = m_matProj.OrthoLH(800, 600, 0.0f, 100.0f);
	//OrthoOffCenterLH(m_matProj ,-400, 400, -300, 300, 0.0f, 100.0f);
}

bool K_Camera::Frame()
{
	if (I_Input.GetKey('W') == KEY_HOLD)
	{
		m_vCameraPos.z += 10.0f * g_fSecondPerFrame;
	}
	if (I_Input.GetKey('S') == KEY_HOLD)
	{
		m_vCameraPos.z -= 10.0f * g_fSecondPerFrame;
	}
	if (I_Input.GetKey('A') == KEY_HOLD)
	{
		m_vCameraPos.x -= 10.0f * g_fSecondPerFrame;
	}
	if (I_Input.GetKey('D') == KEY_HOLD)
	{
		m_vCameraPos.x += 10.0f * g_fSecondPerFrame;
	}
	if (I_Input.GetKey('Q') == KEY_HOLD)
	{
		m_vCameraPos.y += 10.0f * g_fSecondPerFrame;
	}
	if (I_Input.GetKey('E') == KEY_HOLD)
	{
		m_vCameraPos.y -= 10.0f * g_fSecondPerFrame;
	}

	k_Vector vUp = { 0,1,0 };
	//TMatrix mCamera = TMath::RotationY(g_fGameTimer);
	//vPos = (vPos + vPosMovement) * mCamera;
	m_matView.ViewLookAt(m_vCameraPos, m_vTarget, m_vUp);
	return true;
}
