#include "Stack.hpp"

using namespace std;


Stack::Stack(){
	head = NULL;
	size = 0;
}

Stack::Stack(const Team& t, Node* n){
	head = new Node(t, n);
	size = 1;
}

Stack::Stack(const Stack& s){
	head = NULL;
	*this = s;
}

Stack& Stack::operator=(const Stack& s){
	size = 0;
	if (head) delete head;
	
	if(s.head == NULL)	head = NULL;
	else{
		Node* temp = s.head;
		while(temp){
			push(temp->getValue());
			temp = temp->getNext();
		}
	}
	return *this;
}
Stack::~Stack(){
	while(head)
		pop();
}

void Stack::push(const Team& t){
	Node* new_node = new Node(t);
	if(!head) head = new_node;
	else{
		Node* temp = head;
		head = new_node;
		head->setNext(temp);
	}
	size++;
}

void Stack::pop(){
	if(head == NULL) return;
	else{
		Node* temp = head;
		head = head->getNext();
		delete temp;
		size--;
	}
}

void Stack::print(ostream& devo) const{
	Node* temp = head;
	while(temp){
		temp->getValue().printWithScore(devo);
		temp = temp->getNext();
	} 
}

int Stack::getSize() const{
	return size;
}

Node* Stack::getHead() const{
	return head;
}

void Stack::toList(List* l){
	// Capul listei va pointa catre stiva
	l->setHead(head);
	l->setSize(size);
	head = NULL;
	size = 0;
}

