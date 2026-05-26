#include "pch.h"
#include "MainGame.h"
#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "SaveGame.h"
#include "Store.h"
#include "Inventory.h"


CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	m_pSaveManager = nullptr;
	m_pStore = nullptr;
	m_eGameStatus = eGameStatus::INTRO;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pSaveManager = new CSaveGame;
	m_pStore = new CStore;
	m_pStore->Initialize();
}

void CMainGame::Update()
{
	if (m_pPlayer)
	{
		m_pSaveManager->Save(m_pPlayer);
	}
	
	while (m_eGameStatus != eGameStatus::QUIT)
	{
		switch (m_eGameStatus)
		{
		case eGameStatus::INTRO:
			OnIntro();
			break;
		case eGameStatus::SELECTING_START_MODE:
			SelectStartMode();
			break;
		case eGameStatus::CHOOSING_CLASS:
			ChooseClass();
			break;
		case eGameStatus::ON_LOBBY:
			OnLobby();
			break;
		case eGameStatus::SELECTING_LEVEL:
			SelectLevel();
			break;
		case eGameStatus::ON_COMBAT:
			OnCombat();
			break;
		case eGameStatus::ON_STORE:
			OnStore();
			break;
		default:
			cout << "비정상 종료" << endl;
			return;
		}
	}
}

void CMainGame::Release()
{
	SafeDeleteSingle(m_pPlayer);
	SafeDeleteSingle(m_pMonster);
	SafeDeleteSingle(m_pStore);
	SafeDeleteSingle(m_pSaveManager);
}

void CMainGame::SetGameStatus(eGameStatus Status)
{
	m_eGameStatus = Status;
}

void CMainGame::OnIntro()
{
	// Add Drawing Logic Later

	// After eGameStatus::INTRO Drawing
	SetGameStatus(eGameStatus::SELECTING_START_MODE);
}

void CMainGame::SelectStartMode()
{
	while (true)
	{
		system("cls");
		cout << "1. 새로시작  2. 불러오기" << endl;
		cout << "선택지를 선택하세요 : ";

		int iStartModeSelection(0);
		cin >> iStartModeSelection;

		switch (iStartModeSelection)
		{
		case 1:
			SetGameStatus(eGameStatus::CHOOSING_CLASS);
			return;
		case 2:
			m_pPlayer = new CPlayer;
			m_pSaveManager->Load(m_pPlayer);
			m_pPlayer->Initialize();
			SetGameStatus(eGameStatus::ON_LOBBY);
			return;
		default:
			cout << "유효한 입력값을 입력하세요" << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::ChooseClass()
{
	while (true)
	{
		system("cls");
		cout << "1. 전사 2. 마법사 3. 도적" << endl;
		cout << "직업을 선택하세요 : ";

		int iClassSelection(0);
		cin >> iClassSelection;

		switch (iClassSelection)
		{
		case 1:
		case 2:
		case 3:
			m_pPlayer = new CPlayer;
			dynamic_cast<CPlayer*>(m_pPlayer)->InitializeClass(iClassSelection);
			m_pPlayer->Initialize();
			SetGameStatus(eGameStatus::ON_LOBBY);
			return;
		default:
			cout << "유효한 입력값을 입력하세요" << endl;
			system("pause");
			continue;
		}
	}
}

void CMainGame::OnLobby()
{
	while (true)
	{
		system("cls");
		m_pPlayer->PrintCharacterInfo();
		cout << "1. 사냥터  2. 상점  3. 게임 종료" << endl;
		cout << "선택지를 입력하세요 : ";

		int iMainMenuSelection(0);
		cin >> iMainMenuSelection;

		switch (iMainMenuSelection)
		{
		case 1:
			SetGameStatus(eGameStatus::SELECTING_LEVEL);
			return;
		case 2:
			SetGameStatus(eGameStatus::ON_STORE);
			return;
		case 3:
			SetGameStatus(eGameStatus::QUIT);
			return;
		default:
			cout << "올바른 선택지를 입력하세요.";
			system("pause");
			break;
		}
	}
}

void CMainGame::SelectLevel()
{
	while (true)
	{
		system("cls");
		m_pPlayer->PrintCharacterInfo();
		cout << "1. 초급  2. 중급  3. 고급  4. 돌아가기" << endl;
		cout << "선택지를 입력하세요 : ";

		int iFieldSelection(0);
		cin >> iFieldSelection;

		switch (iFieldSelection)
		{
		case 1:
			m_pMonster = new CMonster(eMonsterCode::EASY);
			SetGameStatus(eGameStatus::ON_COMBAT);
			return;
		case 2:
			m_pMonster = new CMonster(eMonsterCode::NORMAL);
			SetGameStatus(eGameStatus::ON_COMBAT);
			return;
		case 3:
			m_pMonster = new CMonster(eMonsterCode::HARD);
			SetGameStatus(eGameStatus::ON_COMBAT);
			return;
		case 4:
			SetGameStatus(eGameStatus::ON_LOBBY);
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

		m_pPlayer->PrintCharacterInfo();
		m_pMonster->PrintCharacterInfo();

		cout << "1. 공격 2. 도망" << endl;
		cout << "선택지를 입력하세요 : ";

		int iCombatSelection(0);
		cin >> iCombatSelection;

		switch (iCombatSelection)
		{
		case 1:
			CombatSingleTurn();
			return;
		case 2:
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
	m_pPlayer->Attack(m_pMonster);
	if (m_pMonster->IsDead())
	{
		system("cls");

		m_pPlayer->PrintCharacterInfo();
		m_pMonster->PrintCharacterInfo();

		cout << "승리!" << endl;
		dynamic_cast<CMonster*>(m_pMonster)->OnDead(static_cast<CPlayer*>(m_pPlayer));
		SafeDeleteSingle(m_pMonster);

		system("pause");

		SetGameStatus(eGameStatus::SELECTING_LEVEL);
		return;
	}

	m_pMonster->Attack(m_pPlayer);
	if (m_pPlayer->IsDead())
	{
		system("cls");

		m_pPlayer->PrintCharacterInfo();
		m_pMonster->PrintCharacterInfo();

		cout << "패배" << endl;
		SafeDeleteSingle(m_pMonster);

		system("pause");

		dynamic_cast<CPlayer*>(m_pPlayer)->Revive();
		SetGameStatus(eGameStatus::SELECTING_LEVEL);
		return;
	}
}

void CMainGame::RunAway()
{
	SafeDeleteSingle(m_pMonster);
	SetGameStatus(eGameStatus::SELECTING_LEVEL);
}

void CMainGame::OnStore()
{
	m_pStore->SetPlayer(static_cast<CPlayer*>(m_pPlayer));
	m_pStore->Update();
	m_eGameStatus = eGameStatus::ON_LOBBY;
}