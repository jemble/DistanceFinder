//============================================================================
// Name        : LocationTree.h
// Authors     : Bourgein, Oliver, Worth
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Binary Tree Class to store Nodes
//============================================================================/*

#ifndef LOCATIONTREE_H_
#define LOCATIONTREE_H_

#include "Location.h"
#include "Node.h"
#include <string>
#include <algorithm>

# define L 0
# define R 1

using namespace std;

class LocationTree {
private:
	Node* root;
	Node* balancePoint;
	Node* midNode;
	Node* insertedNode;
	int childOne;
	int childTwo;

public:

	// Default Constructor
	LocationTree();

	// Destructor
	~LocationTree();

	//Function Prototypes
	Node* getRoot();
	Node* setRoot(Node* node);
	Node* getCity(Node* node, string ident);
	bool addToTree(LocationTree* tree, Location* loc, Node* node, string city); // Adds loc to tree
	void addNode (Location *loc); // To add first node
	void addNode(Location *loc, Node* leaf);
	void reAddNode(Location *loc, Node* test);
	bool deleteNode (string ident);
	bool deleteDupNode(Node* foundNode, int number);
	void freeNode(Node* leaf);
	Node* getPrevious(Node* node, string ident);
	Node* getNext(Node* node, string ident);
	Node* getFirst(Node* node);
	Node* getLast(Node* node);
	Node* getFarLeft(Node* node, string ident);
	Node* getFarRight(Node* node, string ident);
	void rotateLR();
	void rotateRL();
	void rotateRR();
	void rotateLL();
	void balanceUpToRoot(Node* node);
	void resetBalFactUpToRoot(Node* node);
	string serialise(Node* node);
	string displayTrav(Node* node);
	void detachNext(Node* next);
	void detachPrevious(Node* previous);
	void swapInSelected(Node* selected);
	int findMinDepth(Node* root);
	int findMaxDepth(Node* test);
	int getBalanceFactor(Node* test);

};

#endif /* LOCATIONTREE_H_ */

