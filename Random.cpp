#pragma once
#include "Random.h"

std::mt19937 Random::random(time(0));

int Random::Int(int min, int max)
{
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random);
}