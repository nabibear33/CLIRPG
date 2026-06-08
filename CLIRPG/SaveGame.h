#pragma once

#include "pch.h"

class CPlayer;

class CSaveGame
{
public:
	CSaveGame();
	~CSaveGame();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Save(CPlayer* pPlayer);
	tagSaveData GetSaveData(CPlayer* pPlayer);
	void Load(CPlayer*& pPlayer);
	void LoadSaveData(tagSaveData& tSaveData, CPlayer*& pPlayer);
};

