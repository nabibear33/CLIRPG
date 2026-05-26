#pragma once

#include "pch.h"

class CItem;
class CPlayer;
class CInventory;

class CStore
{
public:
	CStore();
	virtual ~CStore();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	CInventory* GetInventory();
	eStoreTab GetCurrentTab();
	void SetCurrentTab(eStoreTab StoreTab);

	void SellItem(CPlayer* Player, CItem* Item);


private:
	CInventory* m_Inventory;

	eStoreTab m_CurrentTab;
};

