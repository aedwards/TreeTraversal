#include <iostream>
using namespace std;

class QueueOverflowException {
public:

	QueueOverflowException() {
		cout << "Queue overflow." << endl;
	}
};

class QueueUnderflowException {
public:

	QueueUnderflowException() {
		cout << "Queue empty." << endl;
	}
};