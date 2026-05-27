#pragma once

#include "pch.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Misc.h"
#include "Monster.h"
#include "Player.h"
#include "Memory.h"


struct tItemDB
{
	~tItemDB() { SafeDeleteSingle(Item); }
	eItemCode _eItemCode;
	CItem* Item;
};

struct tMonsterDB
{
	~tMonsterDB() { SafeDeleteSingle(Monster); }
	eMonsterCode _eMonsterCode;
	CMonster* Monster;
};

struct tPlayerClassDB
{
	~tPlayerClassDB() { SafeDeleteSingle(Player); }
	ePlayerClassCode _ePlayerClassCode;
	CPlayer* Player;
};

struct tDropItemDB
{
	eMonsterCode _eMonsterCode;
	eItemCode _eItemCode;
	double dDropChance;
};

class DB
{
public:
	static tItemDB ItemDB[MAX_DB_ARRAY_SIZE];
	static tMonsterDB MonsterDB[MAX_DB_ARRAY_SIZE];
	static tPlayerClassDB PlayerClassDB[MAX_DB_ARRAY_SIZE];
	static tDropItemDB DropItemDB[MAX_DB_ARRAY_SIZE];
};

