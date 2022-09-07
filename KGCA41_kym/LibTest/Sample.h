#pragma once
#include "K_Device.h"

class Sample : public K_Device
{
public:
	virtual bool Init() override;
	virtual bool Frame() override;
	virtual bool Render() override;
	virtual bool Release() override;
	virtual bool Run() override;
};

