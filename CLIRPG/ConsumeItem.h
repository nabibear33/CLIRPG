#pragma once

#include "Item.h"
#include "pch.h"

class CConsumeItem : public CItem
{
public:
	CConsumeItem();
	CConsumeItem(
		eItemCode _eItemCode,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice,
		int iHP);
	virtual ~CConsumeItem();

	virtual CItem* Clone() override;

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Consume();

	virtual void PrintItemInfo(eStoreState _eStoreState);

private:
	int m_iHP;
};

