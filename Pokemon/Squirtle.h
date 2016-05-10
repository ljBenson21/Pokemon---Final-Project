#ifndef _SQUIRTLE_
#define _SQUIRTLE_
#include "Pokemon.h"
class Squirtle : public Pokemon
{
public: 
	Squirtle();
	//resets attack and defense stats to base for that level
	void resetStats(); 
	double waterGun(Pokemon P1);
	double hydroPump(Pokemon P1);
	double waterfall(Pokemon P1);
	void shell();
};



#endif

