#include "pch.h"
#include "EquipItem.h"
#include "Player.h"

CEquipItem::CEquipItem() : CItem()
{
	m_eEquipmentType = eEquipmentType::NONE;
	m_iHP = 0;
	m_iAttack = 0;
}

CEquipItem::CEquipItem(eItemCode _eItemCode, eEquipmentType _eEquipmentType, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice, int iHP, int iAttack)
	: CItem(_eItemCode, eItemType::EQUIPMENT, szName, szDetail, iBuyPrice, iSellPrice)
{
	m_eEquipmentType = _eEquipmentType;
	m_iHP = iHP;
	m_iAttack = iAttack;
}

CEquipItem::~CEquipItem()
{
}

void CEquipItem::Initialize()
{
}

void CEquipItem::Update()
{
}

void CEquipItem::Release()
{
}

CItem* CEquipItem::Clone()
{
	return new CEquipItem(*this);
}

void CEquipItem::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
	cout << "체력 증가량 : " << m_iHP << endl;
	cout << "공격력 증가량 : " << m_iAttack << endl;
}
