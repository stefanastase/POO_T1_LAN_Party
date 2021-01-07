#pragma once
#include "Player.hpp"
#include <iomanip>


using namespace std;

class Team{
	int size;
	string name;
	Player* players;
	
	public:
		Team(int = 0, string = string(), Player* = NULL);
		Team(const Team&);
		Team& operator=(const Team&);
		~Team();
		
		string getName() const;
		double getScore() const;
		void promote();
		void printWithScore(ostream& = cout) const;
		friend istream& operator>>(istream&, Team&);
		friend ostream& operator<<(ostream&, const Team&);
		
		friend bool operator<(const Team&, const Team&);
		friend bool operator>(const Team&, const Team&);
		friend bool operator<=(const Team&, const Team&);
		friend bool operator>=(const Team&, const Team&);
};
