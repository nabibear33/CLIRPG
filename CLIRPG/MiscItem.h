#pragma once
#include "Item.h"

class CMiscItem : public CItem
{
public:
	CMiscItem();
	CMiscItem(
		eItemCode _eItemCode,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice
	);
	virtual ~CMiscItem();

	virtual CItem* Clone();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void PrintItemInfo(eStoreState _eStoreState);

private:

};

