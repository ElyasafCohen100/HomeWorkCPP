/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#include"Commander.h"
using namespace std;
///---------------------------------------------------------- Commander �� cpp - ����� ����� � ----------------------------------------------------------------///

/*
 ����� ����� ����
*/

//----------- ������ ����������� --------------//
Commander::Commander() :Private() {
	this->fighter = 0;
}


//--------------------- ���������� ���� �� ������ �� ��� ���� ---------------------//                //------------- father's conctructor -------------//
Commander::Commander(int my_taz, string my_first_name, string my_last_name, int my_num_operation) : Private(my_taz, my_first_name, my_last_name, my_num_operation) {
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> this->fighter; // ������ ���� �� ����� ���� �� ��
}


//----------------- ��������� -----------------//
Commander::~Commander() {
	this->ptr_grade.clear();
}



//---------------- ����� ���� -----------------//
bool Commander::medal()const {

	//-- ����� ���� ������� ������ ����� ��� ������ ������ ��� ��� ��� ���� --//
	if (this->num_operation >= 7 && this->average() > 90 && this->fighter == true) {
		return true;
	}

	return false;
}


//------------ ��� ����� ---------------//
string Commander::string_soldierType() const {
	return "commander";
}


//-------------- ����� -----------------//
void Commander::print()const {

	Private::print(); // ����� ������ ������ �� ����

	//--- ����� ������ �� ��� -----//
	if (this->fighter) {
		cout << "combat: yes" << endl;
	}
	else if (this->fighter == false) {
		cout << "combat: no " << endl;
	}
}

//----------- fighter ��������� �� -----------//
bool Commander::get_fighter() {
	return this->fighter;
}
