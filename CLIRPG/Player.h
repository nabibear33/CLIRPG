#pragma once

#include "Character.h"
#include "Types.h"


class CPlayer : public CCharacter
{
public:
	CPlayer();
	CPlayer(const char _szName[], int _iMaxHP, int _iHP, int _iAttack);
	virtual ~CPlayer();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	void InitializeClass(int iChoice);

private:
	EClassType m_ClassType;
};

