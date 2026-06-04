#pragma once

#include "pch.h"

template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}

//template<typename T>
//void SafeDeleteArray(T& p, int iSize)
//{
//	for (int i = 0; i < iSize; ++i)
//	{
//		delete p[i];
//		p[i] = nullptr;
//	}
//
//	delete[] p;
//	p = nullptr;
//}