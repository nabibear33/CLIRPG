#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
	: CCharacter()
{
	m_iGold = 0;
}

CMonster::CMonster(const char szName[], int iMaxHP, int iHP, int iAttack, int iGold)
	: CCharacter(szName, iMaxHP, iHP, iAttack)
{
	m_iGold = iGold;
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
}

void CMonster::Update()
{
}

void CMonster::Release()
{
}
