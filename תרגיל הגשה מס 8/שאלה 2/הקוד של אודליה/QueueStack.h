/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#pragma once
#include "Queue.h"
#include "Stack.h"
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};

