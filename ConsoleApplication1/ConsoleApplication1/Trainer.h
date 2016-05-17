//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#ifndef _TRAINER_
#define _TRAINER_
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std;

class Trainer
{
private:
	string name;
	int pokeballs;
	int money;
	int healthRegenerate;

public:
	void setHealthRegen(int x);
	void useHealthRegen(Pokemon* P1);
	int gethealthRegen() const;
	Pokemon* caughtPokemon[3];
	Trainer();
	string getName() const;
	int getPokeBalls() const;
	int getMoney() const;
	void setName(string N);
	void setPokeballs(int P);
	void setMoney(int M);




};

#endif

