#pragma once
#include <boost/random.hpp>

namespace generator 
{
	extern boost::random::mt19937 rng;

	int generateNumber(int min, int max);
}