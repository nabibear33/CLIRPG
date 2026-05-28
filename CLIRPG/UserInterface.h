#pragma once

#include "pch.h"

class CUserInterface
{
public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void Render(int iU, int iV) = 0;

private:
	
};

