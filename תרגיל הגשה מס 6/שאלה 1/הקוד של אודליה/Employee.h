/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
protected:
	string name;
	int id;
	int seniority;
	float pay = 0;
public:
	Employee(string myName, int myId, int mySen); //ctor
	void setName(string);
	void setId(int);
	void setSeniority(int);
	string getName()const;
	int getId() const;
	int getSeniority()const;
	float getPay()const;
	float salaryAfterBonus();
	friend istream& operator>>(istream& is, Employee& e); //friend method
	friend ostream& operator<<(ostream& os, Employee& e); //friend method
};

