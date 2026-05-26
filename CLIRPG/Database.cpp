#include "pch.h"
#include "Database.h"

tItemDB DB::ItemDB[MAX_DB_ARRAY_SIZE] = {
	{eItemCode::EQUIP_HEADGEAR_BASIC,
	CEquipment(
		eItemCode::EQUIP_HEADGEAR_BASIC,
		eEquipmentType::HEADGEAR,
		"하급 방어구 모자",
		"하급 방어구 모자이다",
		50,
		1,
		10,
		0
	)},
	{eItemCode::EQUIP_ARMOR_BASIC,
	CEquipment(
		eItemCode::EQUIP_ARMOR_BASIC,
		eEquipmentType::ARMOR,
		"하급 방어구 갑옷",
		"하급 방어구 갑옷이다",
		100,
		1,
		20,
		0
	)},
	{eItemCode::EQUIP_WEAPON_BASIC,
	CEquipment(
		eItemCode::EQUIP_WEAPON_BASIC,
		eEquipmentType::WEAPON,
		"하급 무기",
		"하급 무기이다",
		100,
		1,
		0,
		10
	)},


	{eItemCode::CONSUME_PORTION_HP_SMALL,
	CConsumable(
		eItemCode::CONSUME_PORTION_HP_SMALL,
		"소형 HP 포션",
		"HP를 10 회복시킨다",
		3,
		1,
		10
	)},


	{eItemCode::MISC_DROP_EASY,
	CMisc(
		eItemCode::MISC_DROP_EASY,
		"하급 몬스터의 가죽",
		"하급 몬스터에게 드랍되는 아이템이다",
		0,
		5
	)},
	{eItemCode::MISC_DROP_NORMAL,
	CMisc(
		eItemCode::MISC_DROP_NORMAL,
		"중급 몬스터의 가죽",
		"중급 몬스터에게 드랍되는 아이템이다",
		0,
		9
	)},
	{eItemCode::MISC_DROP_HARD,
	CMisc(
		eItemCode::MISC_DROP_HARD,
		"상급 몬스터의 가죽",
		"상급 몬스터에게 드랍되는 아이템이다",
		0,
		13
	)},
};

tMonsterDB DB::MonsterDB[MAX_DB_ARRAY_SIZE] = {
	{eMonsterCode::EASY, CMonster(eMonsterCode::EASY, "초급 몬스터", 30, 30, 5, 10)},
	{eMonsterCode::NORMAL, CMonster(eMonsterCode::NORMAL, "중급 몬스터", 60, 60, 7, 20)},
	{eMonsterCode::HARD, CMonster(eMonsterCode::HARD, "고급 몬스터", 90, 90, 10, 30)},
};

tPlayerClassDB DB::PlayerClassDB[MAX_DB_ARRAY_SIZE] = {
	{ePlayerClassCode::WARRIOR, CPlayer("전사", 150, 150, 5)},
	{ePlayerClassCode::MAGICIAN, CPlayer("마법사", 50, 50, 15)},
	{ePlayerClassCode::THEIF, CPlayer("도적", 100, 100, 10)},
};

tDropItemDB DB::DropItemDB[MAX_DB_ARRAY_SIZE] = {
	{eMonsterCode::EASY, eItemCode::MISC_DROP_EASY, 0.5},
	{eMonsterCode::NORMAL, eItemCode::MISC_DROP_NORMAL, 0.5},
	{eMonsterCode::HARD, eItemCode::MISC_DROP_HARD, 0.5},
};