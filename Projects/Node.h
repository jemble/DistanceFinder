//============================================================================
// Name        : Node.h
// Author      : Ollie
// Date        : Created on: 26 Feb 2013
// Version     :
// Copyright   : copyright reserved
// Description : A Node Class for insertion into binary tree
//============================================================================/*


#ifndef NODE_H_
#define NODE_H_

#include "Location.h"

using namespace std;

class Node {
public:
	string ident;
	int counter;
	//Location location;
	Node* dups;
	Node* left;
	Node* right;
	Node* parent;
	Node(Location *location);

	void setLeft(Node* left);
	void setRight(Node* right);
	void setParent(Node* parent);
	void setDuplicate(Node* dups);
	string getIdent();
	void setIdent(string id);
	Node* getLeft();
	Node* getRight();
	Node* getParent();

};

#endif /* NODE_H_ */

