/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 1*/


#include "Stack.h"
#include "List.h"
#pragma once
class StackList : public Stack
{
public:
	// constructors
	StackList();
	StackList(const StackList&);
	// Stack operations
	void clear() override;
	bool isEmpty() const override;
	int pop()override;
	void push(int value) override;
	int top() const override;
protected:
	// data fields
	List data;
};