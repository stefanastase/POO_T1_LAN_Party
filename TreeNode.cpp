#include "TreeNode.hpp"

TreeNode::TreeNode(const Team& k, int h, TreeNode* l, TreeNode* r):key(k), height(h){

	left = l;
	right = r;
}

Team TreeNode::getKey() const{
	return key;
}

void TreeNode::setKey(const Team& k){
	key = k;
}

int TreeNode::getHeight() const{
	return height;
}

void TreeNode::setHeight(int h){
	height = h;
}

TreeNode* TreeNode::getLeft() const{
	return left;
}

void TreeNode::setLeft(TreeNode *l){
	left = l;
}

TreeNode* TreeNode::getRight() const{
	return right;
}

void TreeNode::setRight(TreeNode *r){
	right = r;
}
