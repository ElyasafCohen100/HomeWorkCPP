/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 5          *
* Seif: II                   *
******************************/
#include <iostream>
#include "List.h"
using namespace std;


//-------------------------- �������� ����� ��� ������ ---------------------------//
List merge(List lst1, List lst2) {

	List lst3; // head = nullptr
	lst3.clear();

	//---- ����� ����� �� ��� ��� ����� ������� ----//
	while (!lst1.isEmpty() && !lst2.isEmpty()) {

		//--- �� ��� ������ ���� ���� ������ ---//
		if (lst1.firstElement() > lst2.firstElement()) {
			lst3.insert(lst1.firstElement());
			lst1.removeFirst(); // ����� ��� �������� ������� �������
		}
		else {
			lst3.insert(lst2.firstElement());
			lst2.removeFirst(); // ����� ��� �������� ������� �����
		}
	}

	//--- ����� ������ ������� ����� ������ ������� -----//
	while (!lst1.isEmpty()) {
		lst3.insert(lst1.firstElement());
		lst1.removeFirst();
	}

	//--- ����� ������ ������� ����� ������ ������� -----//
	while (!lst2.isEmpty()) {
		lst3.insert(lst2.firstElement());
		lst2.removeFirst();
	}

	return lst3;
}



//------------------------- �������� ����� ����� ������ --------------------------//
void makeSet(List& mergedList) {

	List new_lst;
	new_lst.add(mergedList.firstElement()); // ����� ����� ������ ������� ������� ������ �����

	//---- �� ��� ��� ������� ������ ������� ----//
	while (!mergedList.isEmpty()) {

		//---- ����� �� ����� ������ �� ������ ������� ���� ������ ����� -----//
		if (new_lst.search(mergedList.firstElement()) == true) {
			mergedList.removeFirst(); // ����� ��� �������� ������� �������
		}	
		else {
			new_lst.insert(mergedList.firstElement());
		}
	}

	mergedList = new_lst;
}



//------------------------- ������ revers �������� --------------------------//
void reverse(List& mergedList) {
	List new_lst;

	while (!mergedList.isEmpty()) {
		new_lst.add(mergedList.firstElement());
		mergedList.removeFirst();
	}

	mergedList = new_lst;
}




int main() {

	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;

	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;

	return 0;
}

/*
enter sorted values for the first list:
6 5 4 3 2 1 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7
Press any key to continue . . .
*/