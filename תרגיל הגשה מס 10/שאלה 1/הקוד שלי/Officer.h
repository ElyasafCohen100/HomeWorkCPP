/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 10         *
*                            *
******************************/
#pragma once
#include"Soldier.h"
using namespace std;
///--------------------------------------------- Officer אנחנו בקובץ ההדר של -----------------------------------------------///

/*
מחלקת קציו
*/


//--------------------------- Officer פתיחת מחלקת הבן  ----------------------------//
class Officer : public Soldier { // Soldier - יורשת מ Officer המחלקה

private:
	int Sociometric_score; // תכונה עבור ציון סוציומטרי

public:

	//----------- דיפולט קונסטורקטור --------------//
	Officer();
	//---------- קונסטרקטור המקבל ערכים ---------//
	Officer(int my_taz, string my_first_name, string my_last_name, int my_num_operation);


	//------- מתודת הדפסה ---------//
	virtual void print()const;
	//-------- סוג החייל -----------//
	virtual string string_soldierType() const override;
	//------ Sociometric_score ויראטולית גט ------//
	virtual int get_Sociometric_score();


	//-------------- Soldier המתודות הוירטואליות הטהורות של האבא ------------------//

	//-------- זכאות לצלש ---------//
	virtual bool medal() const override;

};