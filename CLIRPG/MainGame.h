#pragma once

#include "pch.h"

class CCharacter;
class CSaveGame;


enum EGameStatus
{
	CHOOSING_CLASS_OR_LOAD,
	ON_MAINMENU,
	ON_FIELD,
	ON_COMBAT,
	QUIT
};


class CMainGame
{
public:
	// 생성자 소멸자
	CMainGame();
	~CMainGame();

	// 기본 함수
	void Initialize();
	void Update(); // 메인 로직
	void Release();

	// Get, Set
	void SetGameStatus(EGameStatus Status);

	// 메인 로직 내 세부 화면들
	// 직업 선택 or 불러오기 화면
	void ChooseClassOrLoad();
	// 메인 화면
	void OnMainMenu();
	// 사냥터 선텍 화면
	void OnField();
	// 전투 화면
	void OnCombat();
	void CombatSingleTurn();
	void RunAway();

	// 출력
	void PrintInfo(CCharacter* _pCharacter);

	// 메모리 해제 함수, 나중에 템플릿 함수를 배우면 통합해서 쓸 수 있을 것 같다
	void SafeDeleteCharacter(CCharacter*& p);
	void SafeDeleteSaveManager(CSaveGame*& p);

private:
	CCharacter* m_pPlayer;
	CCharacter* m_pMonster;

	EGameStatus m_GameStatus;

	CSaveGame* m_pSaveManager;
};