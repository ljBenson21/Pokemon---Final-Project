//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include "Pokemon.h"




Pokemon::Pokemon()
{
	health = 100;
	attack = 10;
	defense = 10;
	XP = 0;
	level = 1;

}

Pokemon::Pokemon(double h, int a, int d, int x, short int l, string n)
{
	health = h;
	attack = a;
	defense = d;
	XP = x;
	level = l;
	name = n;
}

double Pokemon::getHealth() const
{
	return health;
}

int Pokemon::getAttack() const
{
	return attack;
}

int Pokemon::getDefense() const
{
	return defense;
}

int Pokemon::getXP() const
{
	return XP;
}

short int Pokemon::getLevel() const
{
	return level;
}

string Pokemon::getName() const
{
	return name;
}


string Pokemon::getMove1() const
{
	return this->attack1;
}

string Pokemon::getMove2() const
{
	return this->attack2;
}

string Pokemon::getMove3() const
{
	return this->attack3;
}

string Pokemon::getMove4() const
{
	return this->attack4;
}

void Pokemon::setHealth(double H)
{
	health = H;
}

void Pokemon::setAttack(int A)
{
	attack = A;
}

void Pokemon::setDefense(int D)
{
	defense = D;
}

void Pokemon::setXP(int X)
{
	XP = X;
}

void Pokemon::setLevel(short int L)
{
	level = L;
}

void Pokemon::setName(string N)
{
	name = N;
}

void Pokemon::setMove1(string M1)
{
	this->attack1 = M1;
}

void Pokemon::setMove2(string M2)

{
	this->attack2 = M2;
}

void Pokemon::setMove3(string M3)
{
	this->attack3 = M3;
}

void Pokemon::setMove4(string M4)
{
	this->attack4 = M4;
}




