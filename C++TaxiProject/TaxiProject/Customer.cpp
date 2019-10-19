#include "stdafx.h"
#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

// Default Constructor
Customer::Customer()
{
	// Sets Integer values to default to 0
	int CustomerID = 0;
}
// Overloaded Constructor
Customer::Customer(int newID, string newName, string newAddress, string newNumber)
{
	// assigns values to private variables when passed as parameters
	CustomerID = newID;
	CustomerName = newName;
	CustomerAddress = newAddress;
	PhoneNumber = newNumber;
}
// Deconstructor
Customer::~Customer()
{
}
// Return Functions of a constant private variable
int Customer::getID() const
{
	return CustomerID;
}
string Customer::getName() const
{
	return CustomerName;
}
string Customer::getAddress() const
{
	return CustomerAddress;
}
string Customer::getNumber() const
{
	return PhoneNumber;
}
// Declarations of Functions to set private variables
void Customer::setID(int ID)
{
	CustomerID = ID;
}
void Customer::setName(string Name)
{
	CustomerName = Name;
}
void Customer::setAddress(string Address)
{
	CustomerAddress = Address;
}
void Customer::setNumber(string Number)
{
	PhoneNumber = Number;
}