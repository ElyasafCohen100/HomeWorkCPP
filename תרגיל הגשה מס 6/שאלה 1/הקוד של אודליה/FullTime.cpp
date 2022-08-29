/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#include "FullTime.h"

FullTime::FullTime(string myName, int myId, int mySeniority, float mySalaryPerYear) :Employee(myName, myId, mySeniority)
{
	setSalaryPerYear(mySalaryPerYear);
}


void FullTime::setSalaryPerYear(int mySalaryPerYear)
{
	salaryPerYear = mySalaryPerYear;
}


float FullTime::getSalaryPerYear()const
{
	return salaryPerYear;
}


float FullTime::salary()
{
	pay = salaryPerYear / 12;
	return pay;
}


float FullTime::salaryAfterBonus()
{
	Employee::salaryAfterBonus(); // method of parent class
	if (seniority > 5)
	{
		pay += 0.25 * pay;
	}
	return pay;
}


istream& operator>>(istream& is, FullTime& f) //friend method
{
	int seniority;
	cout << "Enter employee details:" << endl;
	is >> f.name;
	is >> f.id;
	is >> seniority;
	is >> f.salaryPerYear;
	f.setSeniority(seniority);
	return is;
}


ostream& operator<<(ostream& os, FullTime& f)//friend method
{
	os << "Employee: " << f.getName() << endl;
	os << "Employee ID: " << f.getId() << endl;
	os << "Years Seniority: " << f.getSeniority() << endl;
	os << "Salary per Month: " << f.salary() << endl;
	return os;
}