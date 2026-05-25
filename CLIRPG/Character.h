#pragma once

#include "pch.h"

class CCharacter
{
public:
	CCharacter();
	CCharacter(const char _szName[], int _iMaxHP, int _iHP, int _iAttack);
	virtual ~CCharacter();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	// Getter, Settter
	char* GetName();
	int GetMaxHP();
	int GetHP();
	int GetAttack();
	void SetName(const char _szName[]);
	void SetMaxHP(int _iMaxHP);
	void SetHP(int _iHP);
	void SetAttack(int _iAttack);

	// On Combat
	void Attack(CCharacter* pCounterPart);
	void OnDamaged(int _iAttack);
	bool IsDead();
	virtual void OnDead() {}
	virtual void Revive() {}

	virtual void InitializeClass(int iChoice) {}

	void PrintInfo();

private:
	char m_szName[MAX_NAME_SIZE];
	int m_iMaxHP;
	int m_iHP;
	int m_iAttack;
};