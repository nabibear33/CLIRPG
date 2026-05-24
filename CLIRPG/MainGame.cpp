#include "pch.h"
#include "MainGame.h"
#include "Character.h"
#include "Player.h"
#include "SaveGame.h"


CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	m_pSaveManager = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// 게임 내내 살아있어야 하는 것만 동적 할당
	m_pSaveManager = new CSaveGame;
	m_GameStatus = CHOOSING_CLASS_OR_LOAD;
}

void CMainGame::Update()
{
	while (m_GameStatus != QUIT)
	{
		switch (m_GameStatus)
		{
		case CHOOSING_CLASS_OR_LOAD:
			ChooseClassOrLoad();
			break;
		case ON_MAINMENU:
			OnMainMenu();
			break;
		case ON_FIELD:
			OnField();
			break;
		case ON_COMBAT:
			OnCombat();
			break;
		default:
			cout << "비정상 종료" << endl;
			return;
		}
	}

	// 종료 버튼을 눌렀을 때 while문 밖으로
}

void CMainGame::Release()
{
	SafeDeleteCharacter(m_pPlayer);
	SafeDeleteCharacter(m_pMonster);
	SafeDeleteSaveManager(m_pSaveManager);
}

void CMainGame::SetGameStatus(EGameStatus Status)
{
	m_GameStatus = Status;
}

void CMainGame::ChooseClassOrLoad()
{
	while (true)
	{
		system("cls");
		cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기" << endl;
		cout << "직업을 선택하세요 : ";

		int iClassSelection(0);
		cin >> iClassSelection;
	
		switch (iClassSelection)
		{
		case 1:
			// 전사 직업으로 동적 할당
			m_pPlayer = new CCharacter("전사", 150, 150, 5);
			m_pPlayer->InitializeClass(iClassSelection);
			SetGameStatus(ON_MAINMENU);
			return;
		case 2:
			// 마법사 직업으로 동적 할당
			m_pPlayer = new CCharacter("마법사", 50, 50, 15);
			m_pPlayer->InitializeClass(iClassSelection);
			SetGameStatus(ON_MAINMENU);
			return;
		case 3:
			// 도적 직업으로 동적 할당
			m_pPlayer = new CCharacter("도적", 100, 100, 10);
			m_pPlayer->InitializeClass(iClassSelection);
			SetGameStatus(ON_MAINMENU);
			return;
		case 4:
			m_pPlayer = new CCharacter;
			m_pSaveManager->Load(m_pPlayer);
			SetGameStatus(ON_MAINMENU);
			return;
		default:
			cout << "유효한 입력값을 입력하세요" << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::OnMainMenu()
{
	while (true)
	{
		system("cls");
		PrintInfo(m_pPlayer);
		cout << "1. 사냥터  2. 저장하기  3. 게임 종료" << endl;
		cout << "선택지를 입력하세요 : ";

		int iMainMenuSelection(0);
		cin >> iMainMenuSelection;

		switch (iMainMenuSelection)
		{
		case 1:
			// 사냥터로 이동
			SetGameStatus(ON_FIELD);
			return;
		case 2:
			// 저장
			m_pSaveManager->Save(m_pPlayer);
			return;
		case 3:
			// 게임 종료
			SetGameStatus(QUIT);
			return;
		default:
			cout << "올바른 선택지를 입력하세요.";
			system("pause");
			break;
		}
	}
}

void CMainGame::OnField()
{
	while (true)
	{
		system("cls");
		PrintInfo(m_pPlayer);
		cout << "1. 초급  2. 중급  3. 고급  4. 돌아가기" << endl;
		cout << "선택지를 입력하세요 : ";

		int iFieldSelection(0);
		cin >> iFieldSelection;

		switch (iFieldSelection)
		{
		case 1:
			m_pMonster = new CCharacter("초급 몬스터", 30, 30, 5);
			SetGameStatus(ON_COMBAT);
			return;
		case 2:
			m_pMonster = new CCharacter("중급 몬스터", 60, 60, 7);
			SetGameStatus(ON_COMBAT);
			return;
		case 3:
			m_pMonster = new CCharacter("고급 몬스터", 90, 90, 10);
			SetGameStatus(ON_COMBAT);
			return;
		case 4:
			SetGameStatus(ON_MAINMENU);
			return;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::OnCombat()
{
	while (true)
	{
		system("cls");

		PrintInfo(m_pPlayer);
		PrintInfo(m_pMonster);

		cout << "1. 공격 2. 도망" << endl;
		cout << "선택지를 입력하세요 : ";

		int iCombatSelection(0);
		cin >> iCombatSelection;

		switch (iCombatSelection)
		{
		case 1:
			// 공격 주고받기
			CombatSingleTurn();
			return;
		case 2:
			// 현재 대치중인 몬스터 메모리 반환 & 필드로 돌아가기
			RunAway();
			return;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::CombatSingleTurn()
{
	// 플레이어 선공
	m_pPlayer->Attack(m_pMonster);
	if (m_pMonster->IsDead())
	{
		system("cls");
		
		PrintInfo(m_pPlayer);
		PrintInfo(m_pMonster);
		
		cout << "승리!" << endl;
		SafeDeleteCharacter(m_pMonster);
		
		system("pause");
		
		SetGameStatus(ON_FIELD);
		return;
	}

	// 몬스터 후공
	m_pMonster->Attack(m_pPlayer);
	if (m_pPlayer->IsDead())
	{
		system("cls");
		
		PrintInfo(m_pPlayer);
		PrintInfo(m_pMonster);
		
		cout << "패배" << endl;
		SafeDeleteCharacter(m_pMonster);
		
		system("pause");

		m_pPlayer->Revive();
		SetGameStatus(ON_FIELD);
		return;
	}
}

void CMainGame::RunAway()
{
	SafeDeleteCharacter(m_pMonster);
	SetGameStatus(ON_FIELD);
}

void CMainGame::PrintInfo(CCharacter* _pCharacter)
{
	if (_pCharacter != nullptr)
	{
		cout << "================================" << endl;
		cout << "이름 : " << _pCharacter->GetName() << endl;
		cout << "체력 : " << _pCharacter->GetHP() << "\t"
			<< "공격력 : " << _pCharacter->GetAttack() << endl;
	}
	else
	{
		cout << "================================" << endl;
		cout << "플레이어(몬스터) 정보가 없습니다" << endl;
	}
}

void CMainGame::SafeDeleteCharacter(CCharacter*& p)
{
	delete p;
	p = nullptr;
}

void CMainGame::SafeDeleteSaveManager(CSaveGame*& p)
{
	delete p;
	p = nullptr;
}
