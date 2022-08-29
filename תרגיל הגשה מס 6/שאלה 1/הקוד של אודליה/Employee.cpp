/*Odelya Yaakowich 207346784
Workshop in c++
Exercise 6 Question 1*/

#include "Employee.h"

Employee::Employee(string myName, int myId, int mySen)
{
	setName(myName);
	setId(myId);
	setSeniority(mySen);
}


void Employee::setName(string myName)
{
	name = myName;
}


void Employee::setId(int myId)
{
	id = myId;
}


void Employee::setSeniority(int mySeniority)
{
	if (mySeniority < 0)
		throw "ERROR";
	else
		seniority = mySeniority;
}


string Employee::getName()const
{
	return name;
}


int Employee::getId() const
{
	return id;
}


int Employee::getSeniority()const
{
	return seniority;
}


float Employee::getPay()const
{
	return pay;
}


float Employee::salaryAfterBonus()
{
	if (seniority <= 5)
		pay += 500;
	return pay;
}


istream& operator>>(istream& is, Employee& e) //friend method
{
	int seniority;
	cout << "Enter employee details:" << endl;
	is >> e.name;
	is >> e.id;
	is >> e.seniority;
	return is;
}


ostream& operator<<(ostream& os, Employee& e) //friend method
{
	os<< "Employee: "<< e.name << endl;
	os << "Employee ID: "<< e.id << endl;
	os << "Years Seniority: "<< e.seniority << endl;
	return os;
}