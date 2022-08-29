/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#pragma once
#include "Stack.h"
#include "List.h"
//-------------------------------------------------------
//  class StackList
//  Stack implemented using List operations
//-------------------------------------------------------
class StackList : public Stack
{
public:
    //Constructors.
    StackList();
    StackList(const StackList& s);
    //Stack operations.
    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() const override;
protected:
    //Data fields.
    List data;
};