#include "pch.h"
#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "Memory.h"

CStore::CStore()
{
	m_Inventory = nullptr;
	m_CurrentTab = eStoreTab::NONE;
}

CStore::~CStore()
{
	SafeDeleteSingle(m_Inventory);
}

void CStore::Initialize()
{
	m_Inventory = new CInventory;
}

void CStore::Update()
{
}

void CStore::Release()
{
}

CInventory* CStore::GetInventory()
{
	return m_Inventory;
}

eStoreTab CStore::GetCurrentTab()
{
	return m_CurrentTab;
}

void CStore::SetCurrentTab(eStoreTab StoreTab)
{
	m_CurrentTab = StoreTab;
}

void CStore::SellItem(CPlayer* Player, CItem* Item)
{
	m_Inventory->RemoveItem(Item);
	Player->GetInventory()->AddItem(Item);
	Player->GetInventory()->UpdateGold(-Item->GetBuyPrice());
}