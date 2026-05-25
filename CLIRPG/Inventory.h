#pragma once

#include "pch.h"

class CItem;

class CInventory
{
public:
	CInventory();
	virtual ~CInventory();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void AddItem(CItem* Item);
	void Render();

private:
	CItem* Items;

	eItemType m_CurrentTab;

	int iGold;
};

