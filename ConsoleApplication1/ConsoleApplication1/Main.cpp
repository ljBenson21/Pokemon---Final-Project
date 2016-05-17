//////////////////////////////////////////
//Pokemon
//Brady Simmelink, LJ Benson, Vince Porporato
//Final Project
//5-17-16
///////////////////////////////////////////

#include <iostream>
#include "Pokemon.h"
#include "Squirtle.h"
#include "Venasaur.h"
#include "Pidgeotto.h"
#include "Pikachu.h"
#include "Charizard.h"
#include "Onyx.h"
#include "Trainer.h"
#include <windows.h>
#include <time.h>
#include <fstream> 

using namespace std;

//saves characters aTttributes
void saveAttributes(Trainer user, Pokemon* P1, Pokemon* P2, Pokemon* P3);
//walks through a battle between the user's current pokemon and an enemy pokemon
void fightPokemon(Pokemon* &usersPoke, Pokemon* &enemyPoke, Trainer &user);
//checks if the pokemons health is <= 0
bool faint(Pokemon* P1);
//used to clear the screen after battle sequences
//or at other points when the screen has been filled with text
void clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}


int main()
{
	//Creates a Trainer with level 5 charizard, pikachu, and pidgeotto
	//used as the find "Boss"
	//option 5 on the menu
	Trainer gymLeader;
	Charizard gymPoke1;
	Pokemon* G1 = new Charizard;
	G1 = &gymPoke1;
	gymPoke1.setAttack(30);
	gymPoke1.setDefense(15);
	gymPoke1.setHealth(30);
	gymLeader.caughtPokemon[0] = G1;
	Pikachu gymPoke2;
	Pokemon* G2 = new Pikachu;
	G2 = &gymPoke2;
	gymPoke2.setAttack(30);
	gymPoke2.setDefense(20);
	gymPoke2.setHealth(30);
	gymLeader.caughtPokemon[1] = G2;
	Pidgeotto gymPoke3;
	Pokemon* G3 = new Pidgeotto;
	G3 = &gymPoke3;
	gymPoke3.setAttack(10);
	gymPoke3.setDefense(10);
	gymPoke3.setHealth(30);
	gymLeader.caughtPokemon[2] = G3;


	Trainer user;
	//allows the user to input his/her name
	string name;
	cout << "What is your trainer's name? ";
	getline(cin, name);
	user.setName(name);

	//creates one of each type of pokemon
	//the user selects which one they wish to begin with
	//that type is stored in the caughtPokemon array
	Squirtle S1;
	Venasaur V1;
	Pidgeotto p1;
	Pikachu Pika1;
	Charizard C1;
	Onyx O1;
	//displays the options for which pokemon to begin with
	//inputs that choice
	int choice;
	cout << "Which Pokemon would you like to start with? " << endl;
	cout << "1. Squirtle (enter 1)" << endl;
	cout << "2. Venasaur (enter 2)" << endl;
	cout << "3. Pidgeotto (enter 3)" << endl;
	cout << "4. Pikachu (enter 4)" << endl;
	cout << "5. Charizard (enter 5)" << endl;
	cout << "6. Onyx (enter 6)" << endl;
	cin >> choice;

	//if they choose 1, the first pokemon in the caught pokemon array is squirtle
	if (choice == 1)
	{
		Pokemon* P1 = new Squirtle;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << S1;
	}
	//if they choose 2, the first pokemon in the caught pokemon array is Venasaur		
	else if (choice == 2)
	{
		Pokemon* P1 = new Venasaur;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << V1;
	}
	//if they choose 3, the first pokemon in the caught pokemon array is Pidgeotto
	else if (choice == 3)
	{
		Pokemon* P1 = new Pidgeotto;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << p1;
	}
	//if they choose 4, the first pokemon in the caught pokemon array is Pikachu
	else if (choice == 4)
	{
		Pokemon* P1 = new Pikachu;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << Pika1;
	}
	//if they choose 5, the first pokemon in the caught pokemon array is Charizard
	else if (choice == 5)
	{
		Pokemon* P1 = new Charizard;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << C1;
	}
	//if they choose 6, the first pokemon in the caught pokemon array is Onyx
	else if (choice == 6)
	{
		Pokemon* P1 = new Onyx;
		user.caughtPokemon[0] = P1;
		cout << "Great Choice " << user.getName() << "! you chose " << P1->getName() << "!" << endl;
		cout << endl;
		cout << O1;
	}
	cout << endl;
	cout << "Choose again! " << endl;

	//creates one of each type of pokemon
	//the user selects which one they wish to begin with
	//that type is pushed back into the vector of their captured pokemon
	Squirtle S2;
	Venasaur V2;
	Pidgeotto p2;
	Pikachu Pika2;
	Charizard C2;
	Onyx O2;
	//displays the options for which pokemon to begin with
	//inputs that choice
	int choice1;
	cout << "Which Pokemon would you like to start with? " << endl;
	cout << "1. Squirtle (enter 1)" << endl;
	cout << "2. Venasaur (enter 2)" << endl;
	cout << "3. Pidgeotto (enter 3)" << endl;
	cout << "4. Pikachu (enter 4)" << endl;
	cout << "5. Charizard (enter 5)" << endl;
	cout << "6. Onyx (enter 6)" << endl;
	cin >> choice1;

	//if they choose 1, the second pokemon in the caught pokemon array is squirtle
	if (choice1 == 1)
	{
		Pokemon* P2 = new Squirtle;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << S2;
	}
	//if they choose 2, the second pokemon in the caught pokemon array is Venasaur		
	else if (choice1 == 2)
	{
		Pokemon* P2 = new Venasaur;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << V2;
	}
	//if they choose 3, the second pokemon in the caught pokemon array is Pidgeotto
	else if (choice1 == 3)
	{
		Pokemon* P2 = new Pidgeotto;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << p2;
	}
	//if they choose 4, the second pokemon in the caught pokemon array is Pikachu
	else if (choice1 == 4)
	{
		Pokemon* P2 = new Pikachu;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << Pika2;
	}
	//if they choose 5, the second pokemon in the caught pokemon array is Charizard
	else if (choice1 == 5)
	{
		Pokemon* P2 = new Charizard;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << C2;
	}
	//if they choose 6, the second pokemon in the caught pokemon array is Onyx
	else if (choice1 == 6)
	{
		Pokemon* P2 = new Onyx;
		user.caughtPokemon[1] = P2;
		cout << "Great Choice " << user.getName() << "! you chose " << P2->getName() << "!" << endl;
		cout << endl;
		cout << O2;
	}
	cout << endl;
	cout << "Choose again! " << endl;
	//creates one of each type of pokemon
	//the user selects which one they wish to begin with

	Squirtle S3;
	Venasaur V3;
	Pidgeotto p3;
	Pikachu Pika3;
	Charizard C3;
	Onyx O3;
	//displays the options for which pokemon to begin with
	//inputs that choice
	int choice2;
	cout << "Which Pokemon would you like to start with? " << endl;
	cout << "1. Squirtle (enter 1)" << endl;
	cout << "2. Venasaur (enter 2)" << endl;
	cout << "3. Pidgeotto (enter 3)" << endl;
	cout << "4. Pikachu (enter 4)" << endl;
	cout << "5. Charizard (enter 5)" << endl;
	cout << "6. Onyx (enter 6)" << endl;
	cin >> choice2;

	//if they choose 1, the third pokemon in the caught pokemon array is squirtle
	if (choice2 == 1)
	{
		Pokemon* P3 = new Squirtle;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << S3;
	}

	//if they choose 2, the third pokemon in the caught pokemon array is Venasaur		
	else if (choice2 == 2)
	{
		Pokemon* P3 = new Venasaur;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << V3;
	}
	//if they choose 3, the third pokemon in the caught pokemon array is Pidgeotto
	else if (choice2 == 3)
	{
		Pokemon* P3 = new Pidgeotto;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << p3;
	}

	//if they choose 4, the third pokemon in the caught pokemon array is Pikachu
	else if (choice2 == 4)
	{
		Pokemon* P3 = new Pikachu;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << Pika3;
	}

	//if they choose 5, the third pokemon in the caught pokemon array is Charizard
	else if (choice2 == 5)
	{
		Pokemon* P3 = new Charizard;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << C3;
	}

	//if they choose 6, the third pokemon in the caught pokemon array is Onyx
	else if (choice2 == 6)
	{
		Pokemon* P3 = new Onyx;
		user.caughtPokemon[2] = P3;
		cout << "Great Choice " << user.getName() << "! you chose " << P3->getName() << "!" << endl;
		cout << endl;
		cout << O3;
	}
	cout << endl;
	//displays the amount of money they have
	cout << "Money: " << user.getMoney() << endl;
	cout << endl;

	//the user selects if they wish to walk along the grass
	//or continue along the path
	//walking through the grass will force a battle with a wild pokemon
	//coninuing along the path will force a battle with another trainer

	cout << "It's time to start your journey! " << endl;
	bool gymLeaderDead = false;
	while (gymLeaderDead == false)
	{
		int choice3;
		cout << "What would you like to do? " << endl;
		cout << "1. Walk through the grass (Enter 1)" << endl;
		cout << "2. Continue along the path (Enter 2)" << endl;
		cout << "3. Use a health regenerate! (Enter 3)" << user.gethealthRegen() << " Remaining" << endl;
		cout << "4. Go to PokeShop (Enter 4)" << endl;
		cout << "5. Fight Gym Leader! (Enter 5)" << endl;
		cout << "6. Save Pokemon's Stats (Enter 6)" << endl;
		cout << "7. Peek at Pokemon Stats (Enter 7" << endl;
		cin >> choice3;
		clear_screen();

		//creates a random pokemon to be used in the fightPokemon function for choice 1
		srand(time(NULL));
		int random = rand() % 6;
		Pokemon* enemyPoke;
		if (random == 0)
		{
			enemyPoke = new Squirtle;
		}
		else if (random == 1)
		{
			enemyPoke = new Venasaur;
		}
		else if (random == 2)
		{
			enemyPoke = new Pidgeotto;
		}
		else if (random == 3)
		{
			enemyPoke = new Pikachu;
		}
		else if (random == 4)
		{
			enemyPoke = new Charizard;
		}
		else if (random == 5)
		{
			enemyPoke = new Onyx;
		}

		//randomly selects a trainer to be used in case 3;
		Trainer enemy;
		Pokemon* Epoke1;
		Pokemon* Epoke2;
		Pokemon* Epoke3;
		srand(time(NULL));
		int random1 = rand() % 3;
		if (random1 == 0)
		{
			Epoke1 = new Pidgeotto;
			Epoke2 = new Onyx;
			Epoke3 = new Pikachu;
			enemy.setName("Kurt");
			enemy.caughtPokemon[0] = Epoke1;
			enemy.caughtPokemon[1] = Epoke2;
			enemy.caughtPokemon[2] = Epoke3;
		}
		else if (random == 1)
		{
			Epoke1 = new Charizard;
			Epoke2 = new Venasaur;
			Epoke3 = new Onyx;
			enemy.setName("Jess");
			enemy.caughtPokemon[0] = Epoke1;
			enemy.caughtPokemon[1] = Epoke2;
			enemy.caughtPokemon[2] = Epoke3;
		}
		else
		{
			Epoke1 = new Pidgeotto;
			Epoke2 = new Pidgeotto;
			Epoke3 = new Pidgeotto;
			enemy.setName("Lauren");
			enemy.caughtPokemon[0] = Epoke1;
			enemy.caughtPokemon[1] = Epoke2;
			enemy.caughtPokemon[2] = Epoke3;
		}

		//used for case 2 and case 5, for moving to the next pokemon after fainting
		int i = 0;
		int j = 0;

		//uses the users choice 
		switch (choice3)
		{
		case 1:
			cout << "You chose to walk through the grass! " << endl;
			//battle between user pokemon and random enemy pokemon
			fightPokemon(user.caughtPokemon[0], enemyPoke, user);
			//if user pokemon faints, advances to next pokemon
			if (user.caughtPokemon[0]->getHealth() <= 0)
			{
				fightPokemon(user.caughtPokemon[1], enemyPoke, user);
			}
			//if user pokemon faints, advances to next pokemon
			if (user.caughtPokemon[1]->getHealth() <= 0)
			{
				fightPokemon(user.caughtPokemon[2], enemyPoke, user);
			}
			//if user pokemon faints, advances to next pokemon
			if (user.caughtPokemon[2]->getHealth() <= 0)
			{
				cout << "All pokemon have Fainted, go to the store to revive! " << endl;
			}
			break;
		case 2:
			cout << "You chose to walk along the path! " << endl;
			cout << "Oh No! " << enemy.getName() << " showed up!" << endl;
			cout << "They want to fight! " << endl;
			while (i < 3 && j < 3)
			{
				//battle between user pokemon and enemy trainer's pokemon
				fightPokemon(user.caughtPokemon[i], enemy.caughtPokemon[j], user);
				//if user pokemon faints, advances to next pokemon, until all have been used
				if (user.caughtPokemon[i]->getHealth() <= 0)
				{
					i++;
					cout << "You use " << user.caughtPokemon[i]->getName() << "!" << endl;
				}
				//if enemy pokemon faints, advances to next pokemon, until all have been used
				if (enemy.caughtPokemon[j]->getHealth() <= 0)
				{
					j++;
				}
			}

			break;

		case 3:
			cout << "Who would you like to regenerate?" << endl;
			//displays the pokemon and health if health is not full
			if (user.caughtPokemon[0]->getHealth() < user.caughtPokemon[0]->getTotalHealth())
			{
				cout << user.caughtPokemon[0]->getName() << " Health: " << user.caughtPokemon[0]->getHealth() << " (enter 1)" << endl;
			}
			//displays the pokemon and health if health is not full
			if (user.caughtPokemon[1]->getHealth() < user.caughtPokemon[1]->getTotalHealth())
			{
				cout << user.caughtPokemon[1]->getName() << " Health: " << user.caughtPokemon[1]->getHealth() << " (enter 2)" << endl;
			}
			//displays the pokemon and health if health is not full
			if (user.caughtPokemon[2]->getHealth() < user.caughtPokemon[2]->getTotalHealth())
			{
				cout << user.caughtPokemon[2]->getName() << " Health: " << user.caughtPokemon[2]->getHealth() << " (enter 3)" << endl;
			}
			int choice;
			cin >> choice;
			choice = choice - 1;
			//if the user has health regenerations left
			if (user.gethealthRegen() > 0)
			{
				//sets the chosen pokemon's health to full
				user.caughtPokemon[choice]->setHealth(user.caughtPokemon[choice]->getTotalHealth());
				user.setHealthRegen(user.gethealthRegen() - 1);
				cout << user.caughtPokemon[choice]->getName() << "'s health has been restored! " << endl;
				cout << user.caughtPokemon[choice]->getName() << "'s Health: " << user.caughtPokemon[choice]->getHealth() << endl << endl;
			}
			else cout << "Not enough health regeneration, go to the Pokeshop!" << endl;
			break;
		case 4:
			cout << "Welcome to the PokeShop! " << endl;
			cout << "Your Money: $" << user.getMoney() << endl;
			cout << "What would you like to buy? " << endl;
			cout << "1. Health Regenerate ($50) (enter 1)" << endl;
			int choice5;
			cin >> choice5;
			switch (choice5)
			{
			case 1:
				if (user.getMoney() >= 50)
				{
					//add a health regeneration to user
					user.setHealthRegen(user.gethealthRegen() + 1);
					//takes 50$ from user
					user.setMoney(user.getMoney() - 50);
					cout << "You purchased 1 Health Regenerate! " << endl;
					cout << "Remaining Health Regenerates: " << user.gethealthRegen() << endl;
					cout << "Remaining Money: " << user.getMoney() << endl << endl;
				}
				else cout << "Insufficient funds! Fight Pokemon and Trainers to earn money! " << endl;
			}
			break;
		case 5:
			cout << "So you think you can fight a gym leader?! " << endl;
			cout << "Alright, let's fight! " << endl;
			while (i < 3 && j < 3)
			{
				//battle between user pokemon and gymleaders pokemon
				fightPokemon(user.caughtPokemon[i], gymLeader.caughtPokemon[j], user);
				//if user pokemon faints, advances to next pokemon until all 3 have fainted
				if (user.caughtPokemon[i]->getHealth() <= 0)
				{
					if (i == 3)
					{
						break;
					}
					i++;
					cout << "You use " << user.caughtPokemon[i]->getName() << "!" << endl;
				}

				//if gymleader pokemon faints, advances to next pokemon until all 3 have fainted
				if (gymLeader.caughtPokemon[j]->getHealth() <= 0)
				{
					j++;
				}
			}
			//if all of the Gym leader's pokemon have fainted, the loop exits and the game is over
			if (gymLeader.caughtPokemon[0]->getHealth() <= 0 && gymLeader.caughtPokemon[1]->getHealth() <= 0 && gymLeader.caughtPokemon[2]->getHealth() <= 0)
			{
				gymLeaderDead = true;
			}
			break;
		case 6:
			//saves all of the characters attributes to a .dat file
			saveAttributes(user, user.caughtPokemon[0], user.caughtPokemon[1], user.caughtPokemon[2]);
			break;

		case 7:
			//projects all of your pokemon's stats to the screen 
			cout << "Name: " << user.caughtPokemon[0]->getName() << endl << "Attack: " << user.caughtPokemon[0]->getAttack() << endl << "Defense: " << user.caughtPokemon[0]->getDefense() << endl;
			cout << "HP: " << user.caughtPokemon[0]->getHealth() << endl << "Level: " << user.caughtPokemon[0]->getLevel() << endl << endl;

			cout << "Name: " << user.caughtPokemon[1]->getName() << endl << "Attack: " << user.caughtPokemon[1]->getAttack() << endl << "Defense: " << user.caughtPokemon[1]->getDefense() << endl;
			cout << "HP: " << user.caughtPokemon[1]->getHealth() << endl << "Level: " << user.caughtPokemon[1]->getLevel() << endl << endl;

			cout << "Name: " << user.caughtPokemon[2]->getName() << endl << "Attack: " << user.caughtPokemon[2]->getAttack() << endl << "Defense: " << user.caughtPokemon[2]->getDefense() << endl;
			cout << "HP: " << user.caughtPokemon[2]->getHealth() << endl << "Level: " << user.caughtPokemon[2]->getLevel() << endl << endl;
			break;
		default:
		{
			cout << "Invalid Option: Try Again" << endl;
			continue;
		}
		}
	}
	cout << "Congratualations! You are now the leader of the gym and have won the game! " << endl;
	return 0;
}

