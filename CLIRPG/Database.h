#pragma once

#include "pch.h"
#include "Item.h"
#include "Equipment.h"
#include "Consumable.h"
#include "Misc.h"

map<eItemCode, CItem*> map_ItemDB = {
	{eItemCode::EQUIP_HEADGEAR_BASIC,
	new CEquipment(
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
	new CEquipment(
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
	new CEquipment(
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
	new CConsumable(
		eItemCode::CONSUME_PORTION_HP_SMALL,
		"소형 HP 포션",
		"HP를 10 회복시킨다",
		3,
		1,
		10
	)},

	
};
