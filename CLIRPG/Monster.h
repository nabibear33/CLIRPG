#pragma once

#include "Character.h"

class CMonster : public CCharacter
{
public:
	CMonster();
	CMonster(
		const char szName[],
		int iMaxHP,
		int iHP,
		int iAttack,
		int iGold);
	virtual ~CMonster();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	int GetGold();

	virtual void OnDead() override;

private:
	int m_iGold;
};

