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
using namespace std;

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
	Trainer user;
	string name; 
	cout << "What is your trainer's name? ";
	cin >> name; 
	user.setName(name);

	Squirtle S1;
	Venasaur V1;
	Pidgeotto P1;
	Pikachu Pika1;
	Charizard C1; 
	Onyx O1;


	int choice;
	cout << "Which Pokemon would you like to start with? " << endl;
	cout << "1. Squirtle (enter 1)" << endl;
	cout << "2. Venasaur (enter 2)" << endl;
	cout << "3. Pidgeotto (enter 3)" << endl;
	cout << "4. Pikachu (enter 4)" << endl;
	cout << "5. Charizard (enter 5)" << endl;
	cout << "6. Onyx (enter 6)" << endl;
	cin >> choice; 

	switch (choice)
	{
	case 1:
		user.setCaughtPokemon(S1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << S1; 
		break;
	case 2:
		user.setCaughtPokemon(V1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << V1;
		break;
	case 3:
		user.setCaughtPokemon(P1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << P1;
		break;
	case 4:
		user.setCaughtPokemon(Pika1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << Pika1; 
		break;
	case 5:
		user.setCaughtPokemon(C1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << C1;
		break;
	case 6: 
		user.setCaughtPokemon(O1);
		cout << "Great Choice " << user.getName() << "! you chose " << user.getCaughtPokemon(0).getName() << "!" << endl;
		cout << endl;
		cout << O1; 
		break;
	}
	cout << endl;
	cout << endl;
	cout << "Pokeballs: " << user.getPokeBalls() << endl;
	cout << "Money: " << user.getMoney() << endl;




	
	
	
	
	/*Squirtle S1;
	Venasaur V1; 

	cout << "Venasuar Health before attack: " << V1.getHealth() << endl;
	V1.setHealth(S1.waterGun(V1)); 
	cout << "Venasaur Health after attack: " << V1.getHealth() << endl; 
	V1.reGrow();
	cout << "Venasaur Health after reGrow: " << V1.getHealth() << endl;*/

	return 0; 
}

