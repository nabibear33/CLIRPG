#pragma once

#include "pch.h"

template<class T>
void SafeDeleteSingle(T* p)
{
	delete p;
	p = nullptr;
}

template<class T>
void SafeDeleteArray(T* p, int iSize)
{
	for (int i = 0; i < iSize; ++i)
	{
		delete p[i];
		p[i] = nullptr;
	}

	delete[] p;
	p = nullptr;
}

