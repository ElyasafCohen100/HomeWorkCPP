/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 9 Question 2*/

#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
};