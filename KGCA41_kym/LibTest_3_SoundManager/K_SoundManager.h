#pragma once
#include "K_Sound.h"

class K_SoundManager : public K_Singleton<K_SoundManager>
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

private:
	FMOD::System* m_pSystem = nullptr;

private:
	friend class K_Singleton<K_SoundManager>;
	std::map<std::wstring, K_Sound*> m_List;

private:
	K_SoundManager();
	~K_SoundManager();

public:
	K_Sound* Load(std::wstring name);


};

#define I_Sound K_SoundManager::GetInstance()