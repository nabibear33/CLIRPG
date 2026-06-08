#pragma once

#include "Character.h"
#include "pch.h"

class CInventory;
class CEquipment;
class CItem;

class CPlayer : public CCharacter
{
public:
	CPlayer();
	CPlayer(const char szName[], int iMaxHP, int iHP, int iAttack);
	virtual ~CPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual CCharacter* Clone() override;

	virtual void InitializeClass(int iSelection);

	void Revive();

	virtual CInventory* GetInventory();
	inline CEquipment* GetEquipment() { return m_pEquipment; }
	inline ePlayerClassCode GetPlayerClassCode() { return m_ePlayerClassType; }

	void LoadSaveData(tagSaveData& tSaveData);

private:
	ePlayerClassCode m_ePlayerClassType;

	CInventory* m_pInventory;
	CEquipment* m_pEquipment;
};

