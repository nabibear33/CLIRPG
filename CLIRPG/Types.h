#pragma once


enum class eGameStatus
{
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
	WARRIOR = 1,
	MAGICIAN,
	THEIF,
};

enum class eEquipmentType
{
	NONE = 0,
	HEADGEAR,
	ARMOR,
	WEAPON,
};