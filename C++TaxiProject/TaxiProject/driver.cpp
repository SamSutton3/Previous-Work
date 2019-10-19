#include "stdafx.h"
#include <iostream>
#include <string>
#include "driver.h"
using namespace std;
// Default Constructor
Driver::Driver()
{
	// Sets Integer values to default to 0
	int DriverID = 0;
}
// Overloaded Constructor
Driver::Driver(int newID, string newName, string newLN, string newAddress, string newNumber)
{
	// assigns values to private variables when passed as parameters
	DriverID = newID;
	DriverName = newName;
	LisenceNo = newLN;
	DriverAddress = newAddress;
	PhoneNumber = newNumber;
}
// Deconstructor
Driver::~Driver()
{
}
// Return Functions of a constant private variable
int Driver::getID() const
{
	return DriverID;
}
string Driver::getName() const
{
	return DriverName;
}
string Driver::getLisenceNo() const
{
	return LisenceNo;
}
string Driver::getAddress() const
{
	return DriverAddress;
}
string Driver::getNumber() const
{
	return PhoneNumber;
}
// Declarations of Functions to set private variables
void Driver::setID(int ID)
{
	DriverID = ID;
}
void Driver::setName(string Name)
{
	DriverName = Name;
}
void Driver::setLisenceNo(string LN)
{
	LisenceNo = LN;
}
void Driver::setAddress(string Address)
{
	DriverAddress = Address;
}
void Driver::setNumber(string Number)
{
	PhoneNumber = Number;
}