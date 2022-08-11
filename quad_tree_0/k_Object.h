#include <vector> // fabs
#include "k_Vector.h"

struct Rect
{
    float x1; // ���� x��ǥ
    float y1; // ���� y��ǥ
    float w; // width
    float h; // heigt
};

struct k_Rect : Rect
{
    float x2; // ū x��ǥ
    float y2; // ū y��ǥ
    float cx; // �߽� x��ǥ
    float cy; // �߽� y��ǥ

    bool   operator == (k_Rect& dest) // ������ ������, ������������ �����ϴ� ��
    {
        if (fabs(x1 - dest.x1) < k_Epsilon)
        {
            if (fabs(y1 - dest.y1) < k_Epsilon)
            {
                if (fabs(w - dest.w) < k_Epsilon)
                {
                    if (fabs(h - dest.h) < k_Epsilon)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    k_Rect() {} // ����Ʈ ������

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
    k_Vector2D m_vDirection;

    void   SetPosition(float x, float y, float w, float h)
    {
        m_sRect.Set(x, y, w, h);

        float hw = w / 2.0f;
        float hh = h / 2.0f;
        float r1 = sqrt(hw * hw + hh * hh);
        m_sCir.Set(x + hw, y + hh, r1);
    }

    void SetDirection(float x, float y) 
    {
        m_vDirection.x = x;
        m_vDirection.y = y;
    }

    void Move() 
    {
        k_Vector2D vStart(m_sRect.x1, m_sRect.y1); // ���ۺ���
        // ������ ������ ������
        // ������� = ���ۺ��� + ���⺤��* t(�Ÿ� ������ �ð�)

        k_Vector2D vDirection = m_vDirection; // *1.0f; - ��� t�ε� ������ �� ���̰��Ƽ�
        vStart = vStart + vDirection;
        m_sRect.x1 = vStart.x;
        m_sRect.y1 = vStart.y;

        if (vStart.x + m_sRect.w > 100.0f)
        {
            m_sRect.x1 = 200.0f - (vStart.x + 2*m_sRect.w);
            m_vDirection.x *= -1.0f;
        }
        if (vStart.x < 0.0f)
        {
            m_sRect.x1 = -(vStart.x);
            m_vDirection.x *= -1.0f;
        }
        if (vStart.y + m_sRect.h > 100.0f)
        {
            m_sRect.y1 = 200.0f - (vStart.y + 2*m_sRect.h);
            m_vDirection.y *= -1.0f;
        }
        if (vStart.y < 0.0f)
        {
            m_sRect.y1 = -(vStart.y);
            m_vDirection.y *= -1.0f;
        }

        SetPosition(m_sRect.x1, m_sRect.y1, m_sRect.w, m_sRect.h);

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
        SetDirection(1.0f + rand()%9, 1.0f + rand() % 9);
    }
};
