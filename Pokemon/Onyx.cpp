#include "Onyx.h"
#include <time.h>

Onyx::Onyx()
{
	setHealth(10);
	setAttack(10);
	setDefense(20);
	setLevel(1);
	setXP(0);
	setMove1("Rock Throw");
	setMove2("Iron Tail");
	setMove3("Smack Down");
	setMove4("Harden");
	setName("Onyx");
}

void Onyx::resetStats()
{
	setAttack(10 * getLevel());
	setDefense(20 * getLevel());
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Onyx::ironTail(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense();
	double newEnemyHealth = P1.getHealth() - damage;

	return newEnemyHealth;
}

//inflicts damage
//dame is attack / enemy's defense
//33% chance of success
double Onyx::rockThrow(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense();
	srand(time(NULL));
	int random = rand() % 3;
	if (random = 1)
	{
		double newEnemyHealth = P1.getHealth() - damage;

		return newEnemyHealth;
	}
	else return P1.getHealth();
}

//inflicts damage with a 10% chance 
//damage is 2 * attack / enemy's defense
double Onyx::smackDown(Pokemon P1)
{
	double damage = (2 * getAttack()) / P1.getDefense();

	srand(time(NULL));
	int random = rand() % 10;
	if (random = 1)
	{
		double newEnemyHealth = P1.getHealth() - damage;

		return newEnemyHealth;
	}
	else return P1.getHealth();
}

//increases defense by the level for the duration of the fight
void Onyx::harden()
{
	int newDefense = getDefense() + getLevel();
	setDefense(newDefense);
}

