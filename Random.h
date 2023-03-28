#pragma once
#include <random>

class Random
{
	//All instances share this variable
	static std::mt19937 random;

public:
	static int Int(int min, int max);
};