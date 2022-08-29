/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#pragma once
#include "Employee.h"
class PartTime :public Employee
{
protected:
	int hours;
	float salaryPerHour;
public:
	PartTime(string myName = " ", int myId = 0, int mySeniority = 0, int myHours = 0, float mysalaryPerHour = 0);//ctor
	void setHours(int myHours);
	void setSalaryPerHour(float mySalaryPerHour);
	int getHours();
	int getSalaryPerHour();
	float salary();
	float salaryAfterBonus();
	friend istream& operator>>(istream& is, PartTime& p);//friend method
	friend ostream& operator<<(ostream& os, PartTime& p);//friend method
};
