#include "pch.h"
#include "Player.h"
#include "Character.h"
#include "Inventory.h"
#include "Store.h"
#include "Item.h"
#include "Memory.h"

CPlayer::CPlayer()
	: CCharacter()
{
	m_Inventory = nullptr;
	m_ePlayerClassType = ePlayerClassType::NONE;
}

CPlayer::CPlayer(const char szName[], int iMaxHP, int iHP, int iAttack)
	: CCharacter(szName, iMaxHP, iHP, iAttack)
{
	m_Inventory = nullptr;
	m_ePlayerClassType = ePlayerClassType::NONE;
}

CPlayer::~CPlayer()
{
	SafeDeleteSingle(m_Inventory);
}

void CPlayer::Initialize()
{
	m_Inventory = new CInventory;
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

void CPlayer::InitializeClass(int iChoice)
{
	switch (iChoice)
	{
	case 1:
		m_ePlayerClassType = ePlayerClassType::WARRIOR;
		SetName("전사");
		SetMaxHP(150);
		SetHP(150);
		SetAttack(5);
		return;
	case 2:
		m_ePlayerClassType = ePlayerClassType::MAGICIAN;
		SetName("마법사");
		SetMaxHP(50);
		SetHP(50);
		SetAttack(15);
		return;
	case 3:
		m_ePlayerClassType = ePlayerClassType::THEIF;
		SetName("도적");
		SetMaxHP(100);
		SetHP(100);
		SetAttack(10);
		return;
	// Input value is guaranteed by MainGame
	default:
		return;
	}
}

void CPlayer::Sell(CItem* Item)
{
	m_Inventory->UpdateGold(Item->GetSellPrice());
	m_Inventory->RemoveItem(Item);
}

void CPlayer::Buy(CStore* Store, CItem* Item)
{
	if (Item->GetBuyPrice() <= m_Inventory->GetCurrentGold())
	{
		Store->SellItem(this, Item);
		m_Inventory->AddItem(Item);
	}
	else
	{
		cout << "골드가 부족하여 아이템을 구매할 수 없습니다." << endl;
		system("pause");
	}
}

CInventory* CPlayer::GetInventory()
{
	return m_Inventory;
}
