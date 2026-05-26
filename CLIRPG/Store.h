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

	void SetPlayer(CPlayer* pPlayer);
	void SetCurrentState(eStoreState _eStoreState);

	CInventory* GetInventory();
	eStoreState GetCurrentState();

private:
	void OnSelectMenu();
	void OnBuyTab();
	void OnSellTab();

	void PrintHeader();

	void OnPlayerBuy(CItem* pItem);
	void OnPlayerSell(CItem* pItem);
	
	CInventory* m_pInventory;

	eStoreState m_eCurrentState;

	CPlayer* m_pPlayer;
};

