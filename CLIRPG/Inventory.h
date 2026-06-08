#pragma once

#include "pch.h"

class CItem;
class CEquipItem;

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
	vector<CItem*> GetItems();

	void AddItem(CItem* pItem);
	CItem* PopItem(CItem* pItem);
	CItem* PopItem(int iIndex);
	void RemoveItem(CItem* pItem);
	void RemoveItem(int iIndex);

	CItem* GetItemFromSelection(int iSelection);

	bool IsValidIndex(int iSelection);

	void PrintItems(eStoreState _eStoreState);

	inline bool IsFull() { return m_vecItem.size() == 5; }
	
	vector<CEquipItem*> GetEquipItems();

	void LoadSaveData(tagSaveData& tSaveData);
	
private:
	vector<CItem*> m_vecItem;

	eItemType m_eCurrentTab;

	int m_iGold;
};

