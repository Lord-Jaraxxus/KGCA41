#include <iostream> // cout, etc
#include <windows.h> //min, max, etc
#include <conio.h> // getch
#include <map> // map
#include "k_Collision.h"

int main()
{
    k_Collision kc;
    kc.QT = new k_QuadTree(100.0f, 100.0f);

    k_Object player;
    player.SetPosition(0, 0, 30, 30);
    player.SetDirection(6, 6);


    std::map<int, k_Object*> DynamicObjectList;
    std::map<int, k_Object*> AllobjectList;
    for (int iObj = 0; iObj < 20; iObj++)
    {
        k_Object* pObj = new k_Object;
        pObj->SetDirection(0.0f, 0.0f);
        AllobjectList.insert(std::make_pair(iObj, pObj));
        kc.AddStaticObject(pObj);
    }
    for (int iObj = 0; iObj < 20; iObj++)
    {
        k_Object* pObj = new k_Object;
        AllobjectList.insert(std::make_pair(iObj + 20, pObj));
        DynamicObjectList.insert(std::make_pair(iObj, pObj));
        kc.AddDynamicObject(pObj);
    }

    std::vector<k_Object*> list = kc.COL(&player);

    while (1)
    {
        kc.DynamicObjectReset(kc.QT->m_pRootNode);
        for (auto obj : DynamicObjectList)
        {
            k_Object* pObject = obj.second;
            pObject->Move();
            kc.AddDynamicObject(pObject);
        }

        std::vector<k_Object*> list = kc.COL(&player);
        std::cout << "player:"
            << player.m_sRect.x1 << "," << player.m_sRect.y1 << ","
            << player.m_sRect.x2 << "," << player.m_sRect.y2
            << std::endl;
        if (!list.empty())
        {
            for (int iObj = 0; iObj < list.size(); iObj++)
            {
                std::cout << "object:"
                    << list[iObj]->m_sRect.x1 << "," << list[iObj]->m_sRect.y1 << ","
                    << list[iObj]->m_sRect.x2 << "," << list[iObj]->m_sRect.y2
                    << std::endl;
            }
        }
        

        player.Move();
        Sleep(10);
        //_getch();
        system("cls");
    }
}


