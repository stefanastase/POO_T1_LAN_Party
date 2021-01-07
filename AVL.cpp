#include "AVL.hpp"

AVL::AVL(){
}

AVL::AVL(const Team& k, int h, TreeNode* l, TreeNode* r):BST(k, h, l, r){
}

AVL::~AVL(){
}

TreeNode* AVL::insertRec(const Team& k, TreeNode* r){
	if(r == NULL){
		TreeNode* newNode = new TreeNode(k);
		return newNode;
	}
	
	Team key = r->getKey();
	if(k < key)
		r->setLeft(insertRec(k, r->getLeft()));
	else
		r->setRight(insertRec(k, r->getRight()));
	
	r->setHeight(1 + max(height(r->getLeft()), height(r->getRight())));
	
	int bal = getBalance(r);
	
	if (bal > 1 && k < r->getLeft()->getKey())		// LL
		return rotateRight(r);
		
	if (bal < -1 && k > r->getRight()->getKey()) 	// RR
		return rotateLeft(r);
		
	if (bal > 1 && k > r->getLeft()->getKey()){		// lR
		r->setLeft(rotateLeft(r->getLeft()));
		return rotateRight(r);
	}
	
	if (bal < -1 && k < r->getRight()->getKey()){ 	// RL
		r->setRight(rotateRight(r->getRight()));
		return rotateLeft(r);
	}
		
	return r;
}

int AVL::height(TreeNode* r){
	return r ? r->getHeight() : 0;
}

int AVL::max(int a, int b){
	return (a > b) ? a : b;
}

TreeNode* AVL::rotateRight(TreeNode* y){
	TreeNode* x = y->getLeft();
	TreeNode* T2 = x->getRight();
	
	x->setRight(y);
	y->setLeft(T2);

	y->setHeight(1 + max(height(y->getLeft()), height(y->getRight())));	
	x->setHeight(1 + max(height(x->getLeft()), height(x->getRight())));
	
	return x;
}

TreeNode* AVL::rotateLeft(TreeNode* x){
	TreeNode* y = x->getRight();
	TreeNode* T2 = y->getLeft();
	
	y->setLeft(x);
	x->setRight(T2);
	
	x->setHeight(1 + max(height(x->getLeft()), height(x->getRight())));
	y->setHeight(1 + max(height(y->getLeft()), height(y->getRight())));
	
	return y;
}

int AVL::getBalance(TreeNode* r){
	return r ? height(r->getLeft()) - height(r->getRight()) : 0;
}

void AVL::printLvlPreOrder(TreeNode* r, int currLvl, int setLvl, ostream& devo){
	if(r){
		if(currLvl == setLvl)
			devo << r->getKey().getName() << endl;
		
		printLvlPreOrder(r->getRight(), currLvl + 1, setLvl, devo);
		printLvlPreOrder(r->getLeft(), currLvl + 1, setLvl, devo);
	}
}

void AVL::insert(const Team& k){
	root = insertRec(k, root);
}

void AVL::printLevel(int level, ostream& devo){
	devo << endl << "THE LEVEL " << level << " TEAMS ARE:" << endl;
	printLvlPreOrder(root, 0, level, devo);
}

void AVL::fromBST(BST* b){
	TreeNode* r = b->getRoot();
	insertFromBST(r);
}

void AVL::insertFromBST(TreeNode* r){
	if(r){
		insertFromBST(r->getRight());
		insert(r->getKey());
		insertFromBST(r->getLeft());
	}
}
