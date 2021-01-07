#pragma once
#include "Team.hpp"

using namespace std;

class TreeNode{
	Team key;
	int height;
	TreeNode *left, *right;
	
	public:
		TreeNode(const Team&, int = 1, TreeNode* = NULL, TreeNode* = NULL);
	
		Team getKey() const;
		void setKey(const Team&);
		
		int getHeight() const;
		void setHeight(int);
		
		TreeNode* getLeft() const;
		void setLeft(TreeNode*);
		
		TreeNode* getRight() const;
		void setRight(TreeNode*);
};
