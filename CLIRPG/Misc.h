#pragma once
#include "Item.h"

class CMisc : public CItem
{
public:
	CMisc();
	CMisc(
		eItemCode _eItemCode,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice
	);
	virtual ~CMisc();

	virtual CItem* Clone();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void PrintItemInfo(eStoreState _eStoreState);

private:

};

