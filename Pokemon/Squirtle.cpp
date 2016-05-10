#include "Squirtle.h"
#include <time.h>

Squirtle::Squirtle()
{
	setHealth(20); 
	setAttack(10);
	setDefense(10);
	setLevel(1);
	setXP(0);
	setMove1("Water Gun");
	setMove2("Hydro Pump");
	setMove3("Waterfall");
	setMove4("Shell");
	setName("Squirtle");
}

void Squirtle::resetStats()
{
	setAttack(10 * getLevel());
	setDefense(10 * getLevel()); 
}

//inflicts damage, 100% chance of successful hit
//damage is squirtle's attack / enemy's attack 
double Squirtle::waterGun(Pokemon P1)
{
	double damage = getAttack() / P1.getDefense(); 
	double newEnemyHealth = P1.getHealth() - damage; 

	return newEnemyHealth; 
}

//restores health by 20% of total health
//increases defense by the level for the duration of the fight (e.g. a level two adds two to the defense stat)
void Squirtle::shell()
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

	//increases the defense by the level
	setDefense(getDefense() + getLevel()); 

}

//increases attack by Squirtle's level for the duration of the fight 
//inflicts damage
//damage is 3 * Squirtle's level / enemy's defense 
double Squirtle::hydroPump(Pokemon P1)
{
	//increases Squirtle's attack by his level for the duration of the fight
	setDefense(getDefense() + getLevel());

	//the amount of damage to be inflicted
	double damage = (3 * getLevel()) / P1.getDefense(); 
	//calculates the new health for the enemy
	double newEnemyHealth = P1.getHealth() - damage;

	return newEnemyHealth; 

}

//Inflicts damage on the enemy
//Damage is Attack * Level / enemy's defense
//attack has a 20% chance  of success
double Squirtle::waterfall(Pokemon P1)
{
	double damage = (getAttack() * getLevel()) / P1.getDefense(); 
	srand(time(NULL));
	int random = rand() % 5;
	if (random = 1)
	{
		double newEnemyHealth = P1.getHealth() - damage;

		return newEnemyHealth; 
	}
	else return P1.getHealth(); 
}

