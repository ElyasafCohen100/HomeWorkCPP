/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#include "QueueStack.h"
#include"StackList.h"
#include<iostream>
using namespace std;
///------------------------------------------------ QueueStack �� cpp - ����� ����� � -----------------------------------------------------///

// ����� ��� ������� ������ //


//--------------- ���������� -------------------//
QueueStack::QueueStack() {
	data = new StackList; // ������ ������ ���� stack ����� ����� ���� 
}



//--------------- ����� ���� --------------------//
void QueueStack::clear() {
	this->data->clear();
}

//---------- ����� ����� ������ ����� ----------//
int QueueStack::dequeue() {

	//if (!this->data->top()) {
	//	throw "the Queue is empty\n";
	//}

	return  this->data->pop();
}


//------------- ����� ���� ���� ���� ---------------//
void QueueStack::enqueue(int value) {

	/*

	���� �����
	I'm using Move cups to keep the method of FIFO

	*/

	StackList st; // ������ ���

	//----- ����� �� ��� �������� ������ ���� ----//
	while (!this->data->isEmpty()) { // �� ��� ������� ������ ���� - ��� ��� ����� �� ����� ����
		st.push(this->data->pop()); // ����� ���� ����� 
	}

	this->data->push(value); //FIFO ����� ������� ������ �� ����� ���� ��� ����� �� 

	//----- ����� ������ ����� ���� ����� ����� �� ����� ���� ----//
	while (!st.isEmpty()) {
		this->data->push(st.pop()); // ����� ������� ������
	}
}


//----------- ���� ���� ���� -------------//
int QueueStack::front() {
	return this->data->top();
}


//---------- ����� �� ���� ��� -----------//
bool QueueStack::isEmpty() const {

	if (this->data->isEmpty()) {
		return true;
	}
	return false;
}