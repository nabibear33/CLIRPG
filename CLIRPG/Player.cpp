#include "pch.h"
#include "Player.h"
#include "Character.h"

CPlayer::CPlayer()
	: CCharacter()
{
	m_ClassType = NONE;
}

CPlayer::CPlayer(const char _szName[], int _iMaxHP, int _iHP, int _iAttack)
	: CCharacter(_szName, _iMaxHP, _iHP, _iAttack)
{
	m_ClassType = NONE;
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
		m_ClassType = WARRIOR;
		("전사", 150, 150, 5);
		return;
	case 2:
		m_ClassType = MAGICIAN;
		("마법사", 50, 50, 15);
		return;
	case 3:
		m_ClassType = THEIF;
		("도적", 100, 100, 10);
		return;
	default:
		cout << "잘못된 입력입니다" << endl;
		return;
	}
}