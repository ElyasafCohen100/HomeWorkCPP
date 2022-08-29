/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: II                   *
******************************/
#include "RoundList.h"
#include "List.h"
#include<iostream>
using namespace std;
///------------------------------------------------ RoundList �� cpp - ����� ���� ����� � -----------------------------------------------------///

//---------------------- ���������� --------------------------//
RoundList::RoundList() :List() {
}


//-------------------- ���� ���������� ---------------------//
RoundList::RoundList(const RoundList& l) {
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
		trg->next = head;
	}
}



//----------------------- ��������� -------------------------//
RoundList::~RoundList() {
	clear();
}




//--------------- ����� ���� ���� ������ ---------------//
void RoundList::addToEnd(int val) {

	List::Link* ptr = this->head;

	//----- ����� ������� ���� -----//
	if (this->isEmpty()) {
		this->head = new List::Link(val, NULL); // ����� ���� ���
		this->head->next = this->head; // ���� ����� �� ����� ������ �� ��� ����� ������
	}

	else {
		while (ptr->next != this->head) {
			ptr = ptr->next;
		}

		//--- ����� ���� ��� ������ ������� ���� ������ ����� ������ ----//
		ptr->next = new List::Link(val, this->head);
	}
}


//---- n ������ ��� ����� ����� ����� n ����� ������ �� ����� ---//
int RoundList::search(int n) {

	if (this->isEmpty()) {
		return -1;
	}

	else if (!this->isEmpty()) {
		//List::Link* node = new List::Link(n, NULL); // ����� ����� ���� �����
		List::Link* ptr = this->head; // ����� ����� ���� ������

		for (int i = 1; i <= n; i++) {
			ptr = ptr->next;
		}

		int save = ptr->value; 
		ptr = NULL;
		return save;
	}
}


//---------------- ����� ���� ��� ������ -----------------//
void RoundList::add(int val) {

	List::Link* ptr = this->head; // ����� �� ��� ������ ptr

	if (this->isEmpty()) {
		this->head = new Link(val, NULL);
		this->head->next = this->head;
	}
	else {
		this->head = new Link(val, this->head);

		//---- �� ��� ���� ����� ���� ���� ���� ����� ������ ----//
		for (; ptr->next != this->head->next; ptr = ptr->next);
		ptr->next = this->head; // ����� ����� ������ ������ ���� ������
	}

	ptr = NULL;
}
	


//----------------- ����� ���� ������ -------------------//
bool RoundList::search(const int& val) const {

	Link* ptr = this->head; //������ ���� ������ ptr ����� 

	//--- �� ��� ������� ������� �� ������� -----//
	while (ptr->next != this->head) {
		if (val == ptr->value) {
			return true;
		}
	}
	return false;
}


//------- ����� ����� ������ ������ ---------//
void RoundList::removeFirst() {
	
	if (isEmpty()) {
		throw "the List is empty, no Elements to remove";
	}
	else {

		//----- ����� ��� �� ���� ���� ������ -----//
		if (this->head == this->head->next) {
			List::removeFirst(); // ����� ����� ������
			this->head = NULL;
		}

		else {
			Link* ptr = this->head;

			//----- ����� �������� ���� ������ -----//
			for (ptr = this->head; ptr->next != this->head; ptr = ptr->next);
			List::removeFirst(); // ����� �������� �� ���� ��������
			ptr->next = this->head; // ���� head - ����� ������ ����� �� �
			ptr = NULL;
		}
	}
}





//------------ ����� �� ������ --------------//
void RoundList::clear() {

	Link* ptr = this->head;
	
	if (!this->isEmpty()) {

		//----- ����� �������� ���� ������ -----//
		for (ptr = this->head; ptr->next != this->head; ptr = ptr->next);
		ptr->next = NULL; // ����� ������ ������� ������ ������
		List::clear(); // ����� �������� �� ����
	}
	//else {
	//	throw "the list is empty so there is nothing to detete\n";
	//}
}




//---------------------- = ������� ���� -------------------------//
RoundList RoundList::operator=(const RoundList my_list) {

	Link* src, * trg;

	if (my_list.head== NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((my_list.head)->value, NULL); // ����� ���� ���
		src = my_list.head;
		trg = this->head;

		//--- �� ��� ��� ����� ���� ������ ---//
		while (src->next != this->head) {
			trg->next = new Link((src->next)->value, NULL); // ����� ���� ���
			src = src->next;
			trg = trg->next;
		}
		trg->next = this->head; // head - ����� ������ ����� �
	}

	return *this; //���� ������ this ������� �� 
}




//-------------------- << ������� ���� - ������� ��� -----------------------//
ostream& operator<<(ostream& lout, const RoundList& my_list) {

	if (my_list.isEmpty()) {
		throw "The list is empty - no Element to print\n";
	}

	else {
		//------ ���� �� ������ ------//
		for (List::Link* ptr = my_list.head; ptr != my_list.head; ptr = ptr->next) {
			lout << ptr->value << " ";
		}
	}

	return lout; // cout �"� ����� ����� �������� �� 
}


//-------------------- >> ������� ���� - ������� ��� -----------------------//
istream& operator >> (istream& lin, RoundList& my_list) {

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
List RoundList::insert(int key) {


	List::Link* node = new List::Link(key, NULL);

	//--- ����� ������� ���� ---//
	if (this->isEmpty()) {
		this->head = node;
		node->next = this->head;
		return *this;
	}

	//---- ���� ������ ������ key - ����� �� ----//
	List::Link* ptr = this->head; // ������ ��� ����� ���� ������ ��� �� ��
	if (key > ptr->value) {
		this->add(key); // ������� ���� ������	
		return*this;
	}

	//---- ����� ����� ���� ----//
	while (ptr->next != this->head) {
		if (key > ptr->next->value) {
			node->next = ptr->next;
			ptr->next = node;
			break; // �"� ����� ������� �� ����� ��� �����
		}
		ptr = ptr->next; // ����� �������� ������
	}
	
	if (ptr->next == NULL) {
		ptr->next = node;
		node->next = this->head;
	}

	return *this;
}
