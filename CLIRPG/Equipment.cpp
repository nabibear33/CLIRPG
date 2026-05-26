#include "pch.h"
#include "Equipment.h"
#include "Player.h"

CEquipment::CEquipment() : CItem()
{
	m_eEquipmentType = eEquipmentType::NONE;
	m_iHP = 0;
	m_iAttack = 0;
}

CEquipment::CEquipment(eItemCode _eItemCode, eEquipmentType _eEquipmentType, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice, int iHP, int iAttack)
	: CItem(_eItemCode, eItemType::EQUIPMENT, szName, szDetail, iBuyPrice, iSellPrice)
{
	m_eEquipmentType = _eEquipmentType;
	m_iHP = iHP;
	m_iAttack = iAttack;
}

CEquipment::~CEquipment()
{
}

void CEquipment::Initialize()
{
}

void CEquipment::Update()
{
}

void CEquipment::Release()
{
}

void CEquipment::Equip(CPlayer* pPlayer)
{
}

void CEquipment::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
	cout << "체력 증가량 : " << m_iHP << endl;
	cout << "공격력 증가량 : " << m_iAttack << endl;
}
