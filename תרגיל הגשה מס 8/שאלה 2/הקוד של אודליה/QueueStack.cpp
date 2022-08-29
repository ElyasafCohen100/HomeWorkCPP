/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#include "QueueStack.h"
#include "StackList.h"

QueueStack::QueueStack()
{
	data = new StackList();
}


void QueueStack::clear()
{
	while (!data->isEmpty())
		data->pop();
}


int QueueStack::dequeue()
{
	return data->pop();
}


void QueueStack::enqueue(int value)
{
	StackList temp;
	while (!data->isEmpty())
		temp.push(data->pop());
	data->push(value);
	while (!temp.isEmpty())
		data->push(temp.pop());
}


int QueueStack::front()
{
	return data->top();
}


bool QueueStack::isEmpty() const
{
	return data->isEmpty();
}