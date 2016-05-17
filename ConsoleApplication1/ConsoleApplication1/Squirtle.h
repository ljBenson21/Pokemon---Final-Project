//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#ifndef _SQUIRTLE_
#define _SQUIRTLE_
#include "Pokemon.h"
class Squirtle : public Pokemon
{
public:
	Squirtle();
	//resets attack and defense stats to base for that level
	void resetStats();
	double move1(Pokemon* P1);
	double move2(Pokemon* P1);
	double move3(Pokemon* P1);
	void move4();
	double getTotalHealth() const;
	void levelUp();
	void operator=(const Squirtle C1)
	{
		setHealth(C1.getHealth());
		setAttack(C1.getAttack());
		setDefense(C1.getDefense());
		setXP(C1.getXP());
		setLevel(C1.getLevel());
		setName(C1.getName());
		setMove1(C1.getMove1());
		setMove2(C1.getMove2());
		setMove3(C1.getMove3());
		setMove4(C1.getMove4());

	}
};



#endif


