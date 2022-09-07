#pragma once
#include "K_Device.h"
#include "K_Timer.h"
#include "K_Input.h"

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
	 bool K_GameCoreRender();
	 bool K_GameCoreRelease();

public:
	bool m_bGameRun = true;

};

