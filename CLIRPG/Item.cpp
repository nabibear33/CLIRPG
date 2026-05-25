#include "pch.h"
#include "Item.h"


CItem::CItem()
{
	strcpy_s(m_szName, sizeof(m_szName), "");
	strcpy_s(m_szDetail, sizeof(m_szDetail), "");
}

CItem::CItem(eItemCode _eItemCode, eItemType _eItemType, const char szName[], const char szDetail[], int iBuyPrice, int iSellPrice)
{
	m_eItemCode = _eItemCode;
	m_eItemType = _eItemType;
	strcpy_s(m_szName, sizeof(m_szName), szName);
	strcpy_s(m_szDetail, sizeof(m_szDetail), szDetail);
	m_iBuyPrice = iBuyPrice;
	m_iSellPrice = iSellPrice;

	m_bFinite = true;
	m_bCountable = (m_eItemType != eItemType::EQUIPMENT);
	m_iCount = 1;
}

CItem::~CItem()
{
}

void CItem::Initialize()
{
}

void CItem::Update()
{
}

void CItem::Release()
{
}

eItemType CItem::GetItemType()
{
	return m_eItemType;
}

void CItem::PrintItemInfo(bool bPrintPrice)
{
	cout << "[" << Enum::EnumToString(m_eItemType) << "] " << m_szName << "\t";
	if (bPrintPrice)
	{
		cout << "판매가 : " << m_iSellPrice << "\t";
	}
}
