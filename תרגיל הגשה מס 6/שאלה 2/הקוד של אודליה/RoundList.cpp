/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 2*/

#include "RoundList.h"

RoundList::RoundList():head(NULL) //ctor
{}


RoundList::RoundList(const RoundList& l) //copy-ctor
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != l.head)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
		trg->next = head;
	}
}


RoundList::~RoundList()//dctor
{
	clear(); // delete all the el at the list
}


void RoundList::clear()
{
	if (!isEmpty())
	{
		Link* p;
		for (p = List::head; p->next != head; p = p->next);
		p->next = NULL;
		List::clear();
	}
}



void RoundList::add(int val)
{
	List::add(val);
	if (head == NULL)
	{//If we added the first and the only node
		List::head->next = List::head;
		head = List::head;
	}
	else
	{//We will change the pointer of the last ode to the new node, which we added to thebeginning
		Link* p = head->next;
		for (p; p->next != head; p = p->next);
		p->next = List::head;
		head = List::head;
	}
}

void RoundList::removeFirst()
{
	if (!isEmpty())
	{
		Link* p = head->next;
		if (p == head)
			clear();
		else
		{
			for (p; p->next != head; p = p->next);
			head = head->next;
			p->next = head;
			List::removeFirst();
		}
	}
}



RoundList RoundList::operator=(const RoundList& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != l.head)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
		trg->next = head;
	}
	return *this;
}



ostream& operator<<(ostream& os, const RoundList& myList)
{
	for (List::Link* p = myList.head; p -> next != myList.head; p = p->next)
	{
		os << p->value << " ";
	}
	return os;
}



istream& operator>>(istream& is, RoundList& myList)
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
		p->next = myList.head;
	}
	return is;
}


void RoundList::insert(int key)
{

	if (isEmpty() || key >= head->value)// if key is bigger then the first element of the list
		add(key);
	else
	{
		Link* p;
		for (p = head; p->next != head && p->next->value > key; p = p->next);
		if (p->next == head)
			p->next = new Link(key, head);
		else
		{
			Link* q = new Link(key, p->next);
			p->next = q;
		}
	}
}


void RoundList::remove(int key)
{
	if (key == firstElement()) //if we want to delete the first element at the list
		removeFirst();
	else
	{
		Link* ptr = head;
		if (search(key) >= 0) //if key is in the list
		{
			for (Link* prev = head; prev -> next != head; prev = prev->next)
			{
				ptr = ptr->next;
				if (ptr->value == key)
				{
					if (ptr->next = head)
					{
						prev->next = head;
						ptr->next = NULL; //remove the link from the list
						delete ptr; //delete the value of the link that was removed
					}
					else
					{
						prev-> next = ptr -> next;
						ptr->next = NULL; //remove the link from the list
						delete ptr; //delete the value of the link that was removed
					}
					break; // delete only the first link that equal to key
				}
			}
		}
		else
			throw "value not found";
	}
}



void RoundList::addToEnd(int val)
{
	if (isEmpty())
		add(val);
	else
	{
		Link* p;
		for (p = head; p->next != head; p = p->next);
		p->next = new Link(val, head);
	}
}


int RoundList::search(int n)
{
	if (isEmpty())
		return -1;
	
	Link* p = List::head;
	for (int i = 0; i < n; p = p->next, i++);
	return p->value;

}
