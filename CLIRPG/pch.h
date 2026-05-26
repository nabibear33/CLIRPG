#pragma once

#include <iostream>
#include <string.h>

// STLs
#include <random>

// Utils
#include "Types.h"
#include "Enum.h"

using namespace std;

// constants
const int MAX_NAME_SIZE = 20;
const int MAX_DETAIL_SIZE = 100;
const int MAX_INVENTORY_SIZE = 20;
const int MAX_DB_ARRAY_SIZE = 99;
const char PATH[] = "save.dat";

// Memory Debugging
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif







/*

	virtual void Initialize();
	virtual void Update();
	virtual void Release();


	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;



*/