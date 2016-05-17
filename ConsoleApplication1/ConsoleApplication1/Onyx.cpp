//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include "Onyx.h"
#include <time.h>

Onyx::Onyx()
{
	setHealth(20);
	setAttack(5);
	setDefense(20);
	setLevel(1);
	setXP(0);
	setMove1("Rock Throw");
	setMove2("Iron Tail");
	setMove3("Smack Down");
	setMove4("Harden");
	setName("Onyx");
	identifier = 2;
}

void Onyx::resetStats()
{
	setAttack(5 + ((getLevel() - 1) * 1));
	setDefense(20 + ((getLevel() - 1) * 5));
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Onyx::move1(Pokemon* P1)
{
	double damage = getAttack() / P1->getDefense();
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;
}

//inflicts damage
//dame is attack / enemy's defense
//33% chance of success
double Onyx::move2(Pokemon* P1)
{
	double damage = getAttack() / P1->getDefense();
	srand(time(NULL));
	int random = rand() % 3;
	if (random = 1)
	{
		double newEnemyHealth = P1->getHealth() - damage;

		return newEnemyHealth;
	}
	else return P1->getHealth();
}

//inflicts damage with a 10% chance 
//damage is 2 * attack / enemy's defense
double Onyx::move3(Pokemon* P1)
{
	double damage = (2 * getAttack()) / P1->getDefense();

	srand(time(NULL));
	int random = rand() % 10;
	if (random = 1)
	{
		double newEnemyHealth = P1->getHealth() - damage;

		return newEnemyHealth;
	}
	else return P1->getHealth();
}

//increases defense by the level for the duration of the fight
void Onyx::move4()
{
	int newDefense = getDefense() + getLevel();
	setDefense(newDefense);
}

void Onyx::levelUp()
{
	if (getXP() >= (getLevel() * 10))
	{
		setLevel(getLevel() + 1);
		double newHealth = getHealth() + 10;
		setHealth(newHealth);
		int newAttack = getAttack() + 1;
		setAttack(newAttack);
		int newDefense = getDefense() + 5;
		cout << "Onyx is now " << getLevel() << "!" << endl;
	}
}

double Onyx::getTotalHealth() const
{
	double totalHealth = 20 + ((getLevel() - 1) * 10);
	return totalHealth;
}

