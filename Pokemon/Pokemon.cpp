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
	return move1;
}

string Pokemon::getMove2() const
{
	return move2;
}

string Pokemon::getMove3() const
{
	return move3;
}

string Pokemon::getMove4() const
{
	return move4; 
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
	move1 = M1;
}

void Pokemon::setMove2(string M2)

{
	move2 = M2;
}

void Pokemon::setMove3(string M3)
{
	move3 = M3;
}

void Pokemon::setMove4(string M4)
{
	move4 = M4; 
}
void Pokemon::faint()
{
	if (health <= 0)
	{
		cout << name << "has fainted! " << endl;
	}
}

void Pokemon::levelUp()
{
	if (XP >= level * 10)
	{
		level++;
	}
}


