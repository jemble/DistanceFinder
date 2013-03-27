/*
 * A binary search tree for storing location nodes
 *
 *  Created on: 26 Feb 2013
 *      Author: Ollie
 */

#include <string>
#include "LocationTree.h"

using namespace std;

// Constructor
LocationTree::LocationTree() {
	cout << "LocationTree object created" << endl;
	root = NULL;
}

// Destructor
LocationTree::~LocationTree() {
	freeNode(root);
}

// Function to find root
Node* LocationTree::getRoot() {
	return root;
	}

// Function that adds nodes to the tree
void LocationTree::addNode (Location *loc) {
   if ( root != NULL ) {
		cout << "adding a new node"<< endl;
		addNode(loc, root);
	} else {
		cout << "creating the root node" << endl;
		Node* n = new Node(loc);
		n->setIdent(loc->getCityName());
		root = n;
	}
}

void LocationTree::addNode(Location *loc, Node* leaf) {
	string ident = loc->getCityName();
	if ( ident <= leaf->getIdent() )
	{
		if ( leaf->getLeft() != NULL )
			addNode(loc, leaf->getLeft());
		else {
			Node* n = new Node(loc);
			n->setIdent(ident);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
		if ( leaf->getRight() != NULL )
			addNode(loc, leaf->getRight());
		else {
			Node* n = new Node(loc);
            n->setIdent(ident);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Remove node
void LocationTree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->getLeft());
		freeNode(leaf->getRight());
		delete leaf;
	}
}

Node* getCity(string ident, Node* node)  {
	if (node == NULL) {
		return NULL;
	}
	else if (ident == node->getIdent()) {
		  return node;
		 }
	else if (ident <= node->getIdent()) {
		getCity(ident, node->getLeft());
		 }
	else if (ident > node->getIdent()) {
		getCity(ident, node->getRight());
		 }
		 else return NULL;
}


