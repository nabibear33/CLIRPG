#pragma once


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
	QUIT,
};

enum class ePlayerClassType
{
	NONE = 0,
	WARRIOR,
	MAGICIAN,
	THEIF,
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
	HEADGEAR,
	ARMOR,
	WEAPON,
};

enum class eStoreTab
{
	NONE = 0,
	BUY,
	SELL,
};

enum class eItemCode
{
	// Equipment
	EQUIP_NONE = 1001,
	EQUIP_HEADGEAR_BASIC,
	EQUIP_ARMOR_BASIC,
	EQUIP_WEAPON_BASIC,
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