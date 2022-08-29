/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#pragma once
#include"Queue.h"
#include"Stack.h"
#include<iostream>
using namespace std;
///------------------------------------------------ QueueStack אנחנו בקובץ ההדר של -----------------------------------------------------///


// מימוש תור באמצעות מחסנית //


//------------------------- QueueStack פתיחת המחלקה האבסטרקטית --------------------------//
class QueueStack : public Queue { // Queue - יורשת מ QueueStack המחלקה

protected:

	Stack* data;

public:

	//------------ קונסטרקטור -----------------//
	QueueStack();
	//------------ מחיקת התור ----------------//
	void clear() override;
	//------ מחיקת האיבר הראשון מהתור -------//
	int dequeue() override;
	//---------- הוספת איבר לתור -------------//
	void enqueue(int value) override;
	//----------- הצצה לראש התור -------------//
	int front() override;
	//---------- בדיקה אם התור ריק -----------//
	bool isEmpty() const override;
};