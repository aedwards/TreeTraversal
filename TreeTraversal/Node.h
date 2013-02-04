//Node class 
#include <iostream>


class Node {

    int key;
    Node* left;
    Node* right;

public:

    Node() { 
		key=-1; 
		left=NULL; 
		right=NULL; 
	}

    void setKey(int aKey) { 
		key = aKey; 
	}

    void setLeft(Node* aLeft) { 
		left = aLeft; 
	}

    void setRight(Node* aRight) { 
		right = aRight; 
	}

    int Key() { 
		return key; 
	}

    Node* Left() { 
		return left; 
	}

    Node* Right() { 
		return right; 
	}

};