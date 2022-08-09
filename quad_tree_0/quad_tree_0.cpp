#include <iostream> // cout, etc
#include <windows.h> //min, max, etc
#include "k_Collision.h"
#include <conio.h> // getch

int main()
{
    //k_QuadTree* qt = new k_QuadTree(100.0f, 100.0f);
    //k_QuadTree qt(100.0f, 100.0f);
    k_Collision kc;
    kc.QT = new k_QuadTree(100.0f, 100.0f);

    //k_Object* pObj = new k_Object;
    //kc.AddObject(pObj);

    k_Object player;
    player.SetPosition(0, 0, 30, 30);

    k_Object* rock = new k_Object;
    rock->SetPosition(31, 31, 30, 30);
    kc.AddObject(rock);

    bool circol = kc.CircleToCircle(player.m_sCir, rock->m_sCir);

    //for (int iObj = 0; iObj < 100; iObj++)
    //{
    //    k_Object* pObj = new k_Object;
    //    kc.AddObject(pObj);
    //}

    //std::vector<k_Object*> list = kc.COL(&player);

    //while (1)
    //{
    //    std::vector<k_Object*> list = kc.COL(&player);
    //    std::cout << "player:"
    //        << player.m_sRect.x1 << "," << player.m_sRect.y1 << ","
    //        << player.m_sRect.x2 << "," << player.m_sRect.y2
    //        << std::endl;
    //    if (!list.empty())
    //    {
    //        for (int iObj = 0; iObj < list.size(); iObj++)
    //        {
    //            std::cout << "object:"
    //                << list[iObj]->m_sRect.x1 << "," << list[iObj]->m_sRect.y1 << ","
    //                << list[iObj]->m_sRect.x2 << "," << list[iObj]->m_sRect.y2
    //                << std::endl;
    //        }
    //    }
    //    static float fDirectionX = 10.0f;
    //    if (rand() % 2 == 0)
    //    {
    //        fDirectionX *= -1.0f;
    //    }
    //    static float fDirectionY = 10.0f;
    //    if (rand() % 2 == 0)
    //    {
    //        fDirectionY *= -1.0f;
    //    }
    //    player.m_sRect.x1 = player.m_sRect.x1 + fDirectionX;
    //    player.m_sRect.y1 = player.m_sRect.y1 + fDirectionY;

    //    player.m_sRect.x1 = min(player.m_sRect.x1, 100.0f);
    //    player.m_sRect.x1 = max(player.m_sRect.x1, 0);
    //    player.m_sRect.y1 = min(player.m_sRect.y1, 100.0f);
    //    player.m_sRect.y1 = max(player.m_sRect.y1, 0);

    //    player.SetPosition(player.m_sRect.x1,
    //        player.m_sRect.y1, 30, 30);
    //    //Sleep(10);
    //    _getch();
    //    system("cls");
    //}
}


