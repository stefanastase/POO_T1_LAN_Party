#pragma once
#include "Node.hpp"
#include "List.hpp"
#include <iostream>

using namespace std;

class Stack{
	Node* head;
	int size;
	
	public:
		Stack();
		Stack(const Team&, Node* = NULL);
		Stack(const Stack&);
		Stack& operator=(const Stack&);
		~Stack();
		
		void push(const Team&);
		void pop();
		void print(ostream& = cout) const;
		
		int getSize() const;
		Node* getHead() const;
		
		void toList(List* );
};
