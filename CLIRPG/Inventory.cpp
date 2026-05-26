#include "pch.h"
#include "Inventory.h"
#include "Item.h"

CInventory::CInventory()
{
	m_CurrentTab = eItemType::NONE;
	m_iGold = 0;
}

CInventory::~CInventory()
{
}

void CInventory::Initialize()
{
}

void CInventory::Update()
{
}

void CInventory::Release()
{
}

int CInventory::GetItemCount()
{
	return static_cast<int>(m_Items.size());
}

void CInventory::AddItem(CItem* pItem)
{
	m_Items.push_back(pItem);
}

void CInventory::RemoveItem(CItem* pItem)
{
	auto it = find(m_Items.begin(), m_Items.end(), pItem);
	if (it != m_Items.end())
	{
		m_Items.erase(it);
	}
	else
	{
		cout << "아이템을 찾지 못하여 인벤토리에서 제거하지 못했습니다." << endl;
	}
}

void CInventory::UpdateGold(int Gold)
{
	m_iGold += Gold;
}

void CInventory::SetCurrentTab(eItemType ItemType)
{
	m_CurrentTab = ItemType;
}

int CInventory::GetCurrentGold()
{
	return m_iGold;
}

vector<CItem*>& CInventory::GetItems()
{
	return m_Items;
}

CItem* CInventory::GetItemFromSelection(int iSelection)
{
	if ((iSelection > m_Items.size()) || (iSelection <= 0)) return nullptr;
	int iIndex = iSelection - 1;
	return m_Items[iIndex];
}

void CInventory::PrintItems(eStoreTab StoreTab)
{
	int iIndex = 1;
	for (auto Item : m_Items)
	{
		cout << "==========================" << endl;
		cout << iIndex << "." << endl;
		Item->PrintItemInfo(StoreTab);
		++iIndex;
	}
}
