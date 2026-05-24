#pragma once

#include "Character.h"
#include "Types.h"


class CPlayer : public CCharacter
{
public:
	CPlayer();
	~CPlayer();

	void InitializeClass(int iChoice);

private:
	EClassType m_ClassType;
};

