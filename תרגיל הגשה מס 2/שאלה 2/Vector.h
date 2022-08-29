/*****************************
* AUTHOR: Elyasaf Cohen      *
* ID:     311557227          *
* SUBJECT: Targil 2 seif 1   *
*                            *
******************************/
#pragma once
#include <cmath>
#include<iostream>
using namespace std;

///---------------------------------------- Vector אנחנו כרגע בקובץ ההדר של ------------------------------------------///

//---------- Vector פתיחת המחלקה ------------//

class Vector {
			
private:

	int* data; // מצביע למערך של שלמים
	int capacity; // אורך הווקטור - מס האיברים המקסימאלי העכשווי במערך
	int size; // מס הערכים הנמצאים בפועל בווקטור


public:

	//------------------------- קונסטרקטור המקבל פרמטר -------------------------------//
	Vector(int vector_size) {

		data = new int[vector_size]; //הגדרת הווקטור
		this->capacity = vector_size;
		this->size = 0;

	}

	//-------------- קונסטרקטור שלא מקבל פרמטר ------------//
	Vector() {
		this->capacity = 2;
		data = new int[this->capacity];
		this->size = 0;
	}


	//------------------ קופי קונסטרקטור --------------------//
	Vector(const Vector& vect) {

		//--- העתקה רדודה ----//
		this->capacity = vect.capacity;
		this->size = vect.size;

		//---- העתקה עמוקה ----//
		this->data = new int[vect.capacity];
		for (int i = 0; i < vect.capacity; i++) {
			*(this->data + i) = *(vect.data + i);
		}
	}


	//--------------------- דיסטרקטור ----------------------//
	~Vector() {
		if (data) {
			delete[] data;
		}
		data = NULL;
	}


	//--------------------- הגדרת הגטים  ---------------------//

//------ capacity גט -------//
	int getCapacity() {
		return this->capacity;
	}

	//------ size גט -------//
	int getSize() {
		return this->size;
	}


	//-------------------- מתודת הדפסה -----------------------//
	void print() {

		cout << "capacity: " << this->capacity << " size: " << this->size << " values: ";
		for (int i = 0; i < this->size; i++) {
			cout << this->data[i] << " ";
		}
		cout << endl;
	}

	//----------------------------- "=" מתודת ההקצאה מתפקדת כפרמטר -------------------------------//
	void assign(Vector new_vector) {
		
		this->capacity = new_vector.capacity;
		this->size = new_vector.size;

		delete[]data;
		data = new int[new_vector.size];
		for (int i = 0; i < new_vector.size; i++) {
			this->data[i] = new_vector.data[i];
		}
	}


	//-------- "==" בדיקה אם שני ווקטורים זהים מתפקדת כאופרטור ---------//
	bool isEqual(Vector new_vector) {
		if (this->size == new_vector.size && this->capacity == new_vector.capacity) {
			return true;
		}
		else {
			return false;
		}
	}



	//------------------ "[]" בדיקה אם שני ווקטורים זהים מתפקדת כאופרטור ---------------------//
	int& at(int index) {

		//--- בדיקה שהאינדקס נמצא בטווח התאים המלאים ---//
		if (this->size < index || index < 0) {
			cout << "ERROR " << endl;
			return this->data[0]; // החזרת התא הראשון
		}

		return *(data + index);
	}


	//-------------------------- מכפלה סקלארית בין שני ווקטורים ------------------------------//
	int strcatcat(Vector new_vector) {

		int dot_product = 0;

		if (this->size != new_vector.size) {
			cout << "ERROR " << endl;
			return -1;
		}


		for (int i = 0; i < this->size; i++) {

			//----- חישוב מכפלה סקלארית ------//
			dot_product += (this->data[i] * new_vector.data[i]);
		}
		return dot_product;
	}


	//---------------------------------- שירשור שני ווקטורים -------------------------------//
	Vector strnewcat(Vector another_vector) {

		//------- הגדרת מערך בגדול שני הווקטורים --------//
		int length = this->capacity + another_vector.capacity;
		Vector viki(length); // הגדרת ווקטור חדש
		viki.size = this->size + another_vector.size; // הכנסת גודל לווקטור

		int i = 0;
		//---- הזרמת הווקטור הראשון -----//
		for (i = 0; i < this->size; i++) {
			viki.data[i] = this->data[i];
		}

		//----- שירשור הווקטור השני -----//
		for (int j = 0; i < length; j++, i++) {
			viki.data[i] = another_vector.data[j];
		}

		return viki;
	}



	//------------------------------- מתודת ריקון ערכים ---------------------------------//
	void clear() {
		this->size = 0; // מחיקת הגודל היא בעצם ריקון הערכים
	}



	//------------------------------ מחיקת האיבר האחרון --------------------------------//
	void delLast() {
		
		if (this->size == 0) {
			cout << "ERROR" << endl;
		}
		else {
			this->size--;
		}
	
	}


	//--------------------- במקום הפנוי במערך val הכנסת ----------------------------//
	int* insert(int val) {

		//----- אם אין מקום פנוי במערך -----//
		if (this->capacity == this->size) {

			this->capacity = (this->capacity * 2); // הגדלת הקיבולת 
			int* arr2 = new int[this->capacity]; // הגדלת המערך פי 2

			//--- הזרמת הנתונים למערך המוגדל ---//
			for (int i = 0; i < this->size; i++) {
				arr2[i] = this->data[i];
			}
			arr2[this->size] = val; // למקום הבא הפנוי במערך val הכנסת 
			this->size++;

			delete[]data;
			data = arr2;
			return data;
		}

		//------ במידה ויש מקום פנוי במערך ------//
		else {
			this->data[this->size] = val; // למקום הבא הפנוי במערך val הכנסת 
			this->size++; // עדכון גודל המערך 
		}

		return this->data;

	}
};
