#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>

// STLs
#include <random>

// Utils
#include "Types.h"
#include "Enum.h"
#include "Memory.h"
#include "Constants.h"

using namespace std;

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