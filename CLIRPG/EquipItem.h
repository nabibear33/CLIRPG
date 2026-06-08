#pragma once

#include "Item.h"
#include "pch.h"

class CPlayer;

class CEquipItem : public CItem
{
public:
	CEquipItem();
	CEquipItem(
		eItemCode _eItemCode,
		eEquipmentType _eEquipmentType,
		const char szName[],
		const char szDetail[],
		int iBuyPrice,
		int iSellPrice,
		int iHP,
		int iAttack
	);
	virtual ~CEquipItem();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual CItem* Clone() override;

	virtual void PrintItemInfo(eStoreState _eStoreState) override;

	inline int GetHP() { return m_iHP; }
	inline int GetAttack() { return m_iAttack; }

	inline eEquipmentType GetEquipmentType() { return m_eEquipmentType; }


private:
	eEquipmentType m_eEquipmentType;

	int m_iHP;
	int m_iAttack;
};

