#pragma once
#pragma comment(lib, "KymGameCore_d.lib")

#include "K_Scene.h"

class Sample : public K_GameCore
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	
public:
	K_Scene*	m_pScene;
}; 

