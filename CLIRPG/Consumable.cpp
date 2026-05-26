#include "pch.h"
#include "Consumable.h"

CConsumable::CConsumable() : CItem()
{
	m_iHP = 0;
}

CConsumable::CConsumable(eItemCode _eItemCode, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice, int iHP)
	: CItem(_eItemCode, eItemType::CONSUMABLE, szName, szDetail, iBuyPrice, iSellPrice)
{
	m_iHP = iHP;
}

CConsumable::~CConsumable()
{
}

void CConsumable::Initialize()
{
}

void CConsumable::Update()
{
}

void CConsumable::Release()
{
}

void CConsumable::Consume()
{
}

void CConsumable::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
	cout << "HP 회복량 : " << m_iHP << endl;
}
