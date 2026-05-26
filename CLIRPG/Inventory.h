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

	int GetItemCount();
	void UpdateGold(int Gold);
	void SetCurrentTab(eItemType ItemType);
	int GetCurrentGold();
	vector<CItem*>& GetItems();

	void AddItem(CItem* pItem);
	void RemoveItem(CItem* pItem);

	CItem* GetItemFromSelection(int iSelection);

	void PrintItems(eStoreTab StoreTab);
	
private:
	vector<CItem*> m_Items;

	eItemType m_CurrentTab;

	int m_iGold;
};

