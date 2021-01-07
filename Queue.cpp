#include "Queue.hpp"

using namespace std;


Queue::Queue(){
	head = tail = NULL;
	size = 0;
}

Queue::Queue(const Match& m, QNode* p, QNode* n){
	head = tail = new QNode(m, p, n);
	size = 1;
}

Queue::Queue(const Queue& q){
	head = NULL;
	tail = NULL;
	*this = q;
}

Queue& Queue::operator=(const Queue& q){
	size = 0;
	if (head) delete head;
	if (tail) delete tail;
	
	if(q.head == NULL){
		head = tail = NULL;
	}
	else{
		QNode *temp = q.getHead();
		while(temp){
			push(temp->getValue());
			temp = temp->getNext();
		}
	}
	return *this;
}
Queue::~Queue(){
	while(head)
		pop();
	tail = NULL;
}

void Queue::push(const Match& m){
	QNode* new_node = new QNode(m);
	
	if(tail == NULL){
		head = tail = new_node;
	}
	
	else{
		tail->setNext(new_node);
		new_node->setPrev(tail);
		tail = new_node;
	}
	size++;
}

void Queue::pop(){
	if(head == NULL) return;
	
	QNode* temp = head;
	
	if(head->getNext())
		(head->getNext())->setPrev(NULL);
		
	head = head->getNext();
	delete temp;
	size--;
}

int Queue::getSize() const{
	return size;
}

QNode* Queue::getHead() const{
	return head;
}

QNode* Queue::getTail() const{
	return tail;
}

void Queue::scheduleMatches(const List& l){
	// Daca sunt cel putin 2 echipe in lista creeam partidele
	if(l.getSize() >= 2){
		Node* curr = l.getHead();
		Node* next = curr->getNext();
			while(curr != NULL && next != NULL){
				Match *temp = new Match(curr->getValue(), next->getValue());
				push(*temp);
				curr = next->getNext();
				if(curr != NULL)	next = curr->getNext();
				delete temp;
			}
	}
}

void Queue::simulateRound(List** teams, int round, ostream& devo){
	// Creeam partida cu echipele din lista
	scheduleMatches(**teams);
	
	// Golim lista de echipe
	int currSize = (*teams)->getSize();
	
	if(currSize)
		(*teams)->removeLowest(currSize);
	
	
	QNode* temp = head;

	Stack* winners = new Stack;
	Stack* losers = new Stack;
	
	while(temp){
		Match match = temp->getValue();
		
		match.setWinner();
		winners->push(match.getWinner());
		losers->push(match.getLoser());
		
		temp = temp->getNext();
	}
	
	devo << endl << "--- ROUND NO:" << round << endl;
	print(devo);
	devo << endl << "WINNERS OF ROUND NO:" << round << endl;
	winners->print(devo);
	winners->toList(*teams);
	
	delete winners;
	delete losers;
	delete temp;
}

void Queue::print(ostream& devo) const{
	QNode* temp = head;
	while(temp != NULL){
		devo << temp->getValue() << endl;
		temp = temp->getNext();
	}
}