//battle sequences between the user and random pokemon
void fightPokemon(Pokemon* &userPoke, Pokemon* &enemyPoke, Trainer& user)
{
	//displays what kind of pokemon the user will be fighting
	cout << "A wild " << enemyPoke->getName() << " appeared!" << endl << endl;


	//battle runs while the user pokemon and enemy pokemon have remaining health and the enemy pokemon has not been captured
	while (userPoke->getHealth() > 0 && enemyPoke->getHealth() > 0)
	{
		//allows the user to pick which of their pokemon's attack to use
		int choice;
		cout << "Pick your attack!" << endl;
		cout << "1. " << userPoke->getMove1() << " (enter 1)" << endl;
		cout << "2. " << userPoke->getMove2() << " (enter 2)" << endl;
		cout << "3. " << userPoke->getMove3() << " (enter 3)" << endl;
		cout << "4. " << userPoke->getMove4() << " (enter 4)" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			//displays which attack was selected
			cout << userPoke->getName() << " used " << userPoke->getMove1() << "!" << endl;
			//uses that attack
			enemyPoke->setHealth(userPoke->move1(enemyPoke));
			//checks if the enemy pokemon's health is <= 0
			//if so, clears screen, displays that the enemy has fainted
			//adds 2 XP to user pokemon
			//checks if the user pokemon will level up with new XP
			//exits loop
			if (faint(enemyPoke))
			{
				clear_screen();
				cout << "Enemy " << enemyPoke->getName() << " has fainted!" << endl;
				userPoke->setXP(userPoke->getXP() + 2);
				cout << userPoke->getName() << " gained 2 XP." << endl;
				user.setMoney(user.getMoney() + 10);
				cout << user.getName() << " has gained $10." << endl;
				userPoke->levelUp();
				continue;
			}
			//displays user and enemy pokemons remaining health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;

			break;

		case 2:
			//displays which attack was selected
			cout << userPoke->getName() << " used " << userPoke->getMove2() << "!" << endl;
			//uses attack
			enemyPoke->setHealth(userPoke->move2(enemyPoke));
			//checks if the enemy pokemon's health is <= 0
			//if so, clears screen, displays that the enemy has fainted
			//adds 2 XP to user pokemon
			//checks if the user pokemon will level up with new XP
			//exits loop
			if (faint(enemyPoke))
			{
				clear_screen();
				cout << "Enemy " << enemyPoke->getName() << " has fainted!" << endl;
				userPoke->setXP(userPoke->getXP() + 2);
				cout << userPoke->getName() << " gained 2 XP." << endl;
				user.setMoney(user.getMoney() + 10);
				cout << user.getName() << " has gained $10." << endl;
				userPoke->levelUp();
				continue;
			}
			//displays user and enemy pokemon remaining health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;

			break;

		case 3:
			//displays which attack was selected
			cout << userPoke->getName() << " used " << userPoke->getMove3() << "!" << endl;
			//uses attack 
			enemyPoke->setHealth(userPoke->move3(enemyPoke));
			//checks if the enemy pokemon's health is <= 0
			//if so, clears screen, displays that the enemy has fainted
			//adds 2 XP to user pokemon
			//checks if the user pokemon will level up with new XP
			//exits loop
			if (faint(enemyPoke))
			{
				clear_screen();
				cout << "Enemy " << enemyPoke->getName() << " has fainted!" << endl;
				userPoke->setXP(userPoke->getXP() + 2);
				cout << userPoke->getName() << " gained 2 XP." << endl;
				user.setMoney(user.getMoney() + 10);
				cout << user.getName() << " has gained $10." << endl;
				userPoke->levelUp();
				continue;
			}
			//displays user and enemy pokemon remaining health 
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;

			break;

		case 4://Attack 4 can never inflict damage on an enemy, removing the need to check if it has fainted
			   //displays which attack was selected
			cout << userPoke->getName() << " used " << userPoke->getMove4() << "!" << endl;
			//uses the attack 
			userPoke->move4();
			//displays user and enemy pokemon's remaining health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;
			break;
		}

		//randomly selects an attack for the enemy pokemon
		srand(time(NULL));
		int random = rand() % 3;
		switch (random)
		{
		case 0:
			//display the attack used
			cout << enemyPoke->getName() << " used " << enemyPoke->getMove1() << "!" << endl;
			//uses attack
			userPoke->setHealth(enemyPoke->move1(userPoke));
			//checks if user pokemon's health <= 0
			//clears screen
			//displays users pokemon has fainted, exits loop
			if (faint(userPoke))
			{
				clear_screen();
				cout << userPoke->getName() << " has fainted!" << endl;
				continue;
			}
			//displays user and enemy pokemon health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;
			break;
		case 1:
			//displays the attack used
			cout << enemyPoke->getName() << " used " << enemyPoke->getMove2() << "!" << endl;
			//uses attack 
			userPoke->setHealth(enemyPoke->move2(userPoke));
			//checks if user pokemon's health <= 0
			//clears screen
			//displays users pokemon has fainted, exits loop
			if (faint(userPoke))
			{
				clear_screen();
				cout << userPoke->getName() << " has fainted!" << endl;
				continue;
			}
			//displays users and enemy pokemon health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;
			break;
		case 2:
			//displaus the attack used
			cout << enemyPoke->getName() << " used " << enemyPoke->getMove3() << "!" << endl;
			//uses attack
			userPoke->setHealth(enemyPoke->move3(userPoke));
			//checks if user pokemon's health <= 0
			//clears screen
			//displays users pokemon has fainted, exits loop
			if (faint(userPoke))
			{
				clear_screen();
				cout << userPoke->getName() << " has fainted!" << endl;
				continue;
			}
			//displays user and enemy pokemons health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;
			break;
		case 3: //4th attack never does damage to enemy, removes need to check if fainted
				//displays attack used
			cout << enemyPoke->getName() << " used " << enemyPoke->getMove4() << "!" << endl;
			//uses attack
			enemyPoke->move4();
			//displays user and enemy pokemon remaining health
			cout << userPoke->getName() << "'s Health: " << userPoke->getHealth() << "       "
				<< "enemy " << enemyPoke->getName() << "'s Health: " << enemyPoke->getHealth() << endl << endl;
			break;
		}
	}
	//some attacks increase attributes such as attack and defense
	//this resets them after the battle 
	for (int i = 0; i < 3; i++)
	{
		user.caughtPokemon[i]->resetStats();
	}
}

