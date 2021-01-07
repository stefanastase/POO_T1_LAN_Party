#include "BST.hpp"

class AVL : public BST{
	
	private:
		TreeNode* insertRec(const Team&, TreeNode*);
		
		int height(TreeNode*);
		int max(int, int);	
		TreeNode* rotateRight(TreeNode*);
		TreeNode* rotateLeft(TreeNode*);
		int getBalance(TreeNode*);
		
		void printLvlPreOrder(TreeNode*, int, int, ostream&);
		void insertFromBST(TreeNode*);
		
	public:
		AVL();
		AVL(const Team&, int = 1, TreeNode* = NULL, TreeNode* = NULL);
		~AVL();
	
		void insert(const Team&);
		void printLevel(int, ostream& = cout);
		
		void fromBST(BST*);
};
