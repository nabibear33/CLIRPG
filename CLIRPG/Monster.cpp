#include "pch.h"
#include "Monster.h"

CMonster::CMonster()
	: CCharacter()
{
}

CMonster::CMonster(const char _szName[], int _iMaxHP, int _iHP, int _iAttack)
	: CCharacter(_szName, _iMaxHP, _iHP, _iAttack)
{
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
