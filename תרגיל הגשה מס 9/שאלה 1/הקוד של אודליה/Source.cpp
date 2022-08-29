/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
*                            *
******************************/
#include <iostream>
#include "SearchTree.h"
#include"Tree.h"
using namespace std;

enum {
	END, 
	ADD,
	SEARCH,
	REMOVE, 
	BREADTHSCAN,
	HEIGHT, 
	SUCCESSOR, 
	DELETEDUP,
	REFLECT 
};

int main() {

	SearchTree<int> T1;
	int x, y, z;

	cout << "enter 10 numbers:\n";

	for (int i = 0; i < 10; i++) {
		cin >> x;
		T1.add(x);
	}

	cout << "inorder: ";
	T1.inOrder();

	cout << "\nenter 0-8:\n";
	cin >> x;

	while (x != END) {
		
		switch (x) {

		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
		
			break;



		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y)) {
				cout << "exist" << endl;
			}
			else {
				cout << "no exist" << endl;
			}

			break;




		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try {
				T1.remove(y);
				cout << "after removing " << y << ": ";
				
				T1.inOrder();
				cout << endl;
			}

			catch (const char* str) {
				cout << str << endl;
			}
			break;



		case BREADTHSCAN: cout << "breadth scan: ";
			T1.breadthScan();
			cout << endl;
			break;




		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;



		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try {
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;
			}

			catch (const char* str) {
				cout << str << endl;
			}
			break;



		case DELETEDUP: cout << "after delete duplicate: ";
			T1.delete_duplicates();
			T1.inOrder();
			cout << endl;
			break;



		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}


		cout << "enter 0-8:\n";
		cin >> x;
	}


	return 0;
}

/*
enter 10 numbers:
	1 2 3 9 8 7 1 5 9 7
	inorder : 1 1 2 3 5 7 7 8 9 9
	enter 0 - 8 :
	1
	enter a number : 6
	after adding 6 : 1 1 2 3 5 6 7 7 8 9 9
	enter 0 - 8 :
	2
	enter a number : 5
	exist
	enter 0 - 8 :
	2
	enter a number : 4
	no exist
	enter 0 - 8 :
	3
	enter a number : 6
	after removing 6 : 1 1 2 3 5 7 7 8 9 9
	enter 0 - 8 :
	4
	breadth scan : 1 1 2 3 9 8 7 9 5 7
	enter 0 - 8 :
	5
	height of tree : 7
	enter 0 - 8 :
	6
	enter a number : 7
	successor of 7 is : 8
	enter 0 - 8 :
	0
	*/
