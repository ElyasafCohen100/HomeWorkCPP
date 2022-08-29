/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: II                   *
******************************/
#include "RoundList.h"
#include<iostream>
using namespace std;


enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};


int main() {

	RoundList ls1;
	int choice;
	try
	{
	cout << "Enter your choice: " << endl;
	cin >> choice;

	
		while (choice != EXIT) {

			int num;
			switch (choice) {

			case ADD: cout << "Enter 5 numbers: " << endl;
				for (int i = 0; i < 5; i++) {
					cin >> num;
					ls1.add(num);
				}
				break;


			case ADD_TO_END:cout << "Enter 5 numbers: " << endl;
				for (int i = 0; i < 5; i++) {
					cin >> num;
					ls1.addToEnd(num);
				}
				break;


			case REMOVE_FIRST: ls1.removeFirst();
				break;


			case SEARCH: cout << "Enter a number: " << endl;
				cin >> num;
				cout << ls1.search(num) << endl;
				break;


			case CLEAR: ls1.clear();
				break;


			case EMPTY: if (ls1.isEmpty())
				cout << "Empty" << endl;
					  else
				cout << "Not empty" << endl;
				break;


			case EXIT:
				cout << "Enter your choice: " << endl;

			default: cout << "ERROR!" << endl;
			}

			cout << "Enter your choice: " << endl;

			cin >> choice;
		}

		return 0;
	}

	catch (...) {}
}