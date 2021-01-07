#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player{
	string firstName;
	string secondName;
	int points;
	
	public:
		Player(string = string(), string = string(), int = 0);
		string getFirstName() const;
		string getSecondName() const;
		int getPoints() const;
		void promote();
		
		friend istream& operator>>(istream&, Player&);
		friend ostream& operator<<(ostream&, const Player&);
};
