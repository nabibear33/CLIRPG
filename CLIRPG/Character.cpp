#include "pch.h"
#include "Character.h"
#include "Database.h"

CCharacter::CCharacter()
{
	strcpy_s(m_szName, sizeof(m_szName), "");
	m_iMaxHP = 0;
	m_iHP = 0;
	m_iAttack = 0;
}

CCharacter::CCharacter(const char szName[], int iMaxHP, int iHP, int iAttack)
{
	strcpy_s(m_szName, sizeof(m_szName), szName);
	m_iMaxHP = iMaxHP;
	m_iHP = iHP;
	m_iAttack = iAttack;
}

CCharacter::CCharacter(const CCharacter& other)
{
	strcpy_s(m_szName, sizeof(m_szName), other.m_szName);
	m_iMaxHP = other.m_iMaxHP;
	m_iHP = other.m_iHP;
	m_iAttack = other.m_iAttack;
}

CCharacter::~CCharacter()
{
}

void CCharacter::Initialize()
{
}

void CCharacter::Update()
{
}

void CCharacter::Release()
{
}

char* CCharacter::GetName()
{
	return m_szName;
}

int CCharacter::GetMaxHP()
{
	return m_iMaxHP;
}

int CCharacter::GetHP()
{
	return m_iHP;
}

int CCharacter::GetAttack()
{
	return m_iAttack;
}

void CCharacter::SetName(const char szName[])
{
	strcpy_s(m_szName, sizeof(m_szName), szName);
}

void CCharacter::SetMaxHP(int iMaxHP)
{
	m_iMaxHP = iMaxHP;
}

void CCharacter::SetHP(int iHP)
{
	m_iHP = iHP;
}

void CCharacter::SetAttack(int iAttack)
{
	m_iAttack = iAttack;
}

CCharacter* CCharacter::CreatePlayer(ePlayerClassCode _ePlayerClassCode)
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::PlayerClassDB[i]._ePlayerClassCode == _ePlayerClassCode)
		{
			return DB::PlayerClassDB[i].Player->Clone();
		}
	}
	return nullptr;
}

CCharacter* CCharacter::CreateMonster(eMonsterCode _eMonsterCode)
{
	for (int i = 0; i < MAX_DB_ARRAY_SIZE; ++i)
	{
		if (DB::MonsterDB[i]._eMonsterCode == _eMonsterCode)
		{
			return DB::MonsterDB[i].Monster->Clone();
		}
	}
	return nullptr;
}

void CCharacter::Attack(CCharacter* pCounterPart)
{
	pCounterPart->OnDamaged(m_iAttack);
}

void CCharacter::OnDamaged(int iAttack)
{
	m_iHP -= iAttack;
	m_iHP = (m_iHP >= 0) ? m_iHP : 0;
}

bool CCharacter::IsDead()
{
	return m_iHP == 0;
}

void CCharacter::PrintCharacterInfo()
{
	cout << "================================" << endl;
	cout << "이름 : " << m_szName << endl;
	cout << "체력 : " << m_iHP << "\t"
		 << "공격력 : " << m_iAttack << endl;
}