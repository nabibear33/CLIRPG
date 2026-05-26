#pragma once

class CEnum
{
public:
	template<typename T>
	static const char* EnumToString(T Enum) { return ""; }

	template<>
	static const char* EnumToString<eItemType>(eItemType Enum)
	{
		switch (Enum)
		{
		case eItemType::EQUIPMENT: return "장비";
		case eItemType::CONSUMABLE: return "소비";
		case eItemType::MISC: return "기타";
		default: return "";
		}
	}

	template<>
	static const char* EnumToString<eEquipmentType>(eEquipmentType Enum)
	{
		switch (Enum)
		{
		case eEquipmentType::HEADGEAR: return "모자";
		case eEquipmentType::ARMOR: return "방어구";
		case eEquipmentType::WEAPON: return "무기";
		default: return "";
		}
	}

};
