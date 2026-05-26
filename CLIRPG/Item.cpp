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

int CItem::GetBuyPrice()
{
	return m_iBuyPrice;
}

int CItem::GetSellPrice()
{
	return m_iSellPrice;
}

void CItem::PrintItemInfo(eStoreTab StoreTab)
{
	cout << "[" << Enum::EnumToString(m_eItemType) << "] " << m_szName << endl;
	cout << m_szDetail << endl;
	switch (StoreTab)
	{
	case eStoreTab::NONE:
		break;
	case eStoreTab::BUY:
		cout << "구매 가격 : " << m_iBuyPrice << "골드" << endl;
		break;
	case eStoreTab::SELL:
		cout << "판매 가격 : " << m_iSellPrice << "골드" << endl;
		break;
	}
}
