#pragma once
#include "Node.hpp"
#include <iostream>

using namespace std;

class List{
		Node* head;
		int size;
	
	public:
		List();
		List(const Team&, Node* = NULL);
		List(const List&);
		List& operator=(const List&);
		~List();
		
		void add(const Team&, int = 0);
		void remove(const Team&);
		void removeLowest(int unqualNum);
		
		void printNames(ostream& o = cout) const;
		
		int getSize() const;
		void setSize(int);
		Node* getHead() const;
		void setHead(Node*);
};
