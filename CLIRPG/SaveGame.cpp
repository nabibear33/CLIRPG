#include "pch.h"
#include "SaveGame.h"
#include "Player.h"
#include "Inventory.h"
#include "Equipment.h"
#include "EquipItem.h"
#include "Item.h"

CSaveGame::CSaveGame()
{
}

CSaveGame::~CSaveGame()
{

}

void CSaveGame::Initialize()
{
}

void CSaveGame::Update()
{
}

void CSaveGame::Release()
{
}

void CSaveGame::Save(CPlayer* pPlayer)
{
	// 파일로 저장
	FILE* SaveFile;
	errno_t err = fopen_s(&SaveFile, PATH, "wb");
	if (err == 0)
	{
		tagSaveData tTmpSaveData = GetSaveData(pPlayer);
		fwrite(&tTmpSaveData, sizeof(tagSaveData), 1, SaveFile);
		fclose(SaveFile);
		cout << "저장 완료" << endl;
		system("pause");
	}
	else
	{
		cout << "스트림 개방 실패" << endl;
		system("pause");
	}
}

tagSaveData CSaveGame::GetSaveData(CPlayer* pPlayer)
{
	tagSaveData tTmpSaveData;

	strcpy_s(tTmpSaveData.szName, sizeof(MAX_NAME_SIZE), pPlayer->GetName());
	tTmpSaveData.iAttack = pPlayer->GetAttack();
	tTmpSaveData.iHP = pPlayer->GetHP();
	tTmpSaveData.iMaxHP = pPlayer->GetMaxHP();
	tTmpSaveData.ePlayerClassType = pPlayer->GetPlayerClassCode();


	tTmpSaveData.iInventoryGold = pPlayer->GetInventory()->GetCurrentGold();
	tTmpSaveData.iInventorySize = pPlayer->GetInventory()->GetItems().size();
	for (size_t i = 0; i < tTmpSaveData.iInventorySize; ++i)
	{
		tTmpSaveData.vecInventory[i] = pPlayer->GetInventory()->GetItems()[i]->GetItemCode();
	}

	tTmpSaveData.iEquipmentSize = pPlayer->GetEquipment()->GetEquipSlot().size();
	for (size_t i = 0; i < tTmpSaveData.iEquipmentSize; ++i)
	{
		tTmpSaveData.mapEquipmentKey[i] = static_cast<eEquipmentType>(i);
		tTmpSaveData.mapEquipmentValue[i] = pPlayer->GetEquipment()->GetEquipSlot()[static_cast<eEquipmentType>(i)]->GetItemCode();
	}

	return tTmpSaveData;
}

void CSaveGame::Load(CPlayer*& pPlayer)
{
	// 파일 불러오기
	FILE* LoadFile;
	errno_t err = fopen_s(&LoadFile, PATH, "rb");
	if (err == 0)
	{
		tagSaveData tagTmpSaveData;
		fread(&tagTmpSaveData, sizeof(tagSaveData), 1, LoadFile);
		LoadSaveData(tagTmpSaveData, pPlayer);
		fclose(LoadFile);
	}
	else
	{
		cout << "스트림 개방 실패" << endl;
		system("pause");
	}
}

void CSaveGame::LoadSaveData(tagSaveData& tSaveData, CPlayer*& pPlayer)
{
	pPlayer->Initialize();
	pPlayer->LoadSaveData(tSaveData);
}
