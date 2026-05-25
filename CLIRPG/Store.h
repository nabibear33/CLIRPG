#pragma once

#include "pch.h"

class CItem;
class CPlayer;

class CStore
{
public:
	CStore();
	virtual ~CStore();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	bool IsValidItemChoice(int iChoice);

	void PrintItems();

private:
	vector<CItem*> m_Items;
};

