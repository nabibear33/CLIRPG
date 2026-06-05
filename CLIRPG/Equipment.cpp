#include "pch.h"
#include "Equipment.h"
#include "Item.h"
#include "Memory.h"
#include "EquipItem.h"
#include "Player.h"
#include "Inventory.h"

CEquipment::CEquipment(CPlayer* pPlayer) : m_pPlayer(pPlayer)
{
}

CEquipment::~CEquipment()
{
}

void CEquipment::Initialize()
{
	m_mapEquipSlot.insert({ eEquipmentType::HEAD, nullptr });
	m_mapEquipSlot.insert({ eEquipmentType::ARMOR, nullptr });
	m_mapEquipSlot.insert({ eEquipmentType::WEAPON, nullptr });
}

void CEquipment::Update()
{
	while (true)
	{
		system("cls");

		cout << "1. 장착(교체)  2. 해제  3. 뒤로가기" << endl;
		cout << "선택지를 입력하세요 : ";

		int iSelection(0);
		cin >> iSelection;
		switch (iSelection)
		{
		case 1:
			OnEquipMenu();
			break;
		case 2:
			OnUnequipMenu();
			break;
		case 3:
			return;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CEquipment::Release()
{
	for (auto iter = m_mapEquipSlot.begin(); iter != m_mapEquipSlot.end(); ++iter)
	{
		Safe_Delete(iter->second);
	}
	m_mapEquipSlot.clear();
}

void CEquipment::Render()
{
	cout << "============= 장비창 ===============" << endl;
	for (auto iter = m_mapEquipSlot.begin(); iter != m_mapEquipSlot.end(); ++iter)
	{
		CEquipItem* pCurrentEquipItem = iter->second;
		cout << "[" << CEnum::EnumToString(iter->first) << "] " << pCurrentEquipItem->GetName() << endl;
		cout << "체력 +" << pCurrentEquipItem->GetHP() << "\t";
		cout << "공격력 +" << pCurrentEquipItem->GetAttack() << endl;
	}
}

void CEquipment::Equip(CItem* pItem)
{
	CEquipItem* pEquipItem = dynamic_cast<CEquipItem*>(pItem);
	if (pEquipItem)
	{
		m_pPlayer->GetInventory()->PopItem(pItem);
		eEquipmentType eType = pEquipItem->GetEquipmentType();
		if (m_mapEquipSlot[eType])
		{
			Unequip(m_mapEquipSlot[eType]);
		}
		m_mapEquipSlot[eType] = pEquipItem;
		UpdatePlayerStat(pEquipItem, true);
	}
}

void CEquipment::Unequip(CEquipItem* pEquipItem)
{
	eEquipmentType eType = pEquipItem->GetEquipmentType();
	
	m_pPlayer->GetInventory()->AddItem(pEquipItem);

	m_mapEquipSlot[eType] = nullptr;

	UpdatePlayerStat(pEquipItem, false);
}

void CEquipment::UpdatePlayerStat(CEquipItem* pEquipItem, bool bEquip)
{
	int iCoef = bEquip ? 1 : -1;
	for (auto iter = m_mapEquipSlot.begin(); iter != m_mapEquipSlot.end(); ++iter)
	{
		CEquipItem* pCurrentEquipItem = iter->second;
		if (pCurrentEquipItem)
		{
			m_pPlayer->SetAttack(m_pPlayer->GetAttack() + iCoef * pCurrentEquipItem->GetAttack());
			m_pPlayer->SetHP(m_pPlayer->GetHP() + iCoef * pCurrentEquipItem->GetHP());
		}
	}
}

void CEquipment::OnEquipMenu()
{
	while (true)
	{
		system("cls");

		m_pPlayer->PrintCharacterInfo();
		vector<CItem*>& vecEquipItems = m_pPlayer->GetInventory()->GetEquipItems();
		for (auto iter = vecEquipItems.begin(); iter != vecEquipItems.end(); ++iter)
		{
			cout << (iter - vecEquipItems.begin() + 1) << ". ";
			(*iter)->PrintItemInfo(eStoreState::NONE);
		}

		cout << "0. 뒤로가기" << endl;
		cout << "장착할 아이템 번호를 입력하세요 : ";

		size_t iSelection(0);
		cin >> iSelection;
		if (iSelection > 0 && iSelection <= vecEquipItems.size())
		{
			CEquipItem* pEquipItem = dynamic_cast<CEquipItem*>(vecEquipItems[iSelection - 1]);
			if (pEquipItem)
			{
				Equip(pEquipItem);
				m_pPlayer->GetInventory()->PopItem(vecEquipItems[iSelection - 1]);
				cout << "장착(교체)이 완료되었습니다." << endl;
				system("pause");
				continue;
			}
			else
			{
				cout << "아이템을 불러오는 중 오류 발생" << endl;
				system("pause");
				continue;
			}
		}
		else
		{
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CEquipment::OnUnequipMenu()
{
	while (true)
	{
		system("cls");
		m_pPlayer->PrintCharacterInfo();
		Render();

		cout << "0. 뒤로가기  1. 모자  2. 방어구  3. 무기" << endl;
		cout << "해제할 장비 아이템 번호를 입력하세요 : ";

		int iSelection(0);
		cin >> iSelection;
		eEquipmentType eType;
		switch (iSelection)
		{
		case 1:
			eType = eEquipmentType::HEAD;
			break;
		case 2:
			eType = eEquipmentType::ARMOR;
			break;
		case 3:
			eType = eEquipmentType::WEAPON;
			break;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
		
		CEquipItem* pSelectedEquipItem = m_mapEquipSlot[eType];
		Unequip(pSelectedEquipItem);
		m_pPlayer->GetInventory()->AddItem(pSelectedEquipItem);
		cout << "해제가 완료되었습니다." << endl;
		system("pause");
	}
}
