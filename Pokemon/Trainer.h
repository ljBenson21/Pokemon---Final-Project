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
	vector<Pokemon> caughtPokemon;

public: 
	Trainer();
	string getName();
	int getPokeBalls();
	int getMoney();
	Pokemon getCaughtPokemon(int i);
	void setName(string N);
	void setPokeballs(int P);
	void setMoney(int M);
	void setCaughtPokemon(Pokemon P1);
};

#endif
