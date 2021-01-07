#include "Node.hpp"

Node::Node(const Team& v, Node* n){
	value = v;
	next = n;
}

Team Node::getValue() const{
	return value;
}

void Node::setValue(const Team& t){
	value = t;
}

Node* Node::getNext() const{
	return next;
}

void Node::setNext(Node* n){
	next = n;
}