//checks if health is <= 0
bool faint(Pokemon* P1)
{

	if (P1->getHealth() <= 0)
	{
		return true;
	}
	else return false;

}

void saveAttributes(Trainer user, Pokemon* P1, Pokemon* P2, Pokemon* P3)
{
	fstream binaryio("X.dat", ios::out | ios::binary);
	string nameValue = user.getName();
	binaryio.write(reinterpret_cast<char*>(&nameValue), sizeof(nameValue));
	int moneyValue = user.getMoney();
	binaryio.write(reinterpret_cast<char*>(&moneyValue), sizeof(moneyValue));
	int healthRegenValue = user.gethealthRegen();
	binaryio.write(reinterpret_cast<char*>(&healthRegenValue), sizeof(healthRegenValue));
	int P1Attack = P1->getAttack();
	binaryio.write(reinterpret_cast<char*>(&P1Attack), sizeof(P1Attack));
	int P1Defense = P1->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P1Defense), sizeof(P1Defense));
	int P1Health = P1->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P1Health), sizeof(P1Health));
	int P1XP = P1->getXP();
	binaryio.write(reinterpret_cast<char*>(&P1XP), sizeof(P1XP));
	int P1Level = P1->getLevel();
	binaryio.write(reinterpret_cast<char*>(&P1Level), sizeof(P1Level));
	int P2Attack = P2->getAttack();
	binaryio.write(reinterpret_cast<char*>(&P2Attack), sizeof(P2Attack));
	int P2Defense = P2->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P2Defense), sizeof(P2Defense));
	int P2Health = P2->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P2Health), sizeof(P2Health));
	int P2XP = P2->getXP();
	binaryio.write(reinterpret_cast<char*>(&P2XP), sizeof(P2XP));
	int P2Level = P2->getLevel();
	binaryio.write(reinterpret_cast<char*>(&P2Level), sizeof(P2Level));
	int P3Attack = P3->getAttack();
	binaryio.write(reinterpret_cast<char*>(&P3Attack), sizeof(P3Attack));
	int P3Defense = P3->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P3Defense), sizeof(P3Defense));
	int P3Health = P3->getDefense();
	binaryio.write(reinterpret_cast<char*>(&P3Health), sizeof(P3Health));
	int P3XP = P3->getXP();
	binaryio.write(reinterpret_cast<char*>(&P3XP), sizeof(P3XP));
	int P3Level = P3->getLevel();
	binaryio.write(reinterpret_cast<char*>(&P3Level), sizeof(P3Level));

	int P1Ident = P1->identifier;
	binaryio.write(reinterpret_cast<char*>(&P1Ident), sizeof(P1Ident));
	int P2Ident = P2->identifier;
	binaryio.write(reinterpret_cast<char*>(&P2Ident), sizeof(P2Ident));
	int P3Ident = P3->identifier;
	binaryio.write(reinterpret_cast<char*>(&P3Ident), sizeof(P3Ident));

	binaryio.close();

}






