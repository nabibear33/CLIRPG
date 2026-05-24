#include "pch.h"
#include "MainGame.h"


int main()
{
	// 메모리 관리 디버그 코드
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CMainGame MainGame;
	MainGame.Initialize();
	MainGame.Update();
}