/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 6          *
* Seif: II                   *
******************************/
#include "RoundList.h"
#include "List.h"
#include<iostream>
using namespace std;
///------------------------------------------------ RoundList של cpp - אנחנו כרגע בקובץ ה -----------------------------------------------------///

//---------------------- קונסטרקטור --------------------------//
RoundList::RoundList() :List() {
}


//-------------------- קופי קונסטרקטור ---------------------//
RoundList::RoundList(const RoundList& l) {
	Link* src, * trg;

	//--- במידה ואין רשימה ---//
	if (l.head == NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((l.head)->value, NULL); // בניית צומת חדש
		src = l.head;
		trg = this->head;

		//--- כל זמן שלא הגענו לסוף הרשימה ---//
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL); // בניית צומת חדש
			src = src->next;
			trg = trg->next;
		}
		trg->next = head;
	}
}



//----------------------- דיסטרקטור -------------------------//
RoundList::~RoundList() {
	clear();
}




//--------------- הוספת איבר בראש הרשימה ---------------//
void RoundList::addToEnd(int val) {

	List::Link* ptr = this->head;

	//----- במידה והרשימה ריקה -----//
	if (this->isEmpty()) {
		this->head = new List::Link(val, NULL); // פתיחת צומת חדש
		this->head->next = this->head; // נקסט מצביע על הצומת הראשון כי זאת רשימה מעגלית
	}

	else {
		while (ptr->next != this->head) {
			ptr = ptr->next;
		}

		//--- פתיחת צומת חדש בחוליה האחרונה כאשר המצביע מצביע להתחלה ----//
		ptr->next = new List::Link(val, this->head);
	}
}


//---- n והחזרת ערך האיבר הנמצא במקום n חיפוש ברשימה את האיבר ---//
int RoundList::search(int n) {

	if (this->isEmpty()) {
		return -1;
	}

	else if (!this->isEmpty()) {
		//List::Link* node = new List::Link(n, NULL); // הגדרת הצומת אותו נוסיף
		List::Link* ptr = this->head; // הגדרת מצביע לראש הרשימה

		for (int i = 1; i <= n; i++) {
			ptr = ptr->next;
		}

		int save = ptr->value; 
		ptr = NULL;
		return save;
	}
}


//---------------- הוספת איבר חדש לרשימה -----------------//
void RoundList::add(int val) {

	List::Link* ptr = this->head; // מצביע על ראש הרשימה ptr

	if (this->isEmpty()) {
		this->head = new Link(val, NULL);
		this->head->next = this->head;
	}
	else {
		this->head = new Link(val, this->head);

		//---- כל זמן שערך הצומת השני שונה מערך הצומת שאחריו ----//
		for (; ptr->next != this->head->next; ptr = ptr->next);
		ptr->next = this->head; // עדכון הצומת האחרון שיצביע לראש הרשימה
	}

	ptr = NULL;
}
	


//----------------- חיפוש נתון ברשימה -------------------//
bool RoundList::search(const int& val) const {

	Link* ptr = this->head; //שיצביע לראש הרשימה ptr הגדרת 

	//--- כל זמן שהרשימה המעגלית לא הסתיימה -----//
	while (ptr->next != this->head) {
		if (val == ptr->value) {
			return true;
		}
	}
	return false;
}


//------- מחיקת האיבר הראשון ברשימה ---------//
void RoundList::removeFirst() {
	
	if (isEmpty()) {
		throw "the List is empty, no Elements to remove";
	}
	else {

		//----- במידה ויש לי צומת יחיד ברשימה -----//
		if (this->head == this->head->next) {
			List::removeFirst(); // מחיקת הצומת הראשון
			this->head = NULL;
		}

		else {
			Link* ptr = this->head;

			//----- קידום הפויינטר לסוף הרשימה -----//
			for (ptr = this->head; ptr->next != this->head; ptr = ptr->next);
			List::removeFirst(); // קריאה לפונקציה של האבא לגימורים
			ptr->next = this->head; // החדש head - הצומת האחרון מצביע על ה
			ptr = NULL;
		}
	}
}





