#pragma once
#pragma comment(lib, "KymGameCore_d.lib")

#include "K_GameCore.h"
#include "K_2dObject.h"
#include "K_Shape.h"
#include "K_Map.h"
#include "K_Camera.h"

class Sample : public K_GameCore
{
public:
	K_BaseObject*	m_pBG = nullptr;
	K_Map*			m_pMap = nullptr;
	K_ShapeBox*		m_pBoxObjA = nullptr;
	K_ShapeBox*		m_pBoxObjB = nullptr;
	K_Camera*		m_pMainCamera = nullptr;

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
}; 

