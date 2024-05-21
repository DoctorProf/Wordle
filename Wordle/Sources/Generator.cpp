#include "../Headers/Generator.hpp"

boost::random::mt19937 generator::rng(time(NULL));

int generator::generateNumber(int min, int max) 
{
	boost::random::uniform_real_distribution<> dist(min, max);
	return dist(rng);
}
