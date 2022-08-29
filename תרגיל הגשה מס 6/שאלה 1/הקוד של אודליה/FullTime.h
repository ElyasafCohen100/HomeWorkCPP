/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#pragma once
#include "Employee.h"
class FullTime :public Employee
{
	float salaryPerYear;
public:
	FullTime(string myName = " ", int myId = 0, int mySen = 0, float mySalaryPerYear = 0);
	void setSalaryPerYear(int mySen);
	float getSalaryPerYear()const;
	float salary();
	float salaryAfterBonus();
	friend istream& operator>>(istream& is, FullTime& f);//friend method
	friend ostream& operator<<(ostream& os, FullTime& f);//friend method
};