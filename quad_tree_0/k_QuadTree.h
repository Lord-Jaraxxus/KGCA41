#include <iostream>
#include <vector>

struct Rect
{
    float x1; // 작은 x좌표
    float y1; // 작은 y좌표
    float w; // width
    float h; // heigt
};

struct k_Rect : Rect
{
    float x2; // 큰 x좌표
    float y2; // 큰 y좌표
    float cx; // 중심 x좌표
    float cy; // 중심 y좌표

    bool   operator == (k_Rect& dest) // 연산자 재정의, 허용오차까지는 ㅇㅋ하는 비교
    {
        if (fabs(x1 - dest.x1) < 0.001f)
        {
            if (fabs(y1 - dest.y1) < 0.001f)
            {
                if (fabs(w - dest.w) < 0.001f)
                {
                    if (fabs(h - dest.h) < 0.001f)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    k_Rect() {} // 디폴트 생성자

    k_Rect(float x, float y, float w, float h)
    {
        Set(x, y, w, h);
    }

    void  Set(float x, float y, float w, float h)
    {
        this->x1 = x;
        this->y1 = y;
        this->w = w;
        this->h = h;
        this->x2 = x + w;
        this->y2 = y + h;
        this->cx = x + w / 2.0f;
        this->cy = y + h / 2.0f;
    }
};

struct k_Circle 
{
    float cx = 0;
    float cy = 0;
    float fRadius = 0;
    
    void Set(float x, float y, float r) 
    {
        cx = x;
        cy = y;
        fRadius = r;
    }

    k_Circle() {};
    k_Circle(float x, float y, float r) 
    {
        cx = x;
        cy = y;
        fRadius = r;
    }
};

class k_Object
{
public:
    k_Rect m_sRect;
    k_Circle m_sCir;

    void   SetPosition(float x, float y, float w, float h)
    {
        m_sRect.Set(x, y, w, h);

        float hw = w / 2.0f;
        float hh = h / 2.0f;
        float r1 = sqrt(hw * hw + hh * hh);
        m_sCir.Set(x+ hw, y+ hh, r1);
    }

    k_Object()
    {
        SetPosition
        (
            (rand() % 90),
            (rand() % 90),
            5.0f + (rand() % 5),
            5.0f + (rand() % 5)
        );
    }
};

class k_Node
{
public:
    k_Rect m_sRect;
    int m_iDepth;
    std::vector<k_Object*> m_vObjectList;
    k_Node* m_pChild[4];
    k_Node* m_pParent;

public:
    k_Node() {}
    k_Node(k_Node* pParent, float x, float y, float w, float h)
    {
        m_sRect.Set(x, y, w, h);
        m_iDepth = 0;
        m_pParent = nullptr;
        if (pParent != nullptr)
        {
            m_pParent = pParent;
            m_iDepth = pParent->m_iDepth + 1;
        }
    }
    ~k_Node()
    {
        delete m_pChild[0];
        delete m_pChild[1];
        delete m_pChild[2];
        delete m_pChild[3];
    }
};

class k_QuadTree
{
public:
    k_Node* m_pRootNode;

public:
    void BuildQuadTree(k_Node* root, float width, float height);

    k_QuadTree(float width, float height) 
    {
        this->m_pRootNode = new k_Node(nullptr, 0.0f, 0.0f, width, height);
        BuildQuadTree(this->m_pRootNode, width, height);
    };
    k_QuadTree() {}; // 디폴트 생성자
    ~k_QuadTree()
    {
        delete m_pRootNode;
    }
};
