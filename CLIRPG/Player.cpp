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
	m_pInventory = nullptr;
	m_ePlayerClassType = ePlayerClassCode::NONE;
}

CPlayer::CPlayer(const char szName[], int iMaxHP, int iHP, int iAttack)
	: CCharacter(szName, iMaxHP, iHP, iAttack)
{
	m_pInventory = nullptr;
	m_ePlayerClassType = ePlayerClassCode::NONE;
}

CPlayer::~CPlayer()
{
	SafeDeleteSingle(m_pInventory);
}

void CPlayer::Initialize()
{
	m_pInventory = new CInventory;
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

void CPlayer::InitializeClass(int iSelection)
{
	switch (iSelection)
	{
	case 1:
		m_ePlayerClassType = ePlayerClassCode::WARRIOR;
		SetName("전사");
		SetMaxHP(150);
		SetHP(150);
		SetAttack(5);
		return;
	case 2:
		m_ePlayerClassType = ePlayerClassCode::MAGICIAN;
		SetName("마법사");
		SetMaxHP(50);
		SetHP(50);
		SetAttack(15);
		return;
	case 3:
		m_ePlayerClassType = ePlayerClassCode::THEIF;
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

void CPlayer::Revive()
{
	SetHP(GetMaxHP());
}

CInventory* CPlayer::GetInventory()
{
	return m_pInventory;
}
