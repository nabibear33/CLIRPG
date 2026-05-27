#pragma once

#include "Character.h"

class CPlayer;

class CMonster : public CCharacter
{
public:
	CMonster();
	CMonster(eMonsterCode _eMonsterCode);
	CMonster(
		eMonsterCode _eMonsterCode,
		const char szName[],
		int iMaxHP,
		int iHP,
		int iAttack,
		int iGold);
	CMonster(const CMonster& other);
	virtual ~CMonster();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual CCharacter* Clone() override;

	void OnDead(CPlayer* pPlayer);

	void DropItem(CPlayer* pPlayer);

private:
	void PickDropItems();

	int m_iGold;

	CInventory* m_pInventory;

	eMonsterCode m_eMonsterCode;
};

