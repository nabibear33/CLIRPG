#include "pch.h"
#include "MiscItem.h"
#include "Database.h"

CMiscItem::CMiscItem()
{
}

CMiscItem::CMiscItem(eItemCode _eItemCode, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice)
	: CItem(_eItemCode, eItemType::MISC, szName, szDetail, iBuyPrice, iSellPrice)
{
}

CMiscItem::~CMiscItem()
{
}

CItem* CMiscItem::Clone()
{
	return new CMiscItem(*this);
}

void CMiscItem::Initialize()
{
}

void CMiscItem::Update()
{
}

void CMiscItem::Release()
{
}

void CMiscItem::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
}
