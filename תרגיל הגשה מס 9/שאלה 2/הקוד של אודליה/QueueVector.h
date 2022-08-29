/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 9 Question 2*/

#pragma once
#include "Queue.h"

template <class T>
class QueueVector : public Queue<T>
{
public:
	QueueVector(int max);
	//QueueVector(const QueueVector&);
	void clear() override;
	T dequeue() override;
	T front() const override;
	void enqueue(T value) override;
	bool isEmpty() const override;
private:
	T* data;
	int capacity;
	int nextSlot; //end of the queue
	int firstUse; ///start of the queue 
};


template <class T>
QueueVector<T>::QueueVector(int size) {
	capacity = size + 1;
	data = new T[capacity]; //the array of the queue
	clear();
}


template <class T>
void QueueVector<T>::clear() {
	nextSlot = 0;
	firstUse = 0;
}


template <class T>
T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity; //promoting the ptr to the next index
	return data[dataloc];
}


template <class T>
void QueueVector<T>::enqueue(T val) {
	if ((nextSlot + 1) % capacity == firstUse) //the array is full and we can't add more el
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}


template <class T>
T QueueVector<T>::front() const {
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}


template <class T>
bool QueueVector<T>::isEmpty() const {
	return nextSlot == firstUse;
}

