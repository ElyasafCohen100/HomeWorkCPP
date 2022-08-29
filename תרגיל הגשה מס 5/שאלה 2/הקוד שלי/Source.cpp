/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 5          *
* Seif: II                   *
******************************/
#include <iostream>
#include "List.h"
using namespace std;


//-------------------------- פונקציית מיזוג שתי רשימות ---------------------------//
List merge(List lst1, List lst2) {

	List lst3; // head = nullptr
	lst3.clear();

	//---- ביצוע המיון כל זמן שלא נגמרו הרשימות ----//
	while (!lst1.isEmpty() && !lst2.isEmpty()) {

		//--- אם ערך הרשימה האחת גדול מהשניה ---//
		if (lst1.firstElement() > lst2.firstElement()) {
			lst3.insert(lst1.firstElement());
			lst1.removeFirst(); // מחיקת התא הרלוונטי מהרשימה הראשונה
		}
		else {
			lst3.insert(lst2.firstElement());
			lst2.removeFirst(); // מחיקת התא הרלוונטי מהרשימה השניה
		}
	}

	//--- הזרמת הרשימה הראשונה במידה והשניה התרוקנה -----//
	while (!lst1.isEmpty()) {
		lst3.insert(lst1.firstElement());
		lst1.removeFirst();
	}

	//--- הזרמת הרשימה הראשונה במידה והשניה התרוקנה -----//
	while (!lst2.isEmpty()) {
		lst3.insert(lst2.firstElement());
		lst2.removeFirst();
	}

	return lst3;
}



//------------------------- פונקציית הפיכת רשימה לקבוצה --------------------------//
void makeSet(List& mergedList) {

	List new_lst;
	new_lst.add(mergedList.firstElement()); // הכנסת האיבר הראשון מהרשימה שקיבלנו לרשימה החדשה

	//---- כל זמן שלא הסתיימה הרשימה שקיבלתי ----//
	while (!mergedList.isEmpty()) {

		//---- בדיקה אם האיבר הראשון של הרשימה שקיבלתי קיים ברשימה החדשה -----//
		if (new_lst.search(mergedList.firstElement()) == true) {
			mergedList.removeFirst(); // מחיקת התא הרלוונטי מהרשימה שקיבלנו
		}	
		else {
			new_lst.insert(mergedList.firstElement());
		}
	}

	mergedList = new_lst;
}



//------------------------- לרשימה revers פונקציית --------------------------//
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