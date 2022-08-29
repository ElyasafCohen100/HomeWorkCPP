/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 11         *
*                            *
******************************/
#pragma once
#include <string>
using namespace std;
///------------------------------------------------ Family ����� ����� ���� ��  -----------------------------------------------------///

//---------- Family ����� ������ ------------//
class Family {

private:

	int family_number; // �� �����
	char last_name[21]; // �� �����
	int num_of_people; // �� ������ ������
	int phone_number; //�� �����
	bool classes[6]; // ���� ������

public:
	//--------------------- ������ ���������� -----------------------//
	Family();
	//------------------------ ���������� --------------------------//
	Family(int n, char*, int amount, int phone, string); //ctor

	//------------------- ����� ������ ������� ---------------------//
	int get_family_number() const;
	string get_last_name() const;
	int get_num_of_people() const;
	int get_phone_number() const;
	bool get_classes(int myIndex) const;


	void set_family_number(int my_family_number);
	void set_last_name(string my_last_name);
	void set_num_of_people(int my_num_of_people);
	void set_phone_number(int my_phone_number);
	void set_classes(bool my_bool, int my_index);

};