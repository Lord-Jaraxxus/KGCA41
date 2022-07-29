#include <iostream>
#include "Node.h"

int g_iData[10] = { 50,22,66,35,43,59,42,78,99,14 };
int g_iCount = 0;
int g_iFlag = 0;

Node* NewNode()
{
    Node* new_node = new Node;
    return new_node;
}

Node* Build_BST(Node* pParent)
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
                pParent->m_pChild[0] = Build_BST(pParent->m_pChild[0]);
            }
            else
            {
                pParent->m_pChild[1] = Build_BST(pParent->m_pChild[1]);
            }
        }
        return pParent;
}

Node* Search_BST(Node* pParent, int iValue)
{
    if (pParent == nullptr)
    {
        std::cout << "찾는 숫자가 없음";
        return nullptr;                               
    }


    if (pParent->m_iData == iValue)  return pParent;                                                
    else if (iValue < pParent->m_iData)
    {
        Search_BST(pParent->m_pChild[0], iValue);
    }
    else
    {
        Search_BST(pParent->m_pChild[1], iValue);
    }
}

void DeleteNode_BST(Node* TargetNode) 
{
    if (g_iFlag == 1) 
    {
    
    }

    if (TargetNode->m_pChild[0] != nullptr) 
    {
        DeleteNode_BST(TargetNode->m_pChild[0]);
    }
    else if (TargetNode->m_pChild[1] != nullptr)
    {
        DeleteNode_BST(TargetNode->m_pChild[1]);
    }
}

int main()
{
    Node* root = nullptr;
    
    while (g_iCount < 10) { root = Build_BST(root); }
    
    Node* find = Search_BST(root, 88);

    std::cout << "Hello, World!";
}
