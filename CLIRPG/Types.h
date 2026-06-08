#pragma once

#include "Constants.h"

enum class eGameStatus
{
	NONE,
	INTRO,
	SELECTING_START_MODE,
	CHOOSING_CLASS,
	ON_LOBBY,
	SELECTING_LEVEL,
	ON_COMBAT,
	ON_STORE,
	ON_INVENTORY,
	ON_EQUIPMENT,
	QUIT,
};

enum class eItemType
{
	NONE = 0,
	EQUIPMENT,
	CONSUMABLE,
	MISC,
};

enum class eEquipmentType
{
	NONE = 0,
	HEAD,
	ARMOR,
	WEAPON,
};

enum class eStoreState
{
	NONE = 0,
	ON_MENU,
	ON_BUYING,
	ON_SELLING,
	EXIT,
};

enum class eItemCode
{
	// Equipment
	EQUIP_NONE = 1001,
	EQUIP_HEADGEAR_BASIC,
	EQUIP_ARMOR_BASIC,
	EQUIP_WEAPON_BASIC,
	EQUIP_HEADGEAR_RARE,
	EQUIP_ARMOR_RARE,
	EQUIP_WEAPON_RARE,
	EQUIP_MAX,

	// Consumable
	CONSUME_NONE = 2001,
	CONSUME_PORTION_HP_SMALL,
	CONSUME_MAX,

	// Misc
	MISC_NONE = 3001,
	MISC_DROP_EASY,
	MISC_DROP_NORMAL,
	MISC_DROP_HARD,
	MISC_MAX,
};

enum class ePlayerClassCode
{
	NONE = 0,
	WARRIOR,
	MAGICIAN,
	THIEF,
	MAX,
};

enum class eMonsterCode
{
	NONE = 0,
	EASY,
	NORMAL,
	HARD,
	MAX,
};


struct tagSaveData
{
public:
	// Player Info
	char szName[MAX_NAME_SIZE];
	int iMaxHP;
	int iHP;
	int iAttack;
	ePlayerClassCode ePlayerClassType;

	// Inventory Info
	eItemCode vecInventory[MAX_INVENTORY_SIZE];
	int iInventoryGold;
	size_t iInventorySize;

	// Equipment Info
	eEquipmentType mapEquipmentKey[MAX_INVENTORY_SIZE];
	eItemCode mapEquipmentValue[MAX_INVENTORY_SIZE];
	size_t iEquipmentSize;
};
