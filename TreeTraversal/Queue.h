//Queue class  -- This will be used in order to facilitate Level Order Traversal of nodes.

//Main class file for linked list implementation of a queue.
#include <iostream>
#include "QueueNode.h"
#include "QueueExceptions.h"

class ListQueue {

private:
	QNode* front;
	QNode* rear;
	int count;

public:

	//default ctor
	ListQueue() {

		front = NULL;
		rear = NULL;
		count = 0;
	}


	//Enqueue element starting at the end of the list(rear).
	void Enqueue(int element) {
		//Create new node
		QNode* temp = new QNode();
		temp->data = element;
		temp->next = NULL;

		//if the list is empty, front and rear both point to the new element.
		if(isEmpty()) {
			front = rear = temp;
		}
		else {
			//Append to the list
			rear->next = temp;
			rear = temp;
		}
		//cout << "\nThe value " << rear->data << " has just been queued.\n" << endl;		//only for verifying output, delete before used in production
		count++;
	}

	//Dequeue the element at the front(head of the list).
	int Dequeue() {
		//check for empty list
		if(isEmpty()) {
			throw new QueueUnderflowException();
		}

		//get the data from the front element of the list before its next pointer is assigned to point to another location.
		int dequeuedData = front->data;		
		
		//Temporary pointer to help facilitate the pointing of the previous front node to a new node.
		//This is necessary because you will have a used memory location without anything pointing to it. i.e. memory leaks/invalid memory.
		QNode* temp = front;		

		//Move the front pointer to the next node.
		front = front->next;
		//decrement the count of the queue list.
		count--;

		delete temp;
		return dequeuedData;
	}
	/*
	void DeleteQueue() {
		QNode* temp;
		while(!isEmpty()) {
			temp = Q;
			Q = Q->next;
			delete temp;
		}
		delete Q;
		temp = nullptr;
		Q = nullptr;
	}
	*/

	bool isEmpty() {
		return count == 0 ? true : false;
	}

	int Size() {
		return count;
	}

	int Front() {
		if(isEmpty()) {
			throw new QueueUnderflowException();
		}

		return front->data;
	}

	int Rear() {
		if(isEmpty()) {
			throw new QueueUnderflowException();
		}

		return rear->data;
	}


};