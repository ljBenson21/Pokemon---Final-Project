#ifndef _POKEMON_
#define _POKEMON_

#include <iostream>
#include <string>
using namespace std;

class Pokemon
{
private:
	double health;
	int attack;
	int defense;
	int XP;
	short int level;
	string name;
	string move1;
	string move2;
	string move3;
	string move4;

public:
	
	Pokemon();
	Pokemon(double health, int attack, int defense, int XP, short int level, string name);
	double getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getXP() const;
	short int getLevel() const;
	string getName() const;
	string getMove1() const;
	string getMove2() const;
	string getMove3() const;
	string getMove4() const; 
	void setHealth(double H);
	void setAttack(int A);
	void setDefense(int D);
	void setXP(int X);
	void setLevel(short int L);
	void setName(string N);
	void setMove1(string M1);
	void setMove2(string M2);
	void setMove3(string M3);
	void setMove4(string M4);
	void faint();
	void levelUp();
	friend ostream& operator<<(ostream &str, const Pokemon& P1)
	{
		{
			str << P1.getName() << endl;
			str << "Health: " << P1.getHealth() << endl;
			str << "Attack: " << P1.getAttack() << endl;
			str << "Defense: " << P1.getDefense() << endl;
			str << "XP: " << P1.getXP() << endl;
			str << "Level: " << P1.getLevel() << endl;
			str << "MOVES: " << endl;
			str << "1. " << P1.getMove1() << endl;
			str << "2. " << P1.getMove2() << endl;
			str << "3. " << P1.getMove3() << endl;
			str << "4. " << P1.getMove4() << endl;

			return str;
		}
	}


};






#endif 

