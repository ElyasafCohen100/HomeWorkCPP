/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 2*/

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
	// no further initialization
}



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
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}



bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}



void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}



int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}



bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}



void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}



List List::operator=(const List& right)
{
	Link* src, * trg;
	if (right.head == NULL)
		head = NULL;
	else {
		head = new Link((right.head)->value, NULL);
		src = right.head;
		trg = head;
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this;
}



ostream& operator<<(ostream& os, const List& myList)
{
	for (List::Link* p = myList.head; p != NULL; p = p->next)
	{
		os << p->value << " ";
	}
	return os;
}



istream& operator>>(istream& is, List& myList)
{
	int val;
	is >> val;
	List::Link* p = myList.head;

	if (p == NULL) // if the list is empty
	{
		myList.add(val);
		p = myList.head;
		is >> val;
	}

	if (p != NULL)
	{
		while (val < p->value) // if the list isn't empty
		{

			p->next = new List::Link(val, NULL);
			p = p->next;
			is >> val;
		}
	}
	return is;
}



void List::insert(int key)
{
	if (isEmpty() || key >= head->value)// if key is bigger then the first element of the list
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



void List::remove(int key)
{
	if (key == firstElement()) //if we want to delete the first element at the list
		removeFirst();
	else
	{
		Link* ptr = head;
		if (search(key)) //if key is in the list
		{
			for (Link* prev = head; prev != NULL; prev = prev->next)
			{
				ptr = ptr->next;
				if (ptr->value == key)
				{
					prev->next = ptr->next;
					ptr->next = NULL; //remove the link from the list
					delete ptr; //delete the value of the link that was removed
					break; // delete only the first link that equal to key
				}
			}
		}
		else
			throw "value not found";
	}
}