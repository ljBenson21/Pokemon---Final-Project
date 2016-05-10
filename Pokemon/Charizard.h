#ifndef _CHARIZARD_
#define _CHARIZARD_
#include "Pokemon.h"

class Charizard : public Pokemon
{
public:
	Charizard();
	double ember(Pokemon P1);
	double fireFace(Pokemon P1);
	double flameBurst(Pokemon P1);
	void smokescreen();
	void resetStats();
};

#endif