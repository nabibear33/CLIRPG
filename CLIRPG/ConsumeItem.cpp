#include "pch.h"
#include "ConsumeItem.h"

CConsumeItem::CConsumeItem() : CItem()
{
	m_iHP = 0;
}

CConsumeItem::CConsumeItem(eItemCode _eItemCode, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice, int iHP)
	: CItem(_eItemCode, eItemType::CONSUMABLE, szName, szDetail, iBuyPrice, iSellPrice)
{
	m_iHP = iHP;
}

CConsumeItem::~CConsumeItem()
{
}

CItem* CConsumeItem::Clone()
{
	return new CConsumeItem(*this);
}

void CConsumeItem::Initialize()
{
}

void CConsumeItem::Update()
{
}

void CConsumeItem::Release()
{
}

void CConsumeItem::Consume()
{
}

void CConsumeItem::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
	cout << "HP 회복량 : " << m_iHP << endl;
}
