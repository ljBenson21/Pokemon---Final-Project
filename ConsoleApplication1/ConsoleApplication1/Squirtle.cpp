//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include "Squirtle.h"
#include <time.h>

Squirtle::Squirtle()
{
	setHealth(20);
	setAttack(12);
	setDefense(8);
	setLevel(1);
	setXP(0);
	setMove1("Water Gun");
	setMove2("Hydro Pump");
	setMove3("Waterfall");
	setMove4("Shell");
	setName("Squirtle");
	identifier = 5;
}

void Squirtle::resetStats()
{
	setAttack(10 + ((getLevel() - 1) * 5));
	setDefense(10 + ((getLevel() - 1) * 3));
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Squirtle::move1(Pokemon* P1)
{
	double damage = getAttack() % P1->getDefense();
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;
}

//restores health by 20% of total health
//increases defense by the level for the duration of the fight (e.g. a level two adds two to the defense stat)
void Squirtle::move4()
{
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

//increases attack by Squirtle's level for the duration of the fight 
//inflicts damage
//damage is 3 * Squirtle's level / enemy's defense 
double Squirtle::move2(Pokemon* P1)
{
	//increases Squirtle's attack by his level for the duration of the fight
	setDefense(getDefense() + getLevel());

	//the amount of damage to be inflicted
	double damage = (3 * getLevel()) / P1->getDefense();
	//calculates the new health for the enemy
	double newEnemyHealth = P1->getHealth() - damage;

	return newEnemyHealth;

}

//Inflicts damage on the enemy
//Damage is Attack * Level / enemy's defense
//attack has a 20% chance  of success
double Squirtle::move3(Pokemon* P1)
{
	double damage = (getAttack() * getLevel()) / P1->getDefense();
	srand(time(NULL));
	int random = rand() % 5;
	if (random = 1)
	{
		double newEnemyHealth = P1->getHealth() - damage;

		return newEnemyHealth;
	}
	else return P1->getHealth();
}

void Squirtle::levelUp()
{
	if (getXP() >= (getLevel() * 10))
	{
		setLevel(getLevel() + 1);
		double newHealth = getHealth() + 5;
		setHealth(newHealth);
		int newAttack = getAttack() + 5;
		setAttack(newAttack);
		int newDefense = getDefense() + 3;
		cout << "Squirtle is now " << getLevel() << "!" << endl;
	}
}

double Squirtle::getTotalHealth() const
{
	double totalHealth = 20 + ((getLevel() - 1) * 5);
	return totalHealth;
}