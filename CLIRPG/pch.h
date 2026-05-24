#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <string.h>

using namespace std;

// const 상수
const int MAX_NAME_SIZE = 20;
const char PATH[] = "save.dat";

// 메모리 검사
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#endif //PCH_H