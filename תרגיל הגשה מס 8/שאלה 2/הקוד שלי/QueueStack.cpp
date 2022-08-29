/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#include "QueueStack.h"
#include"StackList.h"
#include<iostream>
using namespace std;
///------------------------------------------------ QueueStack של cpp - אנחנו בקובץ ה -----------------------------------------------------///

// מימוש תור באמצעות מחסנית //


//--------------- קונסטרקטור -------------------//
QueueStack::QueueStack() {
	data = new StackList; // שיצביע לתחילת התור stack הגדרת מצביע מסוג 
}



//--------------- מחיקת התור --------------------//
void QueueStack::clear() {
	this->data->clear();
}

//---------- מחיקת האיבר הראשון מהתור ----------//
int QueueStack::dequeue() {

	//if (!this->data->top()) {
	//	throw "the Queue is empty\n";
	//}

	return  this->data->pop();
}


//------------- הוספת איבר בודד לתור ---------------//
void QueueStack::enqueue(int value) {

	/*

	מעבר כוסות
	I'm using Move cups to keep the method of FIFO

	*/

	StackList st; // מחסנית עזר

	//----- בדיקה כל עוד שהמחסנית הראשית מלאה ----//
	while (!this->data->isEmpty()) { // כל עוד המחסנית הראשית מלאה - כדי שלא תהייה לי בעיית פיפו
		st.push(this->data->pop()); // עושים מעבר כוסות 
	}

	this->data->push(value); //FIFO הכנסה למחסנית הראשית את האיבר החדש כדי לשמור על 

	//----- החזרת הערכים למקום אחרי דחפנו פנימה את האיבר החדש ----//
	while (!st.isEmpty()) {
		this->data->push(st.pop()); // הכנסה למחסנית הראשית
	}
}


//----------- הצצה לראש התור -------------//
int QueueStack::front() {
	return this->data->top();
}


//---------- בדיקה אם התור ריק -----------//
bool QueueStack::isEmpty() const {

	if (this->data->isEmpty()) {
		return true;
	}
	return false;
}