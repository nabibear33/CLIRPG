#pragma once

#include "pch.h"

class CCharacter
{
public:
	// 생성자, 소멸자
	CCharacter();
	CCharacter(const char _szName[], int _iMaxHP, int _iHP, int _iAttack);
	~CCharacter();

	// 기본 함수
	void Initialize();
	void Update();
	void Release();

	// Get, Set
	char* GetName();
	int GetMaxHP();
	int GetHP();
	int GetAttack();
	void SetName(char _szName[]);
	void SetHP(int _iHP);
	void SetAttack(int _iAttack);

	// 전투 관련 함수
	void Attack(CCharacter* pCounterPart);
	void OnDamaged(int _iAttack);
	bool IsDead();
	void Revive();

	// virtual void InitializeClass(int iChoice);

private:
	char m_szName[MAX_NAME_SIZE];
	int m_iMaxHP;
	int m_iHP;
	int m_iAttack;
};

