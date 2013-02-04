#include "Tree.h"

void main() {

	Tree* myTree = new Tree();


	
	myTree->addNode(3);
	myTree->addNode(1);
	myTree->addNode(2);
	myTree->addNode(4);
	myTree->addNode(5);
	myTree->addNode(9);
	myTree->addNode(7);
	

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

	getchar();
	
}