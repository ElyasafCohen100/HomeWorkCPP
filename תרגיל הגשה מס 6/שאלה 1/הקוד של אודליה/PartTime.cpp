/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#include "PartTime.h"

PartTime::PartTime(string myName, int myId, int mySeniority, int myHours, float mySalaryPerHour) :Employee(myName, myId, mySeniority)
{
	setHours(myHours);
	setSalaryPerHour(mySalaryPerHour);
}


void PartTime::setHours(int myHours)
{
	if (myHours < 0)
		throw "ERROR";
	else
		hours = myHours;
}


void PartTime::setSalaryPerHour(float mySalaryPerHour)
{
	salaryPerHour = mySalaryPerHour;
}


int PartTime::getHours()
{
	return hours;
}


int PartTime::getSalaryPerHour()
{
	return salaryPerHour;
}


float PartTime::salary()
{
	pay = salaryPerHour * hours;
	return pay;
}


float PartTime::salaryAfterBonus()
{
	Employee::salaryAfterBonus();//patrent's method class
	if (seniority > 5)
	{
		pay += 0.25 * pay;
	}
	return pay;
}


istream& operator>>(istream& is, PartTime& p)//friend method
{
	int seniority;
	int hours;
	cout << "Enter employee details:" << endl;
	is >> p.name;
	is >> p.id;
	is >> seniority;
	is >> hours;
	is >> p.salaryPerHour;
	p.setSeniority(seniority);
	p.setHours(hours);
	return is;
}


ostream& operator<<(ostream& os, PartTime& p)//friend method
{
	os << "Employee: " << p.getName() << endl;
	os << "Employee ID: " << p.getId() << endl;
	os << "Years Seniority: " << p.getSeniority() << endl;
	os << "Hours: " << p.getHours() << endl;
	os << "Salary per Month: " << p.salary() << endl;
	return os;
}
