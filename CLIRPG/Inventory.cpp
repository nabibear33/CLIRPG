#include "pch.h"
#include "Inventory.h"
#include "Item.h"
#include "EquipItem.h"
#include "Memory.h"

CInventory::CInventory()
{
	m_eCurrentTab = eItemType::NONE;
	m_iGold = 0;
}

CInventory::~CInventory()
{
	for (size_t i = 0; i < m_vecItem.size(); ++i)
	{
		Safe_Delete(m_vecItem[i]);
	}
}

void CInventory::Initialize()
{
}

void CInventory::Update()
{
	while (true)
	{
		system("cls");
		PrintItems(eStoreState::NONE);

		cout << "0. 뒤로 가기" << endl;
		cout << "메뉴를 선택하세요 : ";

		int iSelection;
		cin >> iSelection;
		if (iSelection == 0) return;
	}
}

void CInventory::Release()
{
}

int CInventory::GetItemCount()
{
	return static_cast<int>(m_vecItem.size());
}

void CInventory::AddItem(CItem* pItem)
{
	m_vecItem.push_back(pItem);
}

CItem* CInventory::PopItem(CItem* pItem)
{
	for (vector<CItem*>::iterator iter = m_vecItem.begin(); iter != m_vecItem.end(); )
	{
		if (pItem == *iter)
		{
			CItem* pTempItem = *iter;
			iter = m_vecItem.erase(iter);
			return pTempItem;
		}
		else
		{
			++iter;
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
		CItem* pTempItem = m_vecItem[iIndex];
		m_vecItem.erase(m_vecItem.begin() + iIndex);
		return pTempItem;
	}
}

void CInventory::RemoveItem(CItem* pItem)
{
	for (vector<CItem*>::iterator iter = m_vecItem.begin(); iter != m_vecItem.end(); )
	{
		if (pItem == *iter)
		{
			Safe_Delete(*iter);
			iter = m_vecItem.erase(iter);
			return;
		}
		else
		{
			++iter;
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
		Safe_Delete(m_vecItem[iIndex]);
		m_vecItem.erase(m_vecItem.begin() + iIndex);
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

vector<CItem*> CInventory::GetItems()
{
	return m_vecItem;
}

CItem* CInventory::GetItemFromSelection(int iSelection)
{
	int iIndex = iSelection - 1;
	if (!IsValidIndex(iIndex)) return nullptr;
	return m_vecItem[iIndex];
}

bool CInventory::IsValidIndex(int iIndex)
{
	return (iIndex < static_cast<int>(m_vecItem.size())) && (iIndex >= 0);
}

void CInventory::PrintItems(eStoreState _eStoreState)
{
	cout << "========== 아이템 목록 ===========" << endl;
	for (vector<CItem*>::iterator iter = m_vecItem.begin(); iter != m_vecItem.end(); ++iter)
	{
		cout << iter - m_vecItem.begin() + 1 << "." << endl;
		(*iter)->PrintItemInfo(_eStoreState);
		cout << endl;
	}
	cout << "==================================" << endl;
}

vector<CItem*> CInventory::GetEquipItems()
{
	vector<CEquipItem*> vecEquipItems;
	for (auto iter = m_vecItem.begin(); iter != m_vecItem.end(); ++iter)
	{
		if ((*iter)->GetItemType() == eItemType::EQUIPMENT)
		{
			vecEquipItems.push_back(dynamic_cast<CEquipItem*>(*iter));
		}
	}
	return vecEquipItems;
}

void CInventory::LoadSaveData(tagSaveData& tSaveData)
{
	for (int i = 0; i < tSaveData.iInventorySize; ++i)
	{
		m_vecItem.push_back(CItem::Create(tSaveData.vecInventory[i]));
	}
	m_iGold = tSaveData.iInventoryGold;

}
