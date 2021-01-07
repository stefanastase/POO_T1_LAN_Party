#include "QNode.hpp"


QNode::QNode(const Match& v, QNode* p, QNode* n){
	
	value = v;
	prev = p;
	next = n;
}

Match QNode::getValue() const{
	return value;
}

void QNode::setValue(const Match& v){
	value = v;
}

QNode* QNode::getPrev() const{
	return prev;
}

void QNode::setPrev(QNode* p){
	prev = p;
}

QNode* QNode::getNext() const{
	return next;
}

void QNode::setNext(QNode* n){
	next = n;
}
