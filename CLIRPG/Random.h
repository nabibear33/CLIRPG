#pragma once

#include "pch.h"

class CRandom
{
public:
	static double UniformReal(double dMin, double dMax)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dis(dMin, dMax);
		return dis(gen);
	}

	static int UniformInt(int iMin, int iMax)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(iMin, iMax);
		return dis(gen);
	}
};