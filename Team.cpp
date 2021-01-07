#include "Team.hpp"

Team::Team(int s, string n, Player* p){
	size = s;
	name = n;
	if(p != NULL){
		players = new Player[size];
		
		for(int i = 0; i < size; i++)
			players[i] = p[i];
	}
	else players = NULL;
		
}

Team::Team(const Team& t){
	players = NULL;
	*this = t;
}

Team& Team::operator=(const Team& t){
	if(this != &t){
		size = t.size;
		name = t.name;
		if(players != NULL) {
			delete [] players;
			}
		if(t.players != NULL){
			players = new Player[size];
			for(int i = 0; i < size; i++)
				players[i] = t.players[i];
			}
		else
			players = NULL;
	}
	return *this;
}

Team::~Team(){
	if(players != NULL) delete [] players;
	players = NULL;
}

double Team::getScore() const{
	double score = 0;
	for(int i = 0; i < size; i++){
		score += players[i].getPoints();
	}
	return score / size;
}

string Team::getName() const{
	return name;
}

void Team::promote(){
	for(int i = 0; i < size; i++)
		players[i].promote();
}

void Team::printWithScore(ostream& devo) const{
		devo << name;
		devo << setfill (' ') << setw (37 - name.length()) << "-  ";
		devo << fixed << setprecision(2) << getScore() << endl;
}

istream& operator>>(istream& din, Team& t){
	din >> t.size >> ws; 
	getline(din, t.name);
	if(t.name[t.name.length() - 1] == ' ')
		t.name = t.name.substr(0, t.name.length() - 1); // Stergem spatiile in plus de la finalul numelui.
 
	t.players = new Player[t.size];
	for(int i = 0; i < t.size; i++)
		din >> t.players[i];

	return din;
}

ostream& operator<<(ostream& dout, const Team& t){
	dout << t.size << " " << t.name << endl;
	
	for(int i = 0; i < t.size; i++)
		dout << t.players[i];
	
	dout << endl;
	return dout;
}

bool operator<(const Team& l, const Team& r){
	if(l.getScore() < r.getScore()) return 1;
	// In cazul in care scorul este egal, comparam numele
	else if(l.getScore() == r.getScore()){	
		string lName = l.getName();
		string rName = r.getName();
		if(lName.compare(rName) < 0) return 1;
		else return 0;
	}
	else return 0;
}

bool operator>(const Team& l, const Team& r){
	return r < l;
}

bool operator<=(const Team& l, const Team& r){
	return !(l > r);
}

bool operator>=(const Team& l, const Team& r){
	return !(l < r);
}
