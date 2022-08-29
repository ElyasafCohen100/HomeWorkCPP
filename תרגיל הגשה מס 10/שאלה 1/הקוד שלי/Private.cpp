/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#include"Private.h"
#include<iostream>
#include <vector>
#include <string>
using namespace std;
///---------------------------------------------------------- Private �� cpp - ����� ����� � ----------------------------------------------------------------///

/*
 ����� ����� �����
*/

//----------- ������ ���������� ----------//
Private::Private() : Soldier() {
}


//------------------------ ���������� ���� �� ������ �� ��� ����-------------------------//      //-------------- father's conctructor ---------------//
Private::Private(int my_taz, string my_first_name, string my_last_name, int my_num_operation) : Soldier(my_taz, my_first_name, my_last_name, my_num_operation) {

	if (my_num_operation > 0) {

		cout << "enter " << my_num_operation << " grades\n";
		int num;

		for (int i = 0; i < my_num_operation; i++) {
			cin >> num;
			this->ptr_grade.push_back(num);
		}
	}
}


//----------------- ���������-------------------//
Private::~Private() {
	this->ptr_grade.clear();
}



//------------------- ����� ����� --------------//
float Private::average()const {

	float sum = 0;

	//--- ��� STL ����� ������� ����� �� ���� � ----//
	vector<int>::const_iterator it = this->ptr_grade.begin();

	//---- ��� STL ���� �� ���� � -----//
	for (it = this->ptr_grade.begin(); it != this->ptr_grade.end(); it++) {
		sum += *it;
	}

	return (sum / this->ptr_grade.size());
}



//------------ ��� ����� ---------------//
string Private::string_soldierType() const {
	return "private";
}




//------------ ����� ����� ------------//
void Private::print()const {

	cout << this->string_soldierType() << endl;

	Soldier::print(); // ����� ������ ������ �� ����

	//--- ����� ������ �� ��� ----//
	cout << "grades: ";
	//--- ����� ������� ---//
	vector<int>::const_iterator it = this->ptr_grade.begin();

	for (it = this->ptr_grade.begin(); it != this->ptr_grade.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}



//------------------------------- Soldier ������ ���������� ������ �� ���� ---------------------------------//

//------------ ����� ���� --------------//
bool Private::medal() const {
	//------ ����� ���� ������� ������� ����� ��� ������ ������ ��� ------//
	if (this->num_operation >= 10 && this->average() > 95) {
		return true;
	}
	return false;
}