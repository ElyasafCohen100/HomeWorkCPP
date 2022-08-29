/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Private.h"
using namespace std;
///------------------------------------------------- Commander ����� ����� ���� �� ---------------------------------------------------///

/*
����� ����
*/

//--------------------------- Commander ����� ����� ���  ----------------------------//
class Commander : public Private { // Private - ����� � Commander ������

protected:
	bool fighter; // ����

public:

	//----------- ������ ����������� --------------//
	Commander();
	//---------- ���������� ����� ����� ---------//
	Commander(int my_taz, string my_first_name, string my_last_name, int my_num_operation);
	//---------------- ��������� ----------------//
	~Commander();


	//-------- ����� ���� ---------//
	virtual bool medal()const override;
	//---------- ����� -------------//
	virtual void print()const;


	//-------- ��� ����� -----------//
	virtual string string_soldierType() const;

	//----------- fighter ��������� �� -----------//
	virtual bool get_fighter();


	/*
	������ Soldier ��� ����� ��������� ������� �� �����
	Soldier ������ ���� ����� ������ ����� ��� ������
	*/

};
