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

///---------------------------------------- Vector ����� ���� ����� ���� �� ------------------------------------------///

//---------- Vector ����� ������ ------------//

class Vector {
			
private:

	int* data; // ����� ����� �� �����
	int capacity; // ���� ������� - �� ������� ��������� ������� �����
	int size; // �� ������ ������� ����� �������


public:

	//------------------------- ���������� ����� ����� -------------------------------//
	Vector(int vector_size) {

		data = new int[vector_size]; //����� �������
		this->capacity = vector_size;
		this->size = 0;

	}

	//-------------- ���������� ��� ���� ����� ------------//
	Vector() {
		this->capacity = 2;
		data = new int[this->capacity];
		this->size = 0;
	}


	//------------------ ���� ���������� --------------------//
	Vector(const Vector& vect) {

		//--- ����� ����� ----//
		this->capacity = vect.capacity;
		this->size = vect.size;

		//---- ����� ����� ----//
		this->data = new int[vect.capacity];
		for (int i = 0; i < vect.capacity; i++) {
			*(this->data + i) = *(vect.data + i);
		}
	}


	//--------------------- ��������� ----------------------//
	~Vector() {
		if (data) {
			delete[] data;
		}
		data = NULL;
	}


	//--------------------- ����� �����  ---------------------//

//------ capacity �� -------//
	int getCapacity() {
		return this->capacity;
	}

	//------ size �� -------//
	int getSize() {
		return this->size;
	}


	//-------------------- ����� ����� -----------------------//
	void print() {

		cout << "capacity: " << this->capacity << " size: " << this->size << " values: ";
		for (int i = 0; i < this->size; i++) {
			cout << this->data[i] << " ";
		}
		cout << endl;
	}

	//----------------------------- "=" ����� ������ ������ ������ -------------------------------//
	void assign(Vector new_vector) {
		
		this->capacity = new_vector.capacity;
		this->size = new_vector.size;

		delete[]data;
		data = new int[new_vector.size];
		for (int i = 0; i < new_vector.size; i++) {
			this->data[i] = new_vector.data[i];
		}
	}


	//-------- "==" ����� �� ��� �������� ���� ������ �������� ---------//
	bool isEqual(Vector new_vector) {
		if (this->size == new_vector.size && this->capacity == new_vector.capacity) {
			return true;
		}
		else {
			return false;
		}
	}



	//------------------ "[]" ����� �� ��� �������� ���� ������ �������� ---------------------//
	int& at(int index) {

		//--- ����� �������� ���� ����� ����� ������ ---//
		if (this->size < index || index < 0) {
			cout << "ERROR " << endl;
			return this->data[0]; // ����� ��� ������
		}

		return *(data + index);
	}


	//-------------------------- ����� ������� ��� ��� �������� ------------------------------//
	int strcatcat(Vector new_vector) {

		int dot_product = 0;

		if (this->size != new_vector.size) {
			cout << "ERROR " << endl;
			return -1;
		}


		for (int i = 0; i < this->size; i++) {

			//----- ����� ����� ������� ------//
			dot_product += (this->data[i] * new_vector.data[i]);
		}
		return dot_product;
	}


	//---------------------------------- ������ ��� �������� -------------------------------//
	Vector strnewcat(Vector another_vector) {

		//------- ����� ���� ����� ��� ��������� --------//
		int length = this->capacity + another_vector.capacity;
		Vector viki(length); // ����� ������ ���
		viki.size = this->size + another_vector.size; // ����� ���� �������

		int i = 0;
		//---- ����� ������� ������ -----//
		for (i = 0; i < this->size; i++) {
			viki.data[i] = this->data[i];
		}

		//----- ������ ������� ���� -----//
		for (int j = 0; i < length; j++, i++) {
			viki.data[i] = another_vector.data[j];
		}

		return viki;
	}



	//------------------------------- ����� ����� ����� ---------------------------------//
	void clear() {
		this->size = 0; // ����� ����� ��� ���� ����� ������
	}



	//------------------------------ ����� ����� ������ --------------------------------//
	void delLast() {
		
		if (this->size == 0) {
			cout << "ERROR" << endl;
		}
		else {
			this->size--;
		}
	
	}


	//--------------------- ����� ����� ����� val ����� ----------------------------//
	int* insert(int val) {

		//----- �� ��� ���� ���� ����� -----//
		if (this->capacity == this->size) {

			this->capacity = (this->capacity * 2); // ����� ������� 
			int* arr2 = new int[this->capacity]; // ����� ����� �� 2

			//--- ����� ������� ����� ������ ---//
			for (int i = 0; i < this->size; i++) {
				arr2[i] = this->data[i];
			}
			arr2[this->size] = val; // ����� ��� ����� ����� val ����� 
			this->size++;

			delete[]data;
			data = arr2;
			return data;
		}

		//------ ����� ��� ���� ���� ����� ------//
		else {
			this->data[this->size] = val; // ����� ��� ����� ����� val ����� 
			this->size++; // ����� ���� ����� 
		}

		return this->data;

	}
};
