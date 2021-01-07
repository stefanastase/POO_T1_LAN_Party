#include "Player.hpp"

Player::Player(string first, string second, int pts){
	firstName = first;
	secondName = second;
	points = pts;
}

string Player::getFirstName() const{
	return firstName;
}

string Player::getSecondName() const{
	return secondName;
}

int Player::getPoints() const{
	return points;
}

void Player::promote(){
	// Daca echipa castiga, jucatorul va primi un punct de experienta
	points++;
}

istream& operator>>(istream& din, Player& p){
	din >> p.firstName >> p.secondName;
	din >> p.points;
	return din;
}

ostream& operator<<(ostream& dout, const Player& p){
	dout << p.firstName << " " << p.secondName << " " << p.points << endl;
	return dout;
}
