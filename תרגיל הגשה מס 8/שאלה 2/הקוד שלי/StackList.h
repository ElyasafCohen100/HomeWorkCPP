/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: II                   *
******************************/
#include "List.h"
#include "Stack.h"
///--------------------------------------------- StackList ����� ����� ���� �� --------------------------------------------------///


// ����� ������ ������� ����� ������ //


//--------------------------------------------//
//  class StackList                           //
//  Stack implemented using List operations   //
//--------------------------------------------//

class StackList : public Stack { // Stack - ����� � StackList ������

public:

	//----------- ���������� ------------//
	StackList();
	//-------- ���� ���������� ---------//
	StackList(const StackList&);



	//--------------------- Stack ����� �������� ����������� ������� �� ���� ----------------------//

	//----------- ����� ������� --------------//
	void clear() override;
	//------- ����� �� ������� ���� --------//
	bool isEmpty() const override;
	//--------- ����� �������� ------------//
	int pop() override;
	//----------- ����� ������� ------------//
	void push(int value)override;
	//-------- ���� ���� ������� ----------//
	int top() const override;


protected:
	// data fields
	List data;
};
