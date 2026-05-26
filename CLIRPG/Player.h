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

	virtual void Sell(CItem* Item);
	virtual void Buy(CStore* Store, CItem* Item);

	virtual CInventory* GetInventory() override;

private:
	ePlayerClassType m_ePlayerClassType;

	CInventory* m_Inventory;
};

