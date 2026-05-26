#include "pch.h"
#include "Item.h"
#include "Database.h"

CItem::CItem()
{
	strcpy_s(m_szName, sizeof(m_szName), "");
	strcpy_s(m_szDetail, sizeof(m_szDetail), "");
}

CItem::CItem(eItemCode _eItemCode)
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::ItemDB[i]._eItemCode == _eItemCode)
		{
			*this = DB::ItemDB[i].Item;
			return;
		}
	}
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

CItem::CItem(const CItem& other)
{
	m_eItemCode = other.m_eItemCode;
	m_eItemType = other.m_eItemType;
	strcpy_s(m_szName, sizeof(m_szName), other.m_szName);
	strcpy_s(m_szDetail, sizeof(m_szDetail), other.m_szDetail);
	m_iBuyPrice = other.m_iBuyPrice;
	m_iSellPrice = other.m_iSellPrice;
	m_bFinite = other.m_bFinite;
	m_bCountable = other.m_bCountable;
	m_iCount = other.m_iCount;
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

void CItem::PrintItemInfo(eStoreState _eStoreState)
{
	cout << "[" << CEnum::EnumToString(m_eItemType) << "] " << m_szName << endl;
	cout << m_szDetail << endl;
	switch (_eStoreState)
	{
	case eStoreState::NONE:
		break;
	case eStoreState::ON_BUYING:
		cout << "구매 가격 : " << m_iBuyPrice << "골드" << endl;
		break;
	case eStoreState::ON_SELLING:
		cout << "판매 가격 : " << m_iSellPrice << "골드" << endl;
		break;
	}
}
