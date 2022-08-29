/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Soldier.h"
#include<vector> // STL נשתמש בווקטור של 
using namespace std;
///--------------------------------------------- Private אנחנו בקובץ ההדר של -----------------------------------------------///

/*
מחלקת טירון
*/


//--------------------------- Private פתיחת מחלקת הבן  ----------------------------//
class Private : public Soldier { // Soldier - יורשת מ Private המחלקה

protected:
	vector<int> ptr_grade;// STL פתיחת מערך של

public:

	//----------- דיפולט קונסטרקטור ----------//
	Private();
	//------- קונסטרקטור המקבל ערכים --------//
	Private(int my_taz, string my_first_name, string my_last_name, int my_num_operation);
	//--------------- דיסטרקטור--------------//
	~Private();
	//-------------- חישוב ממוצע -----------//
	float average()const;



	//-------------- Soldier המתודות הוירטואליות הטהורות של האבא ------------------//

	//-------- זכאות לצלש ---------//
	virtual bool medal()const override;
	//------- מתודת הדפסה ---------//
	virtual void print()const override;


	//-------- סוג החייל -----------//
	virtual string string_soldierType() const override;

};