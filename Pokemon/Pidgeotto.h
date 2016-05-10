#ifndef _PIDGEOTTO_
#define _PIDGEOTTO_
#include "Pokemon.h"

class Pidgeotto : public Pokemon
{
public:
	Pidgeotto();
	double gust(Pokemon P1);
	double tailwind(Pokemon P1);
	double whirlwind(Pokemon P1);
	void hover();
	void resetStats();

};
#endif
