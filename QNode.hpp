#pragma once
#include "Match.hpp"

using namespace std;

class QNode{
	Match value; 
	QNode* prev;
	QNode* next;

	public:
		QNode(const Match& = Match(), QNode* = NULL, QNode* = NULL);

		Match getValue() const;
		void setValue(const Match&);
		QNode* getPrev() const;
		void setPrev(QNode*);
		QNode* getNext() const;
		void setNext(QNode*);
};
