#pragma once
#include <map> // map
#include <windows.h> //sleep, min, max, etc
#include "k_Collision.h"
#include "k_Player2D.h"
#include "k_MapObject2D.h"
#include "k_NPC2D.h"


class k_GameCore
{
public:
    k_Player2D    player;
    k_Collision   kc;
    std::map<int, k_Object2D*> npcList;
    std::map<int, k_Object2D*> AllObjectList;
    std::vector<k_Object2D*>   DrawList;
public:
    bool    Init();     // 초기화	
    bool    Frame(float fDeltaTime, float fGameTime);    // 실시간 계산
    bool    Render();   // 화면에 드로우
    bool    Release();  // 소멸하자
    bool	Run();      // 실행하자
};

