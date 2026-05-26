#pragma once
#include "Item.h"

class CMisc : public CItem
{
public:
	CMisc();
	virtual ~CMisc();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void PrintItemInfo(eStoreTab StoreTab);

private:

};

