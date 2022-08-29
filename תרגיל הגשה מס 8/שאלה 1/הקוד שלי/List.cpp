/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: I                    *
******************************/
#include "List.h"
#include <iostream>

///------------------------------------------------ List �� cpp - ����� ����� � -----------------------------------------------------///

//---------------------------------\\
//  class Link implementation      \\
//---------------------------------\\

//-------------- Link ���������� ��  -------------//
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {
}

//---------- Link ���� ���������� �� --------------//
List::Link::Link(const Link& source) : value(source.value), next(source.next) {
}



//-------------------------------\\
//  class List implementation    \\
//-------------------------------\\


//--------------- ���������� ---------------------//
List::List() : head(NULL) {
	// no further initialization
}


//-------------- ���� ���������� ----------------//
List::List(const List& l) {

	Link* src, * trg;

	//--- ����� ���� ����� ---//
	if (l.head == NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((l.head)->value, NULL); // ����� ���� ���
		src = l.head;
		trg = this->head;

		//--- �� ��� ��� ����� ���� ������ ---//
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL); // ����� ���� ���
			src = src->next;
			trg = trg->next;
		}
	}
}


//--------------------- ��������� ----------------------//
List::~List() {
	clear();
}




//------------------ ����� �� ������ --------------------//
void List::clear() {

	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext) {
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}



//---------------- ����� �� ������ ���� -----------------//
bool List::isEmpty() const {
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}

//---------------- ����� ���� ��� ������ -----------------//
void List::add(int val) {
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}


//----------- �� ����� ������ key ����� � -------------//
int List::firstElement() const {
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return  this->head->value;
}


//----------------- ����� ���� ������ -------------------//
bool List::search(const int& val) const {
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}



//------------- ����� ����� ������ ������ ---------------//
void List::removeFirst() {
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


//---------------------- = ������� ���� -------------------------//
List List::operator=(const List my_list) {

	Link* src, * trg;

	if (my_list.head == NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((my_list.head)->value, NULL); // ����� ���� ���
		src = my_list.head;
		trg = this->head;

		//--- �� ��� ��� ����� ���� ������ ---//
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL); // ����� ���� ���
			src = src->next;
			trg = trg->next;
		}
	}

	return *this; //���� ������ this ������� �� 
}



//-------------------- << ������� ���� - ������� ��� -----------------------//
ostream& operator<<(ostream& lout, const List& my_list) {

	if (my_list.isEmpty()) {
		throw "The list is empty - no Element to print\n";
	}

	else {
		//------ ���� �� ������ ------//
		for (List::Link* ptr = my_list.head; ptr != NULL; ptr = ptr->next) {
			lout << ptr->value << " ";
		}
	}

	return lout; // cout �"� ����� ����� �������� �� 
}



//-------------------- >> ������� ���� - ������� ��� -----------------------//
istream& operator >> (istream& lin, List& my_list) {

	my_list.clear(); // ���� ������ ������ ������� �� ��� ������� ����� �� ������� ��� ����� ����

	int value;
	lin >> value;

	//--- ����� ���� ������� ---//
	my_list.add(value);

	List::Link* ptr = my_list.head; // ����� ����� ����� �� ������

	//--- ���� ����� ������ ----//
	lin >> value;
	while ((value < ptr->value)) { // �� ��� ������ ��� ��� ���
		ptr->next = new List::Link(value, NULL); // ����� ���� �� ������ ������� �����
		ptr = ptr->next;
		lin >> value;
	}

	return lin;
}




//-------------------- ����� ����� --------------------//
List List::insert(int key) {

	List::Link* node = new List::Link(key, NULL);

	//--- ����� ������� ���� ---//
	if (this->isEmpty()) {
		this->head = node;
		return *this;
	}

	//---- ���� ������ ������ key - ����� �� ----//
	List::Link* ptr = this->head; // ������ ��� ����� ���� ������ ��� �� ��
	if (key > ptr->value) {
		this->add(key); // ������� ���� ������
		return*this;
	}

	//---- ����� ����� ���� ----//
	while (ptr->next != NULL) {
		if (key > ptr->next->value) {
			node->next = ptr->next;
			ptr->next = node;
			break; // �"� ����� ������� �� ����� ��� �����
		}
		ptr = ptr->next; // ����� �������� ������
	}

	if (ptr->next == NULL) {
		ptr->next = node;
	}

	return *this;
}



//-------------------- ����� ����� --------------------//
List List::remove(int key) {

	//---- ����� ����� ���� ��� ���� ����� ----//
	List::Link* node_to_remove;

	//----- �� ���� ������ �� ���� -----//
	if (!this->search(key)) {
		throw "value not found \n";
	}

	//----- ����� ����� ������ ���� ��� ������ ---//
	else if (this->head->value == key) {
		this->removeFirst();
		return *this;
	}

	//---- ����� ����� �� ��� ������ -----//
	else {
		List::Link* ptr = this->head; // ����� ������ (����� �� ������) ������ ���� ������ ��� �� �� 
		while (ptr->next->value != key) {
			ptr = ptr->next;
		}
		node_to_remove = ptr->next;
		ptr->next = node_to_remove->next;
		delete node_to_remove;
	}

	return *this;
}