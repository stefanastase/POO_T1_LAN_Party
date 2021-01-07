#include "Match.hpp"

Match::Match(Team team1, Team team2){
	t1 = team1;
	t2 = team2;
}

void Match::setWinner(){
	if(t1.getScore() > t2.getScore()) t1.promote();
	else t2.promote();
}

Team Match::getWinner() const{
	return (t1.getScore() > t2.getScore()) ? t1 : t2;
}

Team Match::getLoser() const{
	return (t1.getScore() < t2.getScore()) ? t1 : t2;
}

ostream& operator<<(ostream& devo, const Match& m){
	devo << m.t1.getName();
	devo << setfill (' ') << setw (34 - m.t1.getName().length()) << "-";
	devo << setfill (' ') << setw (33);
	devo << m.t2.getName();
	
	return devo;
}
