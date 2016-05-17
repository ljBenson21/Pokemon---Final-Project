//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

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
	identifier = 1;
}

void Charizard::resetStats()
{
	setAttack(15 + ((getLevel() - 1) * 4));
	setDefense(5 + ((getLevel() - 1) * 2));
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Charizard::move1(Pokemon* P1)
{
	double damage = getAttack() / P1->getDefense();
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;
}

//damages enemy by 20%
//100% chance of success
double Charizard::move2(Pokemon* P1)
{
	double newEnemyHealth = P1->getHealth() * 0.8;


	return newEnemyHealth;
}

//inflicts damage with a 10% chance 
//damage is 2 * attack / enemy's defense
double Charizard::move3(Pokemon* P1)
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

//increases defense by level for the duration of the fight
void Charizard::move4()
{
	int newDefense = getDefense() + getLevel();
	setDefense(newDefense);
}

void Charizard::levelUp()
{
	if (getXP() >= (getLevel() * 10))
	{
		setLevel(getLevel() + 1);
		double newHealth = getHealth() + 5;
		setHealth(newHealth);
		int newAttack = getAttack() + 4;
		setAttack(newAttack);
		int newDefense = getDefense() + 2;
		cout << "Charizard is now " << getLevel() << "!" << endl;
	}
}

double Charizard::getTotalHealth() const
{
	double totalHealth = 15 + ((getLevel() - 1) * 5);
	return totalHealth;
}
