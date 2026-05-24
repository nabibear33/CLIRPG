#include "pch.h"
#include "Player.h"
#include "Character.h"

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
