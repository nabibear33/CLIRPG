#pragma once

#include "Character.h"
#include "pch.h"

class CInventory;
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

	virtual void InitializeClass(int iChoice);

	void Sell(CItem* Item);
	void Buy(CItem* Item);

private:
	ePlayerClassType m_ePlayerClassType;

	CInventory* m_Inventory;
};

