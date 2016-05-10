#include "Charizard.h"
#include <time.h>

Charizard::Charizard()
{
	setHealth(15);
	setAttack(15);
	setDefense(5);
	setLevel(1);
	setXP(0);
	setMove1("Ember");
	setMove2("Fire Face");
	setMove3("Flame Burst");
	setMove4("Smoke Screen");
	setName("Charizard");
}

void Charizard::resetStats()
{
	setAttack(15 * getLevel());
	setDefense(5 * getLevel());
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Charizard::ember(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense();
	double newEnemyHealth = P1.getHealth() - damage;

	return newEnemyHealth;
}

//damages enemy by 20%
//damages own health by 1
//100% chance of success
double Charizard::fireFace(Pokemon P1)
{
	double newEnemyHealth = P1.getHealth() * 0.8; 
	double newHealth = getHealth() - 1;
	setHealth(newHealth);

	return newEnemyHealth; 
}

//inflicts damage with a 10% chance 
//damage is 2 * attack / enemy's defense
double Charizard::flameBurst(Pokemon P1)
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

//increases defense by level for the duration of the fight
void Charizard::smokescreen()
{
	int newDefense = getDefense() + getLevel();
	setDefense(newDefense); 
}