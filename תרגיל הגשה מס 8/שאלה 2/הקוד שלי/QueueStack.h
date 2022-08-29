/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#pragma once
#include"Queue.h"
#include"Stack.h"
#include<iostream>
using namespace std;
///------------------------------------------------ QueueStack ����� ����� ���� �� -----------------------------------------------------///


// ����� ��� ������� ������ //


//------------------------- QueueStack ����� ������ ���������� --------------------------//
class QueueStack : public Queue { // Queue - ����� � QueueStack ������

protected:

	Stack* data;

public:

	//------------ ���������� -----------------//
	QueueStack();
	//------------ ����� ���� ----------------//
	void clear() override;
	//------ ����� ����� ������ ����� -------//
	int dequeue() override;
	//---------- ����� ���� ���� -------------//
	void enqueue(int value) override;
	//----------- ���� ���� ���� -------------//
	int front() override;
	//---------- ����� �� ���� ��� -----------//
	bool isEmpty() const override;
};