/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: I                    *
******************************/
#include "List.h"
#include "Stack.h"
///--------------------------------------------- StackList אנחנו בקובץ ההדר של --------------------------------------------------///

//--------------------------------------------//
//  class StackList                           //
//  Stack implemented using List operations   //
//--------------------------------------------//

class StackList : public Stack { // Stack - יורשת מ StackList המחלקה

public:

	//----------- קונסטרקטור ------------//
	StackList();
	//-------- קופי קונסטרקטור ---------//
	StackList(const StackList&);



	//--------------------- Stack מימוש הפוקציות הוירטואליות הטהורות של האבא ----------------------//

	//----------- מחיקת המחסנית --------------//
	void clear() override;
	//------- בדיקה אם המחסנית ריקה --------//
	bool isEmpty() const override;
	//--------- הוצאה מהמחסנית ------------//
	int pop() override;
	//----------- דחיפה למחסנית ------------//
	void push(int value) override;
	//-------- הצצה לראש המחסנית ----------//
	int top() const override;


protected:
	// data fields
	List data;
};
