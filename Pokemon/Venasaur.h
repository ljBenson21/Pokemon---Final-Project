#ifndef _VENASUAR_
#define _VENASUAR_
#include "Pokemon.h"

class Venasaur : public Pokemon
{
public:
	Venasaur();
	double vineWhip(Pokemon P1);
	double razorLeaf(Pokemon P1);
	void petalDance();
	void reGrow(); 
	void resetStats(); 

};

#endif
