#pragma once

#include "pch.h"

class CCharacter;

class CSaveGame
{
public:
	CSaveGame();
	~CSaveGame();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Save(CCharacter* pPlayer);
	void Load(CCharacter*& pPlayer);
};

