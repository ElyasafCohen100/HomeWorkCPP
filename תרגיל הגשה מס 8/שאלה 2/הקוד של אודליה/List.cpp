/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 8 Question 2*/


#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(NULL)
{
	//No further initialization.
}

//Copy constructor.
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List()
{
	clear();
}

void List::clear()
{
	//Empty all elements from the List.
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext)
	{
		//Delete the element pointed to by p.
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	//Mark that the List contains no elements.
	head = NULL;
}


bool List::isEmpty() const
{
	//Test to see if the List is empty
	//List is empty if the pointer to the head
	//Link is null
	return head == NULL;
}


void List::add(int val)
{
	//Add a new value to the front of a Linked List.
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}


int List::firstElement() const
{
	//Return first value in List.
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}


bool List::search(const int& val) const
{
	//Loop to test each element.
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	//Not found.
	return false;
}


void List::removeFirst()
{
	//Make sure there is a first element.
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	//Save pointer to the removed node.
	Link* p = head;
	//Reassign the first node.
	head = p->next;
	p->next = NULL;
	//Recover memory used by the first element.
	delete p;
}

//This method receives a key and insert it in the appropriate place in the sorted list.
void List::insert(int key)
{
	if (isEmpty() || key >= head->value)//Checks whether the list is empty,or the value is greater than the value of the head of the list.
		add(key);
	else
	{
		Link* p;
		for (p = head; p->next != NULL && p->next->value > key; p = p->next);
		if (p->next == NULL)
			p->next = new Link(key, NULL);
		else
		{
			Link* q = new Link(key, p->next);
			p->next = q;
		}
	}
}

//This method receives a key and if the key value exists in the list,the method deletes it from the list while maintaining the sort of the list.
void List::remove(int key)
{
	bool flag = true;
	if (key == firstElement())
		removeFirst();
	else
	{
		Link* q = head;
		if (search(key))//Checks whether the value is in the list.
		{
			for (Link* p = head; p != NULL && flag; p = p->next)
			{
				q = p->next;
				if (q->value == key)
				{
					flag = false;
					q = p->next;
					p->next = q->next;
					q->next = NULL;
					delete q;
				}
			}
		}
		else
			throw "value not found";
	}
}

//This method assigns a linked list.
List List::operator=(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}