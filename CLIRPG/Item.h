#pragma once

#include "pch.h"

class CItem
{
public:
	CItem();
	CItem(
		eItemCode _eItemCode,
		eItemType _eItemType,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice
	);
	virtual ~CItem();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	eItemType GetItemType();

	virtual void PrintItemInfo(bool bPrintPrice);

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

