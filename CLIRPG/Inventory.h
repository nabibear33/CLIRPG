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
	void SetCurrentTab(eItemType _eItemType);
	int GetCurrentGold();
	CItem** GetItems();

	void AddItem(CItem* pItem);
	CItem* PopItem(CItem* pItem);
	CItem* PopItem(int iIndex);
	void RemoveItem(CItem* pItem);
	void RemoveItem(int iIndex);

	CItem* GetItemFromSelection(int iSelection);

	bool IsValidIndex(int iSelection);

	void PrintItems(eStoreState _eStoreState);
	
private:
	CItem* m_pItems[MAX_INVENTORY_SIZE];
	int m_iNumItems;

	eItemType m_eCurrentTab;

	int m_iGold;
};

