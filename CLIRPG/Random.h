#pragma once

#include "pch.h"

class CRandom
{
public:
	static double Uniform(double dMin, double dMax)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dis(dMin, dMax);
		return dis(gen);
	}
};