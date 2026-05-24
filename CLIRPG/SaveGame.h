#pragma once

#include "pch.h"

class CCharacter;

class CSaveGame
{
public:
	CSaveGame();
	~CSaveGame();

	// 세이브, 로드
	void Save(CCharacter* pPlayer);
	void Load(CCharacter*& pPlayer);
};

