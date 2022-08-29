/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#pragma once
#include<iostream>
using namespace std;
///------------------------------------------------ Queue אנחנו בקובץ ההדר של -----------------------------------------------------///


//------------------------- Queue פתיחת המחלקה האבסטרקטית --------------------------//
class Queue {
public:
	virtual void clear() = 0;
	virtual void enqueue(int value) = 0;
	virtual int dequeue() = 0;
	virtual int front() = 0;
	virtual bool isEmpty() const = 0;
};
