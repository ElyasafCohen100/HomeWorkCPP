/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#include "StackList.h"
///--------------------------------------------- StackList �� cpp - ����� ����� � --------------------------------------------------///


// ����� ������ ������� ����� ������ //


//-------------------------------------//
//  class StackList implementation     //
//-------------------------------------//


//------------------------ ���������� ---------------------------//
StackList::StackList() :data() {
	// create and initialize a Stack based on Lists
	// this->head = NULL;
}


//--------------------- ���� ���������� ------------------------//
StackList::StackList(const StackList& lst) : data(lst.data) {
}


//---------------------- ����� ������� -------------------------//
void StackList::clear() {
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}


//-------------------- ����� �� ������� ���� ------------------//
bool StackList::isEmpty() const {
	// return true if Stack is empty
	return data.isEmpty();
}


//----------------------- ����� �������� ----------------------//
int StackList::pop() {
	// return and remove the intopmost element in the Stack
	// get first element in List
	int result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}


//------------------------ ����� ������� ----------------------//
void StackList::push(int val) {
	// push new value onto Stack
	data.add(val);
}

//---------------------- ���� ���� ������� ---------------------//
int StackList::top() const {
	return data.firstElement();
}
