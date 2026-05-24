#pragma once

#include "pch.h"

class CCharacter;

class CSaveGame
{
public:
	CSaveGame();
	~CSaveGame();

	void Save(CCharacter* pPlayer);
	void Load(CCharacter*& pPlayer);
};

