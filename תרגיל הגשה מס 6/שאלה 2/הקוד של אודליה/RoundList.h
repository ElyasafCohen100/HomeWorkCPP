/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 2*/


#include "List.h"
#pragma once

class RoundList: public List
{
	Link* head;
public:
	RoundList();//ctor
	RoundList(const RoundList& l);//copy-ctor
	~RoundList();//dctor
	void clear(); // delete all the el at the list
	void add(int value); // adding an element to the start of the list
	void removeFirst(); // delete the firt element at the list
	RoundList operator=(const RoundList& right); // copies the list to another list
	friend ostream& operator<<(ostream& os, const RoundList& myList);
	friend istream& operator>>(istream& is, RoundList& myList);
	void insert(int key); // adding an element in his place at the list
	void remove(int key);  //delete an el from the list
	void addToEnd(int val);
	int search(int n);
};

