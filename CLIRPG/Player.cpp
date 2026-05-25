#include "pch.h"
#include "Player.h"
#include "Character.h"

CPlayer::CPlayer()
	: CCharacter()
{
	m_ePlayerClassType = ePlayerClassType::NONE;
}

CPlayer::CPlayer(const char _szName[], int _iMaxHP, int _iHP, int _iAttack)
	: CCharacter(_szName, _iMaxHP, _iHP, _iAttack)
{
	m_ePlayerClassType = ePlayerClassType::NONE;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
}

void CPlayer::Update()
{
}

void CPlayer::Release()
{
}

void CPlayer::InitializeClass(int iChoice)
{
	switch (iChoice)
	{
	case 1:
		m_ePlayerClassType = ePlayerClassType::WARRIOR;
		SetName("전사");
		SetMaxHP(150);
		SetHP(150);
		SetAttack(5);
		return;
	case 2:
		m_ePlayerClassType = ePlayerClassType::MAGICIAN;
		SetName("마법사");
		SetMaxHP(50);
		SetHP(50);
		SetAttack(15);
		return;
	case 3:
		m_ePlayerClassType = ePlayerClassType::THEIF;
		SetName("도적");
		SetMaxHP(100);
		SetHP(100);
		SetAttack(10);
		return;
	// Input value is guaranteed by MainGame
	default:
		return;
	}
}