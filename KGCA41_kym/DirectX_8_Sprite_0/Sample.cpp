#include "Sample.h"

void K_2dObject::SetRect(k_Vector4D rt)
{
	m_rtInit = rt;
	m_ptImageSize.x = m_pTexture->m_Desc.Width;
	m_ptImageSize.y = m_pTexture->m_Desc.Height;

	k_Vector4D Rect;
	Rect.x = rt.x / m_ptImageSize.x;
	Rect.y = rt.y / m_ptImageSize.y;
	Rect.z = rt.z / m_ptImageSize.x;
	Rect.w = rt.w / m_ptImageSize.y;
	m_rtUV = Rect;
	// 이미지에 대한 w,h 값이 필요하다 즉, 이미지의 크기가 필요하다
}

void K_2dObject::SetPosition(k_Vector2D pos)
{
	m_vPos = pos;

	m_vDrawPos.x = (pos.x / g_rtClient.right)*2.0f - 1.0f;
	m_vDrawPos.y = -((pos.y / g_rtClient.bottom) * 2.0f - 1.0f);
	m_vDrawSize.x = m_rtUV.z * 1.5f;
	m_vDrawSize.y = m_rtUV.w * 1.5f;

	UpdateVertexBuffer();
}

void K_2dObject::UpdateVertexBuffer()
{
	m_VertexList[0].p = { m_vDrawPos.x, m_vDrawPos.y, 0.0f };
	m_VertexList[0].t = { m_rtUV.x, m_rtUV.y };

	m_VertexList[1].p = { m_vDrawPos.x + m_vDrawSize.x, m_vDrawPos.y,  0.0f };
	m_VertexList[1].t = { m_rtUV.x + m_rtUV.z, m_rtUV.y };

	m_VertexList[2].p = { m_vDrawPos.x, m_vDrawPos.y - m_vDrawSize.y, 0.0f };
	m_VertexList[2].t = { m_rtUV.x, m_rtUV.y + m_rtUV.w };

	m_VertexList[3].p = m_VertexList[2].p;
	m_VertexList[3].t = m_VertexList[2].t;

	m_VertexList[4].p = m_VertexList[1].p;
	m_VertexList[4].t = m_VertexList[1].t;

	m_VertexList[5].p = { m_vDrawPos.x + m_vDrawSize.x, m_vDrawPos.y - m_vDrawSize.y, 0.0f };
	m_VertexList[5].t = { m_rtUV.x + m_rtUV.z, m_rtUV.y + m_rtUV.w };
}

bool K_2dObject::Frame()
{
	k_Vector2D vPos = m_vPos;
	if (I_Input.GetKey('W')) vPos.y += -1.0f * g_fSecondPerFrame * 100.0f;
	if (I_Input.GetKey('A')) vPos.x += -1.0f * g_fSecondPerFrame * 100.0f;
	if (I_Input.GetKey('S')) vPos.y += 1.0f * g_fSecondPerFrame * 100.0f;
	if (I_Input.GetKey('D')) vPos.x += 1.0f * g_fSecondPerFrame * 100.0f;
	SetPosition(vPos);

	m_pImmediateContext->UpdateSubresource(m_pVertexBuffer, 0, NULL, &m_VertexList.at(0), 0, 0);
	return true;
}

bool Sample::Init() 
{
	m_pUser = new K_2dObject;
	m_pUser->Create(m_pd3dDevice, m_pImmediateContext, L"../../data/img/crusader.sprite.combat.png", L"DefaultShape.txt");
	m_pObjectList.push_back(m_pUser);

	m_pUser->SetRect({ 0, 51, 113, 337 });
	m_pUser->SetPosition({g_rtClient.right/2.0f, g_rtClient.bottom/2.0f });
	return true; 
}

bool Sample::Frame()
{
	return true;
}

bool Sample::Render()
{
	if (I_Input.GetKey('W') == KEY_PUSH || I_Input.GetKey('W') == KEY_HOLD)
	{
		I_Write.Draw(500, 500, L"W", { 1,1,1,1 });
	}
	if (I_Input.GetKey('A') == KEY_PUSH || I_Input.GetKey('A') == KEY_HOLD)
	{
		I_Write.Draw(400, 600, L"A", { 1,1,1,1 });
	}
	if (I_Input.GetKey('S') == KEY_PUSH || I_Input.GetKey('S') == KEY_HOLD)
	{
		I_Write.Draw(500, 600, L"S", { 1,1,1,1 });
	}
	if (I_Input.GetKey('D') == KEY_PUSH || I_Input.GetKey('D') == KEY_HOLD)
	{
		I_Write.Draw(600, 600, L"D", { 1,1,1,1 });
	}
	return true;
}

bool Sample::Release()
{
	m_pUser->Release();
	delete m_pUser;
	return true; 
}


//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPWSTR    lpCmdLine,
//    _In_ int       nCmdShow) 
//{
//    Sample demo;
//    demo.SetWindow(hInstance);
//    demo.Run();
//    return 1;
//}  

GAME_RUN(CreateObject, 1200, 900)