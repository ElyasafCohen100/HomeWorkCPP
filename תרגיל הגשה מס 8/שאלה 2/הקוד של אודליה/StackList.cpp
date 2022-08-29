/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/

#include "StackList.h"

//-------------------------------------------------------
//  class StackList implementation
//-------------------------------------------------------
StackList::StackList() : data()
{
    //Create and initialize a Stack based on Lists.
}


StackList::StackList(const StackList& lst) : data(lst.data)
{    //Copy constructor.
}


void StackList::clear()
{
    //Clear all elements from Stack, by setting.
    //Delete all values from List.
    data.clear();
}


bool StackList::isEmpty() const
{    //Return true if Stack is empty.
    return data.isEmpty();
}


int StackList::pop()
{
    //Return and remove the topmost element in the Stack.
    //Get first element in List.
    int result = data.firstElement();
    //Remove element from List.
    data.removeFirst();
    //Return value.
    return result;
}


void StackList::push(int val)
{
    //Push new value onto Stack.
    data.add(val);
}


int StackList::top() const
{
    return data.firstElement();
}

