#Makefile for "lanParty" C++ app

PROG = lanParty
SRCS = main.cpp Player.cpp Team.cpp Node.cpp List.cpp Match.cpp QNode.cpp Queue.cpp Stack.cpp TreeNode.cpp BST.cpp AVL.cpp

build: 
	g++ -o $(PROG) $(SRCS)

clean:
	rm -f $(PROG)