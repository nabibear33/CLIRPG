#pragma once

#include "Character.h"

class CMonster : public CCharacter
{
public:
	CMonster();
	CMonster(const char _szName[], int _iMaxHP, int _iHP, int _iAttack);
	virtual ~CMonster();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

private:

};

