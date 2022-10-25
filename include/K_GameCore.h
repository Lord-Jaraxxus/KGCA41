#pragma once
#include "K_Device.h"
#include "K_Timer.h"
#include "K_Input.h"
#include "K_Write.h"
#include "K_BaseObject.h"
#include "K_DxState.h"
#include "K_RenderTarget.h"

class K_GameCore : public K_Device
{
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

	bool Run();

private:
	 bool K_GameCoreInit();
	 bool K_GameCoreFrame();
	 bool K_GameCorePreRender();
	 bool K_GameCoreRender();
	 bool K_GameCorePostRender();
	 bool K_GameCoreRelease();

public:
	virtual HRESULT CreateDXResource();
	virtual HRESULT DeleteDXResource();

public:
	bool m_bGameRun = true;

public:
	K_BaseObject	m_BG;
	K_RenderTarget	m_RT;
};

