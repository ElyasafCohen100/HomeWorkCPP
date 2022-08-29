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

///--------------------------------------------- Circle אנחנו בקובץ ההדר של -----------------------------------------------///

//--------------------------- Circle פתיחת מחלקת הבן  ----------------------------//
class Circle : public Shape { // Shape - יורשת מ Circle המחלקה 

//----- התכונה הנוספת של מעגל ---//
protected:
	float radius;
//	Point center_point; // נקלט ע"י קונסטרקטור האבא ולכן אין צורך להגדיר אותו פה

public:

	//------------------- constructor ----------------------//
	Circle(float my_radius);
	//--------- גט רדיוס ------------//
	float getRadius();
	//--------- סט רדיוס -----------//
	void setRadius(float my_radius);



	//--------------------- המתודות הוירטואליות הטהורות של האבא --------------------------//

	//------------------- חישוב שטח --------------------//
	virtual float area()const override;
	//------------------- בדיקת תכונה מיוחדת --------------------//
	virtual bool isSpecial()const override;
	//------------------- התכונה המיוחדת מעגל קנוני --------------------//
	virtual void printSpecial()const override;
};

