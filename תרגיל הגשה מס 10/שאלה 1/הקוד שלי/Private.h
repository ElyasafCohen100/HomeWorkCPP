/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Soldier.h"
#include<vector> // STL ����� ������� �� 
using namespace std;
///--------------------------------------------- Private ����� ����� ���� �� -----------------------------------------------///

/*
����� �����
*/


//--------------------------- Private ����� ����� ���  ----------------------------//
class Private : public Soldier { // Soldier - ����� � Private ������

protected:
	vector<int> ptr_grade;// STL ����� ���� ��

public:

	//----------- ������ ���������� ----------//
	Private();
	//------- ���������� ����� ����� --------//
	Private(int my_taz, string my_first_name, string my_last_name, int my_num_operation);
	//--------------- ���������--------------//
	~Private();
	//-------------- ����� ����� -----------//
	float average()const;



	//-------------- Soldier ������� ����������� ������� �� ���� ------------------//

	//-------- ����� ���� ---------//
	virtual bool medal()const override;
	//------- ����� ����� ---------//
	virtual void print()const override;


	//-------- ��� ����� -----------//
	virtual string string_soldierType() const override;

};