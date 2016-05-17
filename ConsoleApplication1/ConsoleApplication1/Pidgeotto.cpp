//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

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
	identifier = 3;
}

void Pidgeotto::resetStats()
{
	setAttack(5 + ((getLevel() - 1) * 3));
	setDefense(5 + ((getLevel() - 1) * 1));
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Pidgeotto::move1(Pokemon* P1)
{
	double damage = getAttack() / P1->getDefense();
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;
}

//inflicts damage
//dame is attack / enemy's defense
//33% chance of success
double Pidgeotto::move2(Pokemon* P1)
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
double Pidgeotto::move3(Pokemon* P1)
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

void Pidgeotto::move4()
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

void Pidgeotto::levelUp()
{
	if (getXP() >= (getLevel() * 10))
	{
		setLevel(getLevel() + 1);
		double newHealth = getHealth() + 7;
		setHealth(newHealth);
		int newAttack = getAttack() + 3;
		setAttack(newAttack);
		int newDefense = getDefense() + 1;
		cout << "Pidgeotto is now " << getLevel() << "!" << endl;
	}
}

double Pidgeotto::getTotalHealth() const
{
	double totalHealth = 20 + ((getLevel() - 1) * 7);
	return totalHealth;
}