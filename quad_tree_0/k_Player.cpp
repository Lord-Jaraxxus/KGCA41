#include "k_Player.h"

void   k_Player::Frame(float fDeltaTime, float fGameTime)
{
    {
        k_Vector2D vStart(m_sRect.x1, m_sRect.y1); // 시작벡터
        // 벡터의 직전의 방정식
        // 결과벡터 = 시작벡터 + 방향벡터* t(거리 내지는 시간)

        m_vAcceleration = m_vForces / m_fMass; // 1초 기준 가속도
        //k_Vector2D vAccPerTime = m_vAcceleration * fDeltaTime; // 실제 프레임 시간만큼 지났을 때의 가속도 
        //k_Vector2D vVelocityPerTime = m_vVelocity * fDeltaTime;
        // ㅅㅂ 일단 시간 1초로 고정해.... 시간을 변수로 두는건 존나 어려운 것 같으니까 지금
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
        } //사실 이걸 생각해보려고 했는데.. 일단 있어봐

        SetPosition(m_sRect.x1, m_sRect.y1, m_sRect.w, m_sRect.h);

    }
}