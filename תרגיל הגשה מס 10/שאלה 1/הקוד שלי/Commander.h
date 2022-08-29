/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Private.h"
using namespace std;
///------------------------------------------------- Commander אנחנו בקובץ ההדר של ---------------------------------------------------///

/*
מחלקת מפקד
*/

//--------------------------- Commander פתיחת מחלקת הבן  ----------------------------//
class Commander : public Private { // Private - יורשת מ Commander המחלקה

protected:
	bool fighter; // קרבי

public:

	//----------- דיפולט קונסטורקטור --------------//
	Commander();
	//---------- קונסטרקטור המקבל ערכים ---------//
	Commander(int my_taz, string my_first_name, string my_last_name, int my_num_operation);
	//---------------- דיסטרקטור ----------------//
	~Commander();


	//-------- זכאות לצלש ---------//
	virtual bool medal()const override;
	//---------- הדפסה -------------//
	virtual void print()const;


	//-------- סוג החייל -----------//
	virtual string string_soldierType() const;

	//----------- fighter ויראטולית גט -----------//
	virtual bool get_fighter();


	/*
	מכיוון Soldier אין מימוש לפונקציות הטהורות של מחלקת
	Soldier שמחלקת מפקד יורשת ממחלקת טירון ולא ממחלקת
	*/

};
