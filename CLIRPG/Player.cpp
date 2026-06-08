#include "pch.h"
#include "Player.h"
#include "Character.h"
#include "Inventory.h"
#include "Equipment.h"
#include "Store.h"
#include "Item.h"
#include "Memory.h"
#include "EquipItem.h"

CPlayer::CPlayer()
	: CCharacter()
{
	m_pInventory = nullptr;
	m_pEquipment = nullptr;
	m_ePlayerClassType = ePlayerClassCode::NONE;
}

CPlayer::CPlayer(ePlayerClassCode _ePlayerClassCode, const char szName[], int iMaxHP, int iHP, int iAttack)
	: CCharacter(szName, iMaxHP, iHP, iAttack)
{
	m_pInventory = nullptr;
	m_pEquipment = nullptr;
	m_ePlayerClassType = _ePlayerClassCode;
}

CPlayer::~CPlayer()
{
	Safe_Delete(m_pInventory);
	Safe_Delete(m_pEquipment);
}

void CPlayer::Initialize()
{
	m_pInventory = new CInventory;
	m_pInventory->UpdateGold(1000);
	m_pEquipment = new CEquipment(this);
	m_pEquipment->Initialize();
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

CCharacter* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::Revive()
{
	SetHP(GetMaxHP());
}

CInventory* CPlayer::GetInventory()
{
	return m_pInventory;
}

void CPlayer::LoadSaveData(tagSaveData& tSaveData)
{
	m_ePlayerClassType = tSaveData.ePlayerClassType;
	SetName(tSaveData.szName);
	SetMaxHP(tSaveData.iMaxHP);
	SetHP(tSaveData.iHP);
	SetAttack(tSaveData.iAttack);

	m_pInventory->LoadSaveData(tSaveData);
	m_pEquipment->LoadSaveData(tSaveData);
}

