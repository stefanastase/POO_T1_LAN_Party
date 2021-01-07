#pragma once
#include "TreeNode.hpp"
#include <iostream>

class BST{
	
	protected:
		TreeNode* root;
	
		void destroyRec(TreeNode*);
		void printInOrderAsc(TreeNode*, ostream&);
		void printInOrderDesc(TreeNode*, ostream&);
		TreeNode* insertRec(const Team&, TreeNode*);
	
	public:
		BST();
		BST(const Team&, int = 1, TreeNode* = NULL, TreeNode* = NULL);
		~BST();
		
		TreeNode* getRoot() const;
		void setRoot(TreeNode*);
		
		void insert(const Team&);
		void print(ostream& = cout, int = -1);
};
