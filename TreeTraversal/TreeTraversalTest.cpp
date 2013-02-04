#include "Tree.h"

void main() {

	Tree* myTree = new Tree();

	Tree* otherTree = new Tree();
	otherTree->addNode(45);
	otherTree->addNode(17);
	otherTree->addNode(96);
	
	myTree->addNode(47);
	myTree->addNode(30);
	myTree->addNode(15);
	myTree->addNode(12);

	myTree->Root()->setRight(otherTree->Root());	//adds otherTree to myTree

	

	cout << "Root node: " << myTree->Root()->Key() << endl;

	cout << "\nIn-order traversal" << endl;
	myTree->inOrder(myTree->Root());
	cout << endl;

	cout << "\nPre-order traversal" << endl;
	myTree->preOrder(myTree->Root());
	cout << endl;

	cout << "\nPost-order traversal" << endl;
	myTree->preOrder(myTree->Root());
	cout << endl;

	cout << "\nLevel-order traversal" << endl;
	myTree->levelOrder(myTree->Root());
	cout << endl;

	getchar();
	
}