#include "Pidgeotto.h"
#include <time.h>

Pidgeotto::Pidgeotto()
{
	setHealth(20);
	setAttack(5);
	setDefense(5);
	setLevel(1);
	setXP(0);
	setMove1("Gust");
	setMove2("Tailwind");
	setMove3("Whirlwind");
	setMove4("Hover");
	setName("Pidgeotto");
}

void Pidgeotto::resetStats()
{
		setAttack(5 * getLevel());
		setDefense(5 * getLevel());
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Pidgeotto::gust(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense();
	double newEnemyHealth = P1.getHealth() - damage;

	return newEnemyHealth;
}

//inflicts damage
//dame is attack / enemy's defense
//33% chance of success
double Pidgeotto::tailwind(Pokemon P1)
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
double Pidgeotto::whirlwind(Pokemon P1)
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

void Pidgeotto::hover()
{
	//20 * getLevel() is the maximum health of the pidgeotto
	int healthCapacity = 20 * getLevel();
	//bonus is 20% of the health capacity
	double bonus = healthCapacity * 0.2;
	//newHealth is the current health + 20% of the health capacity 
	double newHealth = getHealth() + bonus;

	//if the new health does not exceed the capacity, changes the health
	if (newHealth <= (20 * getLevel()))
	{
		setHealth(newHealth);
	}
	//if the new health exceeds the capacity, sets the health to the capacity
	else setHealth(20 * getLevel());

}