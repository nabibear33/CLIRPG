#pragma once

class CEquipItem;
class CPlayer;
class CItem;

class CEquipment
{
public:
	CEquipment(CPlayer* pPlayer);
	~CEquipment();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void Render();

	void Equip(CItem* pItem);
	void Unequip(CEquipItem* pEquipItem);

	void UpdatePlayerStat(CEquipItem* pEquipItem, bool bEquip);

private:
	map<eEquipmentType, CEquipItem*> m_mapEquipSlot;

	CPlayer* m_pPlayer;

	void OnEquipMenu();
	void OnUnequipMenu();
};