//------------ מחיקת כל הרשימה --------------//
void RoundList::clear() {

	Link* ptr = this->head;
	
	if (!this->isEmpty()) {

		//----- קידום הפויינטר לסוף הרשימה -----//
		for (ptr = this->head; ptr->next != this->head; ptr = ptr->next);
		ptr->next = NULL; // הפיכת הרשימה המעגלית לרשימה לנארית
		List::clear(); // קריאה לפונקציה של האבא
	}
	//else {
	//	throw "the list is empty so there is nothing to detete\n";
	//}
}




//---------------------- = אופרטור שווה -------------------------//
RoundList RoundList::operator=(const RoundList my_list) {

	Link* src, * trg;

	if (my_list.head== NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((my_list.head)->value, NULL); // בניית צומת חדש
		src = my_list.head;
		trg = this->head;

		//--- כל זמן שלא הגענו לסוף הרשימה ---//
		while (src->next != this->head) {
			trg->next = new Link((src->next)->value, NULL); // בניית צומת חדש
			src = src->next;
			trg = trg->next;
		}
		trg->next = this->head; // head - הצומת האחרון מצביע ל
	}

	return *this; //לאחר השינוי this מחזירים את 
}




//-------------------- << פונקציה חברה - אופרטור פלט -----------------------//
ostream& operator<<(ostream& lout, const RoundList& my_list) {

	if (my_list.isEmpty()) {
		throw "The list is empty - no Element to print\n";
	}

	else {
		//------ ריצה על הרשימה ------//
		for (List::Link* ptr = my_list.head; ptr != my_list.head; ptr = ptr->next) {
			lout << ptr->value << " ";
		}
	}

	return lout; // cout ע"מ שנוכל לעשות שירשורים של 
}


//-------------------- >> פונקציה חברה - אופרטור קלט -----------------------//
istream& operator >> (istream& lin, RoundList& my_list) {

	my_list.clear(); // בגלל שמדובר בהקצאה דינאמית אז אני מעוניין למחוק את הזיכרון ולא לדרוס אותו

	int value;
	lin >> value;

	//--- הכנסת הערך הראשוני ---//
	my_list.add(value);

	List::Link* ptr = my_list.head; // הגדרת מצביע שירוץ על הרשימה

	//--- המשך בניית הרשימה ----//
	lin >> value;
	while ((value < ptr->value)) { // כל זמן שמתקבל ערך קטן ממש
		ptr->next = new List::Link(value, NULL); // פתיחת צומת עם הערכים שהמשתמש הכניס
		ptr = ptr->next;
		lin >> value;
	}

	return lin;
}


//-------------------- מתודת הכנסה --------------------//
List RoundList::insert(int key) {


	List::Link* node = new List::Link(key, NULL);

	//--- במקרה שהרשימה ריקה ---//
	if (this->isEmpty()) {
		this->head = node;
		node->next = this->head;
		return *this;
	}

	//---- גדול מהאיבר הראשון key - במקרה שה ----//
	List::Link* ptr = this->head; // המצביע שלי מצביע לראש הרשימה יחד עם הד
	if (key > ptr->value) {
		this->add(key); // מכניסים לראש הרשימה	
		return*this;
	}

	//---- בדיקת מיקום הערך ----//
	while (ptr->next != this->head) {
		if (key > ptr->next->value) {
			node->next = ptr->next;
			ptr->next = node;
			break; // ע"מ שברגע שהשחלנו את הצומת נצא החוצא
		}
		ptr = ptr->next; // קידום הפויינטר ברשימה
	}
	
	if (ptr->next == NULL) {
		ptr->next = node;
		node->next = this->head;
	}

	return *this;
}
