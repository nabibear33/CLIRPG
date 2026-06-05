#pragma once

class CEquipItem;

class CEquipment
{
public:
	CEquipment();
	~CEquipment();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	void Equip();
	void Unequip();

private:
	
	CEquipItem* pHead;
	CEquipItem* pArmor;
	CEquipItem* pGloves;
	CEquipItem* pShoes;
	CEquipItem* pWeapon;
	
};

