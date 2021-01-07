#pragma once
#include "QNode.hpp"
#include "List.hpp"
#include "Stack.hpp"

using namespace std;

class Queue{
	QNode* head;
	QNode* tail;
	int size;
	
	public:
		Queue();
		Queue(const Match&, QNode* = NULL, QNode* = NULL);
		Queue(const Queue&);
	 	Queue& operator=(const Queue&);
		~Queue();
		
		void push(const Match&);
		void pop();
		
		int getSize() const;
		QNode* getHead() const;
		QNode* getTail() const;
		void scheduleMatches(const List&);
		void print(ostream& = cout) const;
		void simulateRound(List**, int, ostream& = cout);
};
