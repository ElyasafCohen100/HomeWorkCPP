/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#pragma once
class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;
};