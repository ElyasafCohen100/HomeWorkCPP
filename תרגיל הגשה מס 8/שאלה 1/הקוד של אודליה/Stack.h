/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 1*/

#pragma once
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual int pop() = 0;
	virtual void push(int value) = 0;
	virtual int top() const = 0;
};