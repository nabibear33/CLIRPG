#pragma once

#include "pch.h"
#include "Item.h"
#include "EquipItem.h"
#include "ConsumeItem.h"
#include "MiscItem.h"
#include "Monster.h"
#include "Player.h"
#include "Memory.h"


struct tItemDB
{
	~tItemDB() { Safe_Delete(Item); }
	eItemCode _eItemCode;
	CItem* Item;
};

struct tMonsterDB
{
	~tMonsterDB() { Safe_Delete(Monster); }
	eMonsterCode _eMonsterCode;
	CMonster* Monster;
};

struct tPlayerClassDB
{
	~tPlayerClassDB() { Safe_Delete(Player); }
	ePlayerClassCode _ePlayerClassCode;
	CPlayer* Player;
};

struct tDropItemDB
{
	eMonsterCode _eMonsterCode;
	eItemCode _eItemCode;
	double dDropChance;
};

struct tLevelDB
{
	int iLevel;
	int iRequiredExp;
};

class DB
{
public:
	static tItemDB ItemDB[MAX_DB_ARRAY_SIZE];
	static tMonsterDB MonsterDB[MAX_DB_ARRAY_SIZE];
	static tPlayerClassDB PlayerClassDB[MAX_DB_ARRAY_SIZE];
	static tDropItemDB DropItemDB[MAX_DB_ARRAY_SIZE];
	static tLevelDB LevelDB[MAX_DB_ARRAY_SIZE];
};

