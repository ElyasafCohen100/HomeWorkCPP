/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
* seif:    II                *
******************************/
#include <iostream>
#include "SearchTree.h"
#include "Books.h"
using namespace std;


int main() {

	SearchTree<Books> T1;
	char choice = 'z';
	Books my_book;


	while (choice != 'e') {

		cout << "enter a-e:" << endl;
		cin >> choice;

		switch (choice) {


		case 'a': cout << "enter a book" << endl;
			cin >> my_book;
			T1.add(my_book);
			break;



		case 'b': cout << "enter a book" << endl;
			cin >> my_book;
			try {
				T1.remove(my_book);
			}
			catch (const char* str) {
				cout << str << endl;
			}

			break;



		case 'c': cout << "enter a book" << endl;

			cin >> my_book;

			if (T1.search(my_book)) {
				cout << "exist" << endl;
			}
			else {
				cout << "not exist" << endl;
			}

			break;



		case 'd': T1.inOrder();
			break;


		case 'e': break;


		default:
			cout << "error" << endl;
			break;
		}
	}

	return 0;
}



/*
enter a-e:
a
enter a book:
2 b b
enter a-e:
a
enter a book:
5 e e
enter a-e:
a
enter a book:
1 a a
enter a-e:
a
enter a book:
4 d d
enter a-e:
a
enter a book:
7 g g
enter a-e:
a
enter a book:
3 c c
enter a-e:
b
enter a book:
5 e e
enter a-e:
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e:
e
*/