#pragma once
#include <iomanip>
#include "Team.hpp"


using namespace std;

class Match{
	Team t1, t2;
	
	public:
		Match(Team = Team(), Team = Team());
		Team getWinner() const;
		Team getLoser() const;
		void setWinner();
		
		friend ostream& operator<<(ostream&, const Match&); 
};
