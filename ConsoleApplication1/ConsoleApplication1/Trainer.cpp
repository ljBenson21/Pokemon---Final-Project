//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include "Trainer.h"
#include <time.h>

Trainer::Trainer()
{
	name = " ";
	pokeballs = 6;
	money = 100;
	healthRegenerate = 3;
}

string Trainer::getName() const
{
	return name;
}

int Trainer::getPokeBalls() const
{
	return pokeballs;
}

int Trainer::getMoney() const
{
	return money;
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

void Trainer::setHealthRegen(int x)
{
	healthRegenerate = x;
}
int Trainer::gethealthRegen() const
{
	return healthRegenerate;
}

void Trainer::useHealthRegen(Pokemon* P1)
{
	P1->setHealth(P1->getTotalHealth());
}

