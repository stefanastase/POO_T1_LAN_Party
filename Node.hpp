#pragma once
#include "Team.hpp"

using namespace std;

class Node{
		Team value;
		Node* next;
	
	public:
		Node(const Team& = Team(), Node* = NULL);
		
		Team getValue() const;
		void setValue(const Team&);
		Node* getNext() const;
		void setNext(Node*);
};
