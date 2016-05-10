#ifndef _ONYX_
#define _ONYX_
#include "Pokemon.h"

class Onyx : public Pokemon
{
public: 
	Onyx();
	double rockThrow(Pokemon P1);
	double ironTail(Pokemon P1);
	double smackDown(Pokemon P1);
	void harden();
	void resetStats();
};
#endif
