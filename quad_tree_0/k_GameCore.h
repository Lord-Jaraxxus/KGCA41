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
    std::map<int, k_Object*> npcList;
    std::map<int, k_Object*> AllObjectList;
    std::vector<k_Object*>   DrawList;
public:
    bool    Init();     // �ʱ�ȭ	
    bool    Frame(float fDeltaTime, float fGameTime);    // �ǽð� ���
    bool    Render();   // ȭ�鿡 ��ο�
    bool    Release();  // �Ҹ�����
    bool	Run();      // ��������
};

