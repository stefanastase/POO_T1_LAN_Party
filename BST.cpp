#include "BST.hpp"

BST::BST(){
	root = NULL;
}

BST::BST(const Team& val, int h, TreeNode* l, TreeNode* r){
	root = new TreeNode(val, h, l, r);
}

BST::~BST(){
	// Arborele se va distruge recursiv
	destroyRec(root);
}

void BST::destroyRec(TreeNode* n){
	if(n != NULL){
		destroyRec(n->getLeft());
		destroyRec(n->getRight());
		delete n;
	}
}

void BST::printInOrderAsc(TreeNode* n, ostream& devo){
	if(n){
		printInOrderAsc(n->getLeft(), devo);
		n->getKey().printWithScore(devo);
		printInOrderAsc(n->getRight(), devo);
	}
}

void BST::printInOrderDesc(TreeNode* n, ostream& devo){
	if(n){
		printInOrderDesc(n->getRight(), devo);	
		n->getKey().printWithScore(devo);	
		printInOrderDesc(n->getLeft(), devo);
	}
}

TreeNode* BST::insertRec(const Team& k, TreeNode* r){
	if(r == NULL){
		TreeNode* newNode = new TreeNode(k);
		return newNode;
	}
	
	Team key = r->getKey();
	if(k < key)
		r->setLeft(insertRec(k, r->getLeft()));
	else
		r->setRight(insertRec(k, r->getRight()));
	
	return r;
}

TreeNode* BST::getRoot() const{
	return root;
}

void BST::insert(const Team& t){
	root = insertRec(t, root);
}

void BST::print(ostream& devo, int order){
	// Afisare asc sau desc, implicit desc
	if(order > 0)
		printInOrderAsc(root, devo);
	else
		printInOrderDesc(root, devo);
}

