#include "List.hpp"

List::List(){
	head = NULL;
	size = 0;
}

List::List(const Team& v, Node* n){
	head = new Node(v, n);
	size = 1;
};

List::List(const List& l){	
	head = NULL;
	*this = l;
};

List& List::operator=(const List& l){
	size = 0;
	if(head) delete head;
	
	if(l.head == NULL)	head = NULL;
	else{
		Node* temp = l.head;
		while(temp){
			add(temp->getValue(), size);
			temp = temp->getNext();
		}
	}
	return *this;
}

List::~List(){
	while(head != NULL){
		Node *temp = head->getNext();
		delete head;
		head = temp;
		size--;
	}
}
void List::add(const Team& t, int pos){
	Node* new_node = new Node(t);
	
	if(pos > size)
		pos = size;
	
	if(pos == 0){
		if (head == NULL){
			head = new_node;
		}
		else{
			Node* temp = head;
			head = new_node;
			head->setNext(temp);
		}
	}
	else{
		Node* temp = head;
		int currPos = 0;
		while(temp->getNext() != NULL && currPos != pos){
			temp = temp->getNext();
			currPos++;
			}
		if(currPos == pos){
			Node* next = temp->getNext();
			new_node->setNext(next);
			}
			
		temp->setNext(new_node);
			
	}
	size++;
}

void List::remove(const Team& t){
	if(head == NULL) return;
	
	if((head->getValue()).getName() == t.getName()){
		Node *temp = head;
		head = head->getNext();
		delete temp;
		size--;
		return;
	}
	
	Node* curr = head;
	Node* next = head->getNext();
	
	while(next != NULL){
		if((next->getValue()).getName() == t.getName()){
			curr->setNext(next->getNext());
			delete next;
			size--;
			return;
		}
		curr = curr->getNext();
		if(curr != NULL)
			next = curr->getNext();
		else
			next = NULL;
	}
}

void List::removeLowest(int unqualNum){
	int removed = 0;
	
	while(removed < unqualNum){
		Node* temp = head;
		double minScore = (temp->getValue()).getScore();
		Team minTeam = temp->getValue();
		temp = temp->getNext();
		
		while(temp != NULL){
			double currScore = (temp->getValue()).getScore();
			if(currScore < minScore){
				minScore = currScore;
				minTeam = temp->getValue();
			}
			temp = temp->getNext();
		}
		
		remove(minTeam);
		removed++; 
	}
}

void List::printNames(ostream& o) const{
	Node *temp = head;
	while(temp != NULL){
		o << (temp->getValue()).getName() << endl;
		temp = temp->getNext();
	}	
}

int List::getSize() const{
	return size;
}

void List::setSize(int s){
	size = s;
}

Node* List::getHead() const{
	return head;
}

void List::setHead(Node* h){
	head = h;
}
