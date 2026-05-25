#pragma once

#include "Character.h"
#include "Types.h"

class Item;

class CPlayer : public CCharacter
{
public:
	CPlayer();
	CPlayer(const char _szName[], int _iMaxHP, int _iHP, int _iAttack);
	virtual ~CPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	virtual void InitializeClass(int iChoice);

private:
	ePlayerClassType m_ePlayerClassType;

	Item* Items;
};

