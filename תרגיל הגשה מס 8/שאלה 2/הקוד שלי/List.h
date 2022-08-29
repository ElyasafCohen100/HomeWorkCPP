/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#pragma once
#include<iostream>
using namespace std;
///------------------------------------------------ List ����� ����� ���� �� -----------------------------------------------------///

//------------------------------------------\\
//  class List                              \\
//      arbitrary size Lists                \\
//      permits insertion and removal       \\
//      only from the front of the List     \\
//------------------------------------------\\


//------------------------- List ����� ������ --------------------------//
class List {

protected:

	//--------------------------------------------\\
	//  inner class link                          \\
	//  a single element for the linked List      \\
	//--------------------------------------------\\

	//------------ Link ����� ������ ������ ������� --------------//
	class Link {

		//---- Link ���� ���� ����� ����� �� List-��� �� public - ������� �-----//
	public:

		//-------- ���������� -------//
		Link(int linkValue, Link* nextPtr);
		//----- ���� ���������� -----//
		Link(const Link&);


		//-------- ����� -------//
		int value; // key - ��� �
		Link* next; //�������� ����� ����
	};


public:
	//-------- ���������� --------//
	List();
	//----- ���� ���������� -----//
	List(const List&);
	//-------- ��������� --------//
	~List();



	//---------- ����� ���� ��� ������ -----------//
	void add(int value);
	//----- �� ������ ������� key ����� � -------//
	int firstElement() const;
	//----------- ����� ���� ������ -------------//
	bool search(const int& value) const;
	//---------- ����� �� ������ ���� -----------//
	bool isEmpty() const;
	//------- ����� ����� ������ ������ ---------//
	void removeFirst();
	//------------ ����� �� ������ --------------//
	void clear();



	//---------------------- = ������� ���� -------------------------//
	List operator=(const List my_list);
	//-------------------- << ������� ���� - ������� ��� -----------------------//
	friend ostream& operator<<(ostream& lout, const List& my_list);
	//-------------------- >> ������� ���� - ������� ��� -----------------------//
	friend istream& operator>>(istream& lin, List& my_list);
	//-------------------- ����� ����� --------------------//
	List insert(int key);
	//-------------------- ����� ����� --------------------//
	List remove(int key);



protected:

	Link* head; // ����� ����� ������

};