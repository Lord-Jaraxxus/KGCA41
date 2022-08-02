#include <iostream>
#include "Node.h"

int g_iData[10] = { 50,22,66,35,43,59,42,78,63,14 };
int g_iCount = 0;
int g_iFlag = 0;

Node* g_pRoot = nullptr;


Node* NewNode()
{
    Node* new_node = new Node;
    return new_node;
}

Node* AddNode_BST(Node* pParent)
{
    if (pParent == nullptr)
    {
        pParent = NewNode();
        pParent->m_iData = g_iData[g_iCount];
        pParent->m_iIndex = g_iCount;
        g_iCount++;
    }

    else if (g_iCount < 10)
    {
        if (g_iData[g_iCount] < pParent->m_iData)
        {
            pParent->m_pChild[0] = AddNode_BST(pParent->m_pChild[0]);
            pParent->m_pChild[0]->m_pParent = pParent;
        }
        else
        {
            pParent->m_pChild[1] = AddNode_BST(pParent->m_pChild[1]);
            pParent->m_pChild[1]->m_pParent = pParent;
        }
    }
    return pParent;
}

int GetColor(Node* node) 
{
    if (node == nullptr) return BLACK;
    else return node->m_iColor;
}

void LeftRotate(Node* node) 
{
}

void RightRotate(Node* node) 
{
    Node* pPr = node->m_pParent; 
    Node* pGpr = pPr->m_pParent;

    //앞으로 연결이 끊길 노드들을 미리 세이브해둠
    Node* pPrLc = pPr->m_pChild[0]; // pPr의 원래 왼쪽 자식 (p Parent Left chid)
    Node* pGGpr = pGpr->m_pParent; // 조부모의 부모, 즉 증조부 (p Grand-Grand parent)

    pPr->m_pChild[0] = pGpr; // 부모의 왼쪽 자식을 조부모로 변경
    pGpr->m_pParent = pPr; // 조부모의 부모를 왼쪽 자식으로 변경, 사실상 위랑 세트

    pPr->m_pParent = pGGpr; 
    if (pGpr == pGGpr->m_pChild[0]) pGGpr->m_pChild[0] = pPr;
    else if (pGpr == pGGpr->m_pChild[1]) pGGpr->m_pChild[1] = pPr;

    pPrLc

}

void FixRBT(Node* ptr) 
{
    Node* pParent = nullptr;
    Node* pGrandParent = nullptr;
    Node* pUncle = nullptr;

    while (ptr != g_pRoot && GetColor(ptr) == RED && GetColor(ptr->m_pParent) == RED)
    {
        pParent = ptr->m_pParent;
        pGrandParent = pParent->m_pParent;

        if (pParent == pGrandParent->m_pChild[0]) // 부모가 조부모의 왼쪽 자식일 때 
        {
            pUncle = pGrandParent->m_pChild[1]; // 삼촌은 조부모의 오른쪽 자식, 삼촌이 없을수도 있음
            if (GetColor(pUncle) == RED) 
            {
                pParent->m_iColor = BLACK;
                pUncle->m_iColor = BLACK;
                pGrandParent->m_iColor = RED;
                ptr = pGrandParent;
            }
            else if (GetColor(pUncle) == BLACK) 
            {
                if (ptr == pParent->m_pChild[0]) 
                {
                    RightRotate(ptr); // 음..
                    ptr = pGrandParent; // 
                }
                else if (ptr == pParent->m_pChild[1]) 
                {
                    LeftRotate(ptr); 
                    RightRotate(ptr);
                    ptr = pGrandParent;
                }
            }
        }
        else if (pParent == pGrandParent->m_pChild[1]) // 부모가 조부모의 오른쪽 자식일 때, else 써도 되는데 보기 편하라고
        {
        }
    }
    g_pRoot->m_iColor = BLACK;
}



int main()
{
    Node* root = nullptr;

    while (g_iCount < 10) { root = AddNode_BST(root); }

    std::cout << "Hello, World!";

}
