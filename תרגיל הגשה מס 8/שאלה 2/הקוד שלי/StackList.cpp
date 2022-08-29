/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#include "StackList.h"
///--------------------------------------------- StackList של cpp - אנחנו בקובץ ה --------------------------------------------------///


// מימוש מחסנית באמצעות רשימה מקושרת //


//-------------------------------------//
//  class StackList implementation     //
//-------------------------------------//


//------------------------ קונסטרקטור ---------------------------//
StackList::StackList() :data() {
	// create and initialize a Stack based on Lists
	// this->head = NULL;
}


//--------------------- קופי קונסטרקטור ------------------------//
StackList::StackList(const StackList& lst) : data(lst.data) {
}


//---------------------- מחיקת המחסנית -------------------------//
void StackList::clear() {
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}


//-------------------- בדיקה אם המחסנית ריקה ------------------//
bool StackList::isEmpty() const {
	// return true if Stack is empty
	return data.isEmpty();
}


//----------------------- הוצאה מהמחסנית ----------------------//
int StackList::pop() {
	// return and remove the intopmost element in the Stack
	// get first element in List
	int result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}


//------------------------ דחיפה למחסנית ----------------------//
void StackList::push(int val) {
	// push new value onto Stack
	data.add(val);
}

//---------------------- הצצה לראש המחסנית ---------------------//
int StackList::top() const {
	return data.firstElement();
}
