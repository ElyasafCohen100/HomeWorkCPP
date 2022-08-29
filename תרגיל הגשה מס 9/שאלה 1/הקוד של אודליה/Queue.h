/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 9          *
*                            *
******************************/
#pragma once
#include <iostream>
using namespace std;
///------------------------------------------------ Queue קובץ ההדר של -----------------------------------------------------///


//---------------- Queue פתיחת המחלקה הגנרית האבסטרקטית ------------------//
template <class T>
class Queue {

public:

	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty() const = 0;
};