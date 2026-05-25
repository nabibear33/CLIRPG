#pragma once
#include "Item.h"

class CConsumable : public CItem
{
public:
	CConsumable();
	virtual ~CConsumable();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Consume();

private:
	int iHP;
};

