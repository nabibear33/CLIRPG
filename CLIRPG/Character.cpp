#include "pch.h"
#include "Character.h"

CCharacter::CCharacter()
{
	strcpy_s(m_szName, sizeof(m_szName), "");
	m_iMaxHP = 0;
	m_iHP = 0;
	m_iAttack = 0;
}

CCharacter::CCharacter(const char _szName[], int _iMaxHP, int _iHP, int _iAttack)
{
	strcpy_s(m_szName, sizeof(m_szName), _szName);
	m_iMaxHP = _iMaxHP;
	m_iHP = _iHP;
	m_iAttack = _iAttack;
}

CCharacter::~CCharacter()
{
	Release();
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

void CCharacter::SetName(const char _szName[])
{
	strcpy_s(m_szName, sizeof(m_szName), _szName);
}

void CCharacter::SetMaxHP(int _iMaxHP)
{
	m_iMaxHP = _iMaxHP;
}

void CCharacter::SetHP(int _iHP)
{
	m_iHP = _iHP;
}

void CCharacter::SetAttack(int _iAttack)
{
	m_iAttack = _iAttack;
}

void CCharacter::Attack(CCharacter* pCounterPart)
{
	pCounterPart->OnDamaged(m_iAttack);
}

void CCharacter::OnDamaged(int _iAttack)
{
	m_iHP -= _iAttack;
	m_iHP = (m_iHP >= 0) ? m_iHP : 0;
}

bool CCharacter::IsDead()
{
	return m_iHP == 0;
}

void CCharacter::Revive()
{
	m_iHP = m_iMaxHP;
}

//void CCharacter::InitializeClass(int iChoice)
//{
//}