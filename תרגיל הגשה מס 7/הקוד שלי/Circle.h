/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 7          *
*                            *
******************************/
#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

///--------------------------------------------- Circle ����� ����� ���� �� -----------------------------------------------///

//--------------------------- Circle ����� ����� ���  ----------------------------//
class Circle : public Shape { // Shape - ����� � Circle ������ 

//----- ������ ������ �� ���� ---//
protected:
	float radius;
//	Point center_point; // ���� �"� ���������� ���� ���� ��� ���� ������ ���� ��

public:

	//------------------- constructor ----------------------//
	Circle(float my_radius);
	//--------- �� ����� ------------//
	float getRadius();
	//--------- �� ����� -----------//
	void setRadius(float my_radius);



	//--------------------- ������� ����������� ������� �� ���� --------------------------//

	//------------------- ����� ��� --------------------//
	virtual float area()const override;
	//------------------- ����� ����� ������ --------------------//
	virtual bool isSpecial()const override;
	//------------------- ������ ������� ���� ����� --------------------//
	virtual void printSpecial()const override;
};

