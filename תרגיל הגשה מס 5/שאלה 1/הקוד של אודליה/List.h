///*Odelya Yaakowich 207346784
//Workshop in c++
//Exercise 5 Question 1*/
//
//
//
//#pragma once
//#include <iostream>
//using namespace std;
//
//
////------------------------------------------------
////  class List
////      arbitrary size Lists
////      permits insertion and removal 
////      only from the front of the List
////------------------------------------------------
//class List
//{
//protected:
//	//--------------------------------------------
//	//  inner class link
//	//  a single element for the linked List 
//	//--------------------------------------------
//	class Link
//	{
//	public:
//		// constructor
//		Link(int linkValue, Link* nextPtr);
//		Link(const Link&);
//		// data areas
//		int value;
//		Link* next;
//	};	//end of class Link
//public:
//	// constructors
//	List();
//	List(const List&);
//	~List();
//
//	// operations
//	void add(int value); // adding an element to the start of the list
//	int firstElement() const; // return the first element at the list
//	bool search(const int& value) const; // if value is in the list
//	bool isEmpty() const; // check if the list is empty
//	void removeFirst(); // delete the firt element at the list
//	void clear(); // delete all the el at the list
//	List operator=(const List& rihght); // copies the list to another list
//	friend ostream& operator<<(ostream& os, const List& myList);
//	friend istream& operator>>(istream& is, List& num);
//	void insert(int key); // adding an element in his place at the list
//	void remove(int key);  //delete an el from the list
//protected:
//	// data field
//	Link* head;
//};
//
