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
LocationTree::Tree() {
	cout << LocationTree object created with name: << cityName << endl;
	root = NULL;
}

// Destructor
LocationTree::~Tree() {
	freeNode(root);
}

// Function to find root
Node* LocationTree::getRoot() {
	return root;
	}

// Function that adds nodes to the tree
void LocationTree::addNode (int ident) {
   if ( root == NULL ) {
		cout << "creating the root node, City = " << ident << endl;
		Node* n = new Node();
		n->setIdent(ident);
		root = n;
    }
    else {
		cout << "adding a new node, City = " << ident << endl;
		addNode(ident, root);
	}
}

void LocationTree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != NULL )
            addNode(key, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != NULL )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Remove node
void LocationTree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}
