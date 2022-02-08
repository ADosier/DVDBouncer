#ifndef RANDO_H
#define RANDO_H

// ==============================================================
// Name: Alec Dosier
// Date: 5/2021
// Description: A very simple random number generator
// How to use:	- instantiate a Rando obect to seed the RNG with time
//				- call getRand to return a random integer in the interval [start, end]
//
// Note:		- Try to use the same object for all ranges
//					- creating multiple objects in a short amount of time may create
//						duplicate random objects that return the same random sequence
//						if they are created in the same second
// ==============================================================

#include <ctime>
#include <random>

class Rando
{
public:
	Rando();
	int getRand(const int start, const int end);
};

inline Rando::Rando()
{
	srand((unsigned)time(0));
}

inline int Rando::getRand(const int start, const int end)
{
	return start + int(((end+1) - start)*rand() / (RAND_MAX + 1.0));
}

#endif