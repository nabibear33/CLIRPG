#pragma once

#include "Item.h"
#include "pch.h"

class CPlayer;

class CEquipment : public CItem
{
public:
	CEquipment();
	CEquipment(
		eItemCode _eItemCode,
		eEquipmentType _eEquipmentType,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice,
		int iHP,
		int iAttack
	);
	virtual ~CEquipment();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Equip(CPlayer* pPlayer);

	virtual void PrintItemInfo(bool bPrintPrice) override;

private:
	eEquipmentType m_eEquipmentType;

	int m_iHP;
	int m_iAttack;
};

