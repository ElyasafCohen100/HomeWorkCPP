/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 5          *
* Seif: I                    *
******************************/
#include <iostream>
#include "List.h"
using namespace std;

int main() {

	List lst;
	int choice, val;

	cout << "enter the list values\n";
	cin >> lst;

	cout << "choose 0-2\n";
	cin >> choice;


	while (choice) {
		switch (choice) {

		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;


		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char* msg) {
				cout << msg << endl;
			}
			break;

		default:cout << "ERROR\n";
		}

		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}

	return 0;
}

/*
enter the list values
3 2 1 1
choose 0-2
2
enter a value to remove
2
3 1
choose 0-2
1
enter a value to insert
4
4 3 1
choose 0-2
1
enter a value to insert
2
4 3 2 1
choose 0-2
0
Press any key to continue . . .
*/