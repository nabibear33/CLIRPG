#include "pch.h"
#include "SaveGame.h"
#include "Character.h"


CSaveGame::CSaveGame()
{
}

CSaveGame::~CSaveGame()
{

}

void CSaveGame::Save(CCharacter* pPlayer)
{
	// 파일로 저장
	FILE* SaveFile;
	errno_t err = fopen_s(&SaveFile, PATH, "wb");
	if (err == 0)
	{
		fwrite(pPlayer, sizeof(CCharacter), 1, SaveFile);
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

void CSaveGame::Load(CCharacter*& pPlayer)
{
	// 파일 불러오기
	FILE* LoadFile;
	errno_t err = fopen_s(&LoadFile, PATH, "rb");
	if (err == 0)
	{
		fread(pPlayer, sizeof(CCharacter), 1, LoadFile);
		fclose(LoadFile);
	}
	else
	{
		cout << "스트림 개방 실패" << endl;
		system("pause");
	}
}
