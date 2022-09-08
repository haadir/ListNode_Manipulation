#include <iostream>
using namespace std;
#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
	Node* test4 = new Node(4, nullptr);
	Node* test3 = new Node(3, test4);
	Node* test2 = new Node(2, test3);
	Node* test1 = new Node(1, test2);
	Node* evens = nullptr;
	Node* odds = nullptr;
	split(test1, odds, evens);
	
	cout << "odds:" << endl;
		while (odds != NULL) {
			cout << odds->value << endl;
			odds = odds->next;
		}
		
		cout << "evens:" << endl;
		while (evens != NULL) {
			cout << evens->value << endl;
			evens = evens->next;
		}

		delete test1;
		delete test2;
		delete test3;
		delete test4;
}