/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 8          *
* Seif: I                    *
******************************/
#include "List.h"
#include <iostream>

///------------------------------------------------ List של cpp - אנחנו בקובץ ה -----------------------------------------------------///

//---------------------------------\\
//  class Link implementation      \\
//---------------------------------\\

//-------------- Link קונסטרקטור של  -------------//
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {
}

//---------- Link קופי קונסטרקטור של --------------//
List::Link::Link(const Link& source) : value(source.value), next(source.next) {
}



//-------------------------------\\
//  class List implementation    \\
//-------------------------------\\


//--------------- קונסטרקטור ---------------------//
List::List() : head(NULL) {
	// no further initialization
}


//-------------- קופי קונסטרקטור ----------------//
List::List(const List& l) {

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
	}
}


//--------------------- דיסטרקטור ----------------------//
List::~List() {
	clear();
}




//------------------ מחיקת כל הרשימה --------------------//
void List::clear() {

	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != NULL; p = theNext) {
		// delete the element pointed to by p
		theNext = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}



//---------------- בדיקה אם הרשימה ריקה -----------------//
bool List::isEmpty() const {
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == NULL;
}

//---------------- הוספת איבר חדש לרשימה -----------------//
void List::add(int val) {
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}


//----------- של הצומת הראשון key החזרת ה -------------//
int List::firstElement() const {
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return  this->head->value;
}


//----------------- חיפוש נתון ברשימה -------------------//
bool List::search(const int& val) const {
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}



//------------- מחיקת האיבר הראשון ברשימה ---------------//
void List::removeFirst() {
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}


//---------------------- = אופרטור שווה -------------------------//
List List::operator=(const List my_list) {

	Link* src, * trg;

	if (my_list.head == NULL) {
		this->head = NULL;
	}

	else {
		this->head = new Link((my_list.head)->value, NULL); // בניית צומת חדש
		src = my_list.head;
		trg = this->head;

		//--- כל זמן שלא הגענו לסוף הרשימה ---//
		while (src->next != NULL) {
			trg->next = new Link((src->next)->value, NULL); // בניית צומת חדש
			src = src->next;
			trg = trg->next;
		}
	}

	return *this; //לאחר השינוי this מחזירים את 
}



//-------------------- << פונקציה חברה - אופרטור פלט -----------------------//
ostream& operator<<(ostream& lout, const List& my_list) {

	if (my_list.isEmpty()) {
		throw "The list is empty - no Element to print\n";
	}

	else {
		//------ ריצה על הרשימה ------//
		for (List::Link* ptr = my_list.head; ptr != NULL; ptr = ptr->next) {
			lout << ptr->value << " ";
		}
	}

	return lout; // cout ע"מ שנוכל לעשות שירשורים של 
}



//-------------------- >> פונקציה חברה - אופרטור קלט -----------------------//
istream& operator >> (istream& lin, List& my_list) {

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
List List::insert(int key) {

	List::Link* node = new List::Link(key, NULL);

	//--- במקרה שהרשימה ריקה ---//
	if (this->isEmpty()) {
		this->head = node;
		return *this;
	}

	//---- גדול מהאיבר הראשון key - במקרה שה ----//
	List::Link* ptr = this->head; // המצביע שלי מצביע לראש הרשימה יחד עם הד
	if (key > ptr->value) {
		this->add(key); // מכניסים לראש הרשימה
		return*this;
	}

	//---- בדיקת מיקום הערך ----//
	while (ptr->next != NULL) {
		if (key > ptr->next->value) {
			node->next = ptr->next;
			ptr->next = node;
			break; // ע"מ שברגע שהשחלנו את הצומת נצא החוצא
		}
		ptr = ptr->next; // קידום הפויינטר ברשימה
	}

	if (ptr->next == NULL) {
		ptr->next = node;
	}

	return *this;
}



//-------------------- מתודת מחיקה --------------------//
List List::remove(int key) {

	//---- הגדרת הצומת אותה אני רוצה למחוק ----//
	List::Link* node_to_remove;

	//----- אם הערך למחיקה לא נמצא -----//
	if (!this->search(key)) {
		throw "value not found \n";
	}

	//----- במידה והערך למחיקה נמצא בתא הראשון ---//
	else if (this->head->value == key) {
		this->removeFirst();
		return *this;
	}

	//---- במידה והערך לא בתא הראשון -----//
	else {
		List::Link* ptr = this->head; // הגדרת המצביע (שירוץ על הרשימה) שיצביע לראש הרשימה יחד עם הד 
		while (ptr->next->value != key) {
			ptr = ptr->next;
		}
		node_to_remove = ptr->next;
		ptr->next = node_to_remove->next;
		delete node_to_remove;
	}

	return *this;
}