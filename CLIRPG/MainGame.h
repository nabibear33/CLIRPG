#pragma once

#include "pch.h"
#include "Memory.h"


class CCharacter;
class CSaveGame;
class CStore;


class CMainGame
{
public:
	CMainGame();
	~CMainGame();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

	// Getter, Setter
	void SetGameStatus(eGameStatus Status);

	// eGameStatus : INTRO
	// not yet
	void OnIntro();

	// eGameStatus : SELECTING_START_MODE
	void SelectStartMode();
	
	// eGameStatus : CHOOSING_CLASS
	void ChooseClass();
	

	// eGameStatus : ON_MAINMENU
	void OnLobby();

	// eGameStatus : SELECTING_LEVEL
	void OnField();

	// eGameStatus : ON_COMBAT
	void OnCombat();
	void CombatSingleTurn();
	void RunAway();

	// eGameStatus : ON_STORE
	void OnStore();

private:
	// Global State
	eGameStatus m_eGameStatus;
	
	// Logics
	CSaveGame* m_pSaveManager;
	CStore* m_pStore;

	// Characters
	CCharacter* m_pPlayer;
	CCharacter* m_pMonster;

};