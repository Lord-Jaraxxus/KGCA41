#include "K_SoundManager.h"

bool K_SoundManager::Init()
{
    FMOD::System_Create(&m_pSystem);
    m_pSystem->init(32, FMOD_INIT_NORMAL, 0);

    return true;
}

bool K_SoundManager::Frame()
{

    m_pSystem->update();
    for (auto data : m_List)
    {
        K_Sound* pData = data.second;
        if (pData) pData->Frame();
    }
    return true;
}

bool K_SoundManager::Render()
{
    return true;
}

bool K_SoundManager::Release()
{
    for (auto data : m_List)
    {
        K_Sound* pData = data.second;
        if (pData) pData->Release();
        delete pData;
    }
    m_List.clear();
    return true;
}

K_SoundManager::K_SoundManager()
{
}

K_SoundManager::~K_SoundManager()
{
}


K_Sound* K_SoundManager::Load(std::wstring name)
{
    bool hr;

    //중복 제거
    auto iter = m_List.find(name);
    if (iter != m_List.end()) return iter->second;

    K_Sound* pNewData = new K_Sound;
    if (pNewData)
    {
        hr = pNewData->Load (m_pSystem, name);
        if (hr) m_List.insert(std::make_pair(name, pNewData));
    }
    return pNewData;
}