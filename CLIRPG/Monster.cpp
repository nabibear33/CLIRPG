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
	random_device rd;
	int RandomGold = (rd() % 7) - 3;
	m_iGold = iGold + RandomGold;
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

int CMonster::GetGold()
{
	return m_iGold;
}

void CMonster::OnDead()
{
}
