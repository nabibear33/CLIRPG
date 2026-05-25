#pragma once
#include "Item.h"
#include "Types.h"

class CEquipment : public CItem
{
public:
	CEquipment();
	virtual ~CEquipment();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Equip();

private:
	eEquipmentType m_eEquipmentType;

	int iHP;
	int iAttack;
};

