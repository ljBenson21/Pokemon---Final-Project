//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include "Venasaur.h"
#include <time.h>

Venasaur::Venasaur()
{
	setHealth(25);
	setAttack(5);
	setDefense(5);
	setLevel(1);
	setXP(0);
	setMove1("Vine Whip");
	setMove2("Razor Leaf");
	setMove3("Petal Dance");
	setMove4("ReGrow");
	setName("Venasaur");
	identifier = 6;
}

void Venasaur::resetStats()
{
	setAttack(5 + ((getLevel() - 1) * 3));
	setDefense(5 + ((getLevel() - 1) * 5));
}

//inflicts damage, 100% chance of successful hit
//damage is attack / enemy's attack 
double Venasaur::move1(Pokemon* P1)
{
	double damage = getAttack() / P1->getDefense();
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;
}

void Venasaur::move4()
{
	//25 * getLevel() is the maximum health of the squirtle
	int healthCapacity = 25 * getLevel();
	//bonus is 20% of the health capacity
	double bonus = healthCapacity * 0.2;
	//newHealth is the current health + 20% of the health capacity 
	double newHealth = getHealth() + bonus;

	//if the new health does not exceed the capacity, changes the health
	if (newHealth <= (25 * getLevel()))
	{
		setHealth(newHealth);
	}
	//if the new health exceeds the capacity, sets the health to the capacity
	else setHealth(25 * getLevel());
}

//Inflicts damage on the enemy
//restores health by the level
//Damage is Attack  / enemy's defense
//attack has a 30% chance  of success
double Venasaur::move2(Pokemon* P1)
{
	//25 * getLevel() is the maximum health of the venasaur
	int healthCapacity = 25 * getLevel();
	//bonus is the level
	double bonus = getLevel();
	//newHealth is the current health + 30% of the health capacity 
	double newHealth = getHealth() + bonus;

	//if the new health does not exceed the capacity, changes the health
	if (newHealth <= (25 * getLevel()))
	{
		setHealth(newHealth);
	}
	//if the new health exceeds the capacity, sets the health to the capacity
	else setHealth(25 * getLevel());

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

double Venasaur::move3(Pokemon* P1)
{
	double newHealth = P1->getHealth() - 2;
	srand(time(NULL));
	int random = rand() % 200;
	if (random = 1)
	{
		//25 * getLevel() is the maximum health of the venasaur
		int healthCapacity = 25 * getLevel();
		//bonus is the level
		double bonus = 5 * getLevel();
		//newHealth is the current health + 30% of the health capacity 
		double newHealth = getHealth() + bonus;

		//if the new health does not exceed the capacity, changes the health
		if (newHealth <= (25 * getLevel()))
		{
			setHealth(newHealth);
		}
		//if the new health exceeds the capacity, sets the health to the capacity
		else setHealth(25 * getLevel());
	}
	return newHealth;
}

void Venasaur::levelUp()
{
	if (getXP() >= (getLevel() * 10))
	{
		setLevel(getLevel() + 1);
		double newHealth = getHealth() + 4;
		setHealth(newHealth);
		int newAttack = getAttack() + 3;
		setAttack(newAttack);
		int newDefense = getDefense() + 5;
		cout << "Venasuar is now " << getLevel() << "!" << endl;
	}
}

double Venasaur::getTotalHealth() const
{
	double totalHealth = 25 + ((getLevel() - 1) * 4);
	return totalHealth;
}