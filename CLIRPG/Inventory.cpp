#include "pch.h"
#include "Inventory.h"
#include "Item.h"
#include "Memory.h"

CInventory::CInventory()
{
	m_eCurrentTab = eItemType::NONE;
	m_iGold = 0;
	m_iNumItems = 0;
	for (int i = 0; i < MAX_INVENTORY_SIZE; ++i)
	{
		m_pItems[i] = nullptr;
	}
}

CInventory::~CInventory()
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; ++i)
	{
		SafeDeleteSingle(m_pItems[i]);
	}
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
	return m_iNumItems;
}

void CInventory::AddItem(CItem* pItem)
{
	m_pItems[m_iNumItems] = pItem;
	++m_iNumItems;
}

CItem* CInventory::PopItem(CItem* pItem)
{
	for (int i = 0; i < m_iNumItems; ++i)
	{
		if (pItem == m_pItems[i])
		{
			CItem* pTempItem = m_pItems[i];
			m_pItems[i] = nullptr;
			--m_iNumItems;
			return pTempItem;
		}
	}

	cout << "아이템을 찾지 못하여 인벤토리에서 제거하지 못했습니다." << endl;
	return nullptr;
}

CItem* CInventory::PopItem(int iIndex)
{
	if (!IsValidIndex(iIndex))
	{
		cout << "유효한 인덱스가 아닙니다" << endl;
		return nullptr;
	}
	else
	{
		CItem* pTempItem = m_pItems[iIndex];
		m_pItems[iIndex] = nullptr;
		return pTempItem;
	}
}

void CInventory::RemoveItem(CItem* pItem)
{
	for (int i = 0; i < m_iNumItems; ++i)
	{
		if (pItem == m_pItems[i])
		{
			SafeDeleteSingle(m_pItems[i]);
			--m_iNumItems;
			return;
		}
	}

	cout << "아이템을 찾지 못하여 인벤토리에서 제거하지 못했습니다." << endl;
}

void CInventory::RemoveItem(int iIndex)
{
	if (!IsValidIndex(iIndex))
	{
		cout << "유효한 인덱스가 아닙니다" << endl;
		return;
	}
	else
	{
		SafeDeleteSingle(m_pItems[iIndex]);
		return;
	}
}

void CInventory::UpdateGold(int iGold)
{
	m_iGold += iGold;
}

void CInventory::SetCurrentTab(eItemType _eItemType)
{
	m_eCurrentTab = _eItemType;
}

int CInventory::GetCurrentGold()
{
	return m_iGold;
}

CItem** CInventory::GetItems()
{
	return m_pItems;
}

CItem* CInventory::GetItemFromSelection(int iSelection)
{
	int iIndex = iSelection - 1;
	if (!IsValidIndex(iIndex)) return nullptr;
	return m_pItems[iIndex];
}

bool CInventory::IsValidIndex(int iIndex)
{
	return (iIndex < m_iNumItems) && (iIndex >= 0);
}

void CInventory::PrintItems(eStoreState _eStoreState)
{
	cout << "========== 아이템 목록 ===========" << endl;
	for (int i = 0; i < m_iNumItems; ++i)
	{
		cout << i << "." << endl;
		m_pItems[i]->PrintItemInfo(_eStoreState);
		cout << endl;
	}
	cout << "==================================" << endl;
}
