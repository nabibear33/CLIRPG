#include "pch.h"
#include "Misc.h"
#include "Database.h"

CMisc::CMisc()
{
}

CMisc::CMisc(eItemCode _eItemCode, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice)
	: CItem(_eItemCode, eItemType::MISC, szName, szDetail, iBuyPrice, iSellPrice)
{
}

CMisc::~CMisc()
{
}

CItem* CMisc::Clone()
{
	return new CMisc(*this);
}

void CMisc::Initialize()
{
}

void CMisc::Update()
{
}

void CMisc::Release()
{
}

void CMisc::PrintItemInfo(eStoreState _eStoreState)
{
	CItem::PrintItemInfo(_eStoreState);
}
