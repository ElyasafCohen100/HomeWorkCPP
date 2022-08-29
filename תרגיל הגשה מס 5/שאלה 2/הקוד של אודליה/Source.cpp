/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 5 Question 2*/

#include <iostream>
#include "List.h"
using namespace std;
//הגדרת ומימוש הפונקציות

List merge(List& lst1, List& lst2);
void makeSet(List& myList);
void reverse(List& myList);

int main()
{
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


List merge(List& lst1, List& lst2)
{
	List myMerge;
	while (!lst1.isEmpty() && !lst2.isEmpty())
	{
		if (lst1.firstElement() >= lst2.firstElement())
		{
			myMerge.insert(lst1.firstElement());
			lst1.removeFirst();
		}
		else
		{
			myMerge.insert(lst2.firstElement());
			lst2.removeFirst();
		}
	}

	while (!lst1.isEmpty()) // if there is more elements at lst1
	{
		myMerge.insert(lst1.firstElement());
		lst1.removeFirst();
	}

	while (!lst2.isEmpty()) // if there is more elements at lst2
	{
		myMerge.insert(lst2.firstElement());
		lst2.removeFirst();
	}

	return myMerge;
}


void makeSet(List& myList)
{
	List groupList;

	while (!myList.isEmpty())
	{
		if (groupList.search(myList.firstElement())) // if the element is already at groupList
		{
			myList.removeFirst();
		}
		else
			groupList.insert(myList.firstElement());// if the element isn't at groupList - add it
	}
	myList = groupList;
}


void reverse(List& myList)
{
	List reverseList;
	while (!myList.isEmpty())
	{
		reverseList.add(myList.firstElement()); // addind the element at the start of the list
		myList.removeFirst();
	}
	myList = reverseList;
}


/*
enter sorted values for the first list:
6 5 4 3 2 1 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7
*/