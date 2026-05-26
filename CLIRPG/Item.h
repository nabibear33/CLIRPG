#pragma once

#include "pch.h"

class CItem
{
public:
	CItem();
	CItem(eItemCode _eItemCode);
	CItem(
		eItemCode _eItemCode,
		eItemType _eItemType,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice
	);
	CItem(const CItem& other);
	virtual ~CItem();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	eItemType GetItemType();
	int GetBuyPrice();
	int GetSellPrice();

	virtual void PrintItemInfo(eStoreState _eStoreState);

private:
	eItemCode m_eItemCode;
	eItemType m_eItemType;

	char m_szName[MAX_NAME_SIZE];
	char m_szDetail[MAX_DETAIL_SIZE];

	int m_iBuyPrice;
	int m_iSellPrice;

	bool m_bFinite;
	bool m_bCountable;
	int m_iCount;
};

