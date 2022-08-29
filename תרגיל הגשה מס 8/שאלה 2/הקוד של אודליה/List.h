/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#pragma once
#include<iostream>
using namespace std;

//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		//Constructor.
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		//Data areas.
		int value;
		Link* next;
	};	//End of class Link.
public:
	//Constructors.
	List();
	List(const List&);
	~List();
	//Operations.
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void insert(int key);
	void remove(int key);
	List operator=(const List& l);
protected:
	//Data field.
	Link* head;
};


