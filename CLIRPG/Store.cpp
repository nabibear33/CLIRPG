#include "pch.h"
#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "Memory.h"

CStore::CStore()
{
	m_pInventory = nullptr;
	m_pPlayer = nullptr;
	m_eCurrentState = eStoreState::NONE;
}

CStore::~CStore()
{
	SafeDeleteSingle(m_pInventory);
}

void CStore::Initialize()
{
	m_pInventory = new CInventory;
}

void CStore::Update()
{
	while (m_eCurrentState != eStoreState::EXIT)
	{
		switch (m_eCurrentState)
		{
		case eStoreState::NONE:
			OnSelectMenu();
			continue;
		case eStoreState::ON_BUYING:
			OnBuyTab();
			continue;
		case eStoreState::ON_SELLING:
			OnSellTab();
			continue;
		}
	}
}



void CStore::Release()
{
}

void CStore::OnSelectMenu()
{
	while (true)
	{
		system("cls");
		PrintHeader();
		cout << "0. 뒤로 가기  1. 구매  2. 판매" << endl;
		cout << "선택지를 입력하세요 : ";
		int iTabSelection;
		cin >> iTabSelection;

		switch (iTabSelection)
		{
		case 0:
			SetCurrentState(eStoreState::EXIT);
			return;
		case 1:
			SetCurrentState(eStoreState::ON_BUYING);
			return;
		case 2:
			SetCurrentState(eStoreState::ON_SELLING);
			return;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CStore::OnBuyTab()
{
	while (true)
	{
		system("cls");
		PrintHeader();
		GetInventory()->PrintItems(m_eCurrentState);
		cout << endl;
		cout << "0. 뒤로 가기" << endl;
		cout << "메뉴를 선택하거나 해당되는 아이템 번호를 입력하세요 : ";
		int iBuyItemSelection;
		cin >> iBuyItemSelection;

		if (iBuyItemSelection == 0)
		{
			SetCurrentState(eStoreState::ON_MENU);
			continue;
		}
		else if (CItem* pItem = GetInventory()->GetItemFromSelection(iBuyItemSelection))
		{
			OnPlayerBuy(pItem);
			cout << "아이템 구매 완료" << endl;
			system("pause");
			continue;
		}
		else
		{
			cout << "유효한 입력값을 입력하세요" << endl;
			system("pause");
			continue;
		}
	}
}

void CStore::OnSellTab()
{
	while (true)
	{
		system("cls");
		PrintHeader();
		dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()->PrintItems(m_eCurrentState);
		cout << "0. 뒤로 가기" << endl;
		cout << "메뉴를 선택하거나 해당되는 아이템 번호를 입력하세요 : ";
		int iSellItemSelection;
		cin >> iSellItemSelection;

		if (iSellItemSelection == 0)
		{
			SetCurrentState(eStoreState::ON_MENU);
			return;
		}
		else if (CItem* pItem = dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()->GetItemFromSelection(iSellItemSelection))
		{
			OnPlayerSell(pItem);
			cout << "아이템 판매 완료" << endl;
			system("pause");
			return;
		}
		else
		{
			cout << "유효한 입력값을 입력하세요" << endl;
			system("pause");
			continue;
		}
	}
}

void CStore::SetPlayer(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CInventory* CStore::GetInventory()
{
	return m_pInventory;
}

eStoreState CStore::GetCurrentState()
{
	return m_eCurrentState;
}

void CStore::SetCurrentState(eStoreState _eStoreState)
{
	m_eCurrentState = _eStoreState;
}

void CStore::PrintHeader()
{
	cout << "============== 상점 ==============" << endl;
	cout << "보유 중인 골드 : " << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()->GetCurrentGold() << endl;
	cout << endl;
}

void CStore::OnPlayerBuy(CItem* pItem)
{
	if (pItem->GetBuyPrice() <= m_pInventory->GetCurrentGold())
	{
		m_pInventory->PopItem(pItem);
		m_pPlayer->GetInventory()->AddItem(pItem);
		m_pPlayer->GetInventory()->UpdateGold(-pItem->GetBuyPrice());
		
		cout << "아이템 구매 완료" << endl;
		system("pause");
	}
	else
	{
		cout << "보유한 골드가 부족합니다" << endl;
		system("pause");
	}
}

void CStore::OnPlayerSell(CItem* pItem)
{
	m_pPlayer->GetInventory()->PopItem(pItem);
	m_pPlayer->GetInventory()->UpdateGold(pItem->GetSellPrice());

	cout << "아이템 판매 완료" << endl;
	system("pause");
}