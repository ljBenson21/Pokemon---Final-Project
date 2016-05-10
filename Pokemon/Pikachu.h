#ifndef _PIKACHU_
#define _PIKACHU_
#include "Pokemon.h"

class Pikachu : public Pokemon
{
public:
	Pikachu();
	double electroball(Pokemon P1);
	double thunderwave(Pokemon P1);
	double lightScreen(Pokemon P1);
	void powerup();
	void resetStats();
};

#endif
