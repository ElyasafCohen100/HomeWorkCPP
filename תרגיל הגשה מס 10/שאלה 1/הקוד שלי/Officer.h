/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Soldier.h"
using namespace std;
///--------------------------------------------- Officer ����� ����� ���� �� -----------------------------------------------///

/*
����� ����
*/


//--------------------------- Officer ����� ����� ���  ----------------------------//
class Officer : public Soldier { // Soldier - ����� � Officer ������

private:
	int Sociometric_score; // ����� ���� ���� ���������

public:

	//----------- ������ ����������� --------------//
	Officer();
	//---------- ���������� ����� ����� ---------//
	Officer(int my_taz, string my_first_name, string my_last_name, int my_num_operation);


	//------- ����� ����� ---------//
	virtual void print()const;
	//-------- ��� ����� -----------//
	virtual string string_soldierType() const override;
	//------ Sociometric_score ��������� �� ------//
	virtual int get_Sociometric_score();


	//-------------- Soldier ������� ����������� ������� �� ���� ------------------//

	//-------- ����� ���� ---------//
	virtual bool medal() const override;

};