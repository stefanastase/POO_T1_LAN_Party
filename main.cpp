#include <fstream>
#include "List.hpp"
#include "Queue.hpp"
#include "AVL.hpp"

using namespace std;

// Functie ce trunchiaza numarul n la o putere a lui 2
int binaryFloor(int n){
	
	int b = 1;
	
	while(b <= n)
		b *= 2;
	
	return b / 2;
}

int main(int argc, char** argv) {
	ifstream rin(argv[1]);
	ifstream din(argv[2]);
	ofstream rout(argv[3]);
	
	int task = 0;
	
	for(int i = 0; i < 5; i++){
		bool c;
		rin >> c;
		task += c;
	}
	
	int num;
	din >> num;
	
	List *teams = new List;
	for(int i = 0; i < num; i++){
		Team t;
		din >> t;	
		teams->add(t);
	}
	
	if(task == 1)
		teams->printNames(rout);
		
	
	if(task >= 2){
		int qualifiedNum = binaryFloor(num);
		teams->removeLowest(num - qualifiedNum);
		teams->printNames(rout);
	}
	

	if(task >= 3){
		List* topEight = new List;		
		int round = 1;
		// Se vor simula runde pana cand mai ramane o singura echipa in lista
		while(teams->getSize() > 1){
			Queue *matches = new Queue;
			matches->simulateRound(&teams, round, rout);
			if(teams->getSize() == 8)
				*topEight = *teams; 
			round++;
			delete matches;
		}
		
		if(task >= 4){
			BST *topTree = new BST;		
			Node* topHead = topEight->getHead();
			
			while(topHead){
				Team t = topHead->getValue();
				topTree->insert(t);
				topHead = topHead->getNext();
			}
			
			rout << endl << "TOP 8 TEAMS:" << endl;
			topTree->print(rout);
			
			if(task >= 5){
				AVL* avlTree = new AVL;
				avlTree->fromBST(topTree);
				avlTree->printLevel(2, rout);
				delete avlTree;
				}
	
			delete topTree;
		}
		
		delete topEight;
		}
	
	rin.close();
	din.close();
	rout.close();
	
	delete teams;
	return 0;
}
