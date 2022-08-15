#include "k_Player.h"

void   k_Player::Frame(float fDeltaTime, float fGameTime)
{
    {
        k_Vector2D vStart(m_sRect.x1, m_sRect.y1); // ���ۺ���
        // ������ ������ ������
        // ������� = ���ۺ��� + ���⺤��* t(�Ÿ� ������ �ð�)

        m_vAcceleration = m_vForces / m_fMass; // 1�� ���� ���ӵ�
        //k_Vector2D vAccPerTime = m_vAcceleration * fDeltaTime; // ���� ������ �ð���ŭ ������ ���� ���ӵ� 
        //k_Vector2D vVelocityPerTime = m_vVelocity * fDeltaTime;
        // ���� �ϴ� �ð� 1�ʷ� ������.... �ð��� ������ �δ°� ���� ����� �� �����ϱ� ����
        m_vVelocity += m_vAcceleration;

        vStart += m_vVelocity;
        

        m_sRect.x1 = vStart.x;
        m_sRect.y1 = vStart.y;

        if (vStart.x + m_sRect.w > 100.0f)
        {
            m_sRect.x1 = 200.0f - (vStart.x + 2 * m_sRect.w);
            m_vForces.x *= -1.0f;
            m_vVelocity.x *= -1.0f;
        }
        if (vStart.x < 0.0f)
        {
            m_sRect.x1 = -(vStart.x);
            m_vForces.x *= -1.0f;
            m_vVelocity.x *= -1.0f;
        }
        if (vStart.y + m_sRect.h > 100.0f)
        {
            m_sRect.y1 = 200.0f - (vStart.y + 2 * m_sRect.h);
            m_vForces.y *= -1.0f;
            m_vVelocity.y *= -1.0f;
        }
        if (vStart.y < 0.0f)
        {
            m_sRect.y1 = -(vStart.y);
            m_vForces.y *= -1.0f;
            m_vVelocity.y *= -1.0f;
        } //��� �̰� �����غ����� �ߴµ�.. �ϴ� �־��

        SetPosition(m_sRect.x1, m_sRect.y1, m_sRect.w, m_sRect.h);

    }
}