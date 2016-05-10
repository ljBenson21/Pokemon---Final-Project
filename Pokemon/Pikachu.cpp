#include "Pikachu.h"
#include <time.h>

Pikachu::Pikachu()
{
	setHealth(15);
	setAttack(15);
	setDefense(5);
	setLevel(1);
	setXP(0);
	setMove1("Electro Ball");
	setMove2("Thunder Wave");
	setMove3("Light Screen");
	setMove4("Power Up");
	setName("Pikachu");
}

void Pikachu::resetStats()
{
	setAttack(15 * getLevel());
	setDefense(5 * getLevel());
}

double Pikachu::electroball(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense();
	double newEnemyHealth = P1.getHealth() - damage;

	return newEnemyHealth;
}

double Pikachu::thunderwave(Pokemon P1)
{
	//25 * getLevel() is the maximum health of the pikachu
	int healthCapacity = 15 * getLevel();
	//bonus is the level
	double bonus = getLevel();
	//newHealth is the current health + the level of the health capacity 
	double newHealth = getHealth() + bonus;

	//if the new health does not exceed the capacity, changes the health
	if (newHealth <= (15 * getLevel()))
	{
		setHealth(newHealth);
	}
	//if the new health exceeds the capacity, sets the health to the capacity
	else setHealth(15 * getLevel());

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
double Pikachu::lightScreen(Pokemon P1)
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

//increases attack and defense by the level
//restores 20% of the health
void Pikachu::powerup()
{
	//increases defense and attack by the level
	setDefense(getDefense() + getLevel());
	setAttack(getAttack() + getLevel());

	//20 * getLevel() is the maximum health of the squirtle
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

