#include "Trainer.h"

Trainer::Trainer()
{
	name = " ";
	pokeballs = 6;
	money = 100;
}

string Trainer::getName()
{
	return name;
}

int Trainer::getPokeBalls()
{
	return pokeballs;
}

int Trainer::getMoney()
{
	return money;
}

Pokemon Trainer::getCaughtPokemon(int i)
{
	return caughtPokemon.at(i); 
}

void Trainer::setName(string n)
{
	name = n; 
}

void Trainer::setPokeballs(int P)
{
	pokeballs = P;
}

void Trainer::setMoney(int M)
{
	money = M;
}

void Trainer::setCaughtPokemon(Pokemon P1)
{
	caughtPokemon.push_back(P1); 
}

