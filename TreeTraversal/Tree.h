//Tree class  -- The main class that faciliates the creation, deletion and traversal of nodes in a binary tree.

#include <iostream>
using namespace std;
#include "Node.h";

class Tree {

	Node* root;

public:

	//deafult ctor
	Tree() {
		 root = NULL;
	}

	//destructor
	~Tree() {
		 freeNode(root);
	}

	//return the root node
	Node* Root() {
		return root;
	}

	// Free the node
	void freeNode(Node* leaf)
	{
		if ( leaf != NULL )
		{
		   freeNode(leaf->Left());
		   freeNode(leaf->Right());
		   delete leaf;
		}
	}

	// Add a node
	void addNode(int key) {
		 //If no previous existing elements, add node as root node
		 if ( root == NULL ) {
			cout << "add root node ... " << key << endl;
			Node* n = new Node();
			n->setKey(key);
			root = n;
		 }
		 //defer control to the overloaded addNode() method
		 else {
			cout << "add other node ... " << key << endl;
			addNode(key, root);
		 }
	}

	//Overloaded addNode which determines where to add a node based on the location of previously inserted nodes. It is a recursive funtion.
	void addNode(int key, Node* leaf) {
		if(key <= leaf->Key()) {
			if(leaf->Left() != NULL) {
				addNode(key, leaf->Left());
			}
			else {
				Node *n = new Node();
				n->setKey(key);
				leaf->setLeft(n);
			}
		}
		else {
			if(leaf->Right() != NULL) {
				addNode(key, leaf->Right());
			}
			else {
				Node *n = new Node();
				n->setKey(key);
				leaf->setRight(n);
			}
		}
	}

	//Print the tree In-Order
	//Traverse the subtree, root, and right tree
	void inOrder(Node* n) {
		if(n) {
			inOrder(n->Left());
			cout << n->Key() << " ";
			inOrder(n->Right());
		}
	}

	//Print the tree Pre-order
	//Traverse the root, left sub-tree, right-subtree
	void preOrder(Node* n) {
		if(n) {
			cout << n->Key() << " ";
			preOrder(n->Left());
			preOrder(n->Right());
		}
	}

	//Print the tree postOrder
	//Traverse the left sub-tree, right sub-tree, root
	void postOrder(Node* n) {
		if(n) {
			postOrder(n->Left());
			postOrder(n->Right());
			cout << n->Key() << " ";
		}
	}


};