#pragma once

#ifndef DRIVER_H
#define DRIVER_H

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
// Class Declaration
class Driver {
public:
	// Default Constructor
	Driver();
	// Overloaded Constructor
	Driver(int, string, string, string, string);
	// Deconstructor
	~Driver();
	// Functions to return private variables
	int getID() const;
	string getName() const;
	string getLisenceNo() const;
	string getAddress() const;
	string getNumber() const;
	// Functions to set private variables
	void setID(int);
	void setName(string);
	void setLisenceNo(string);
	void setAddress(string);
	void setNumber(string);
// private variables
private:
	int DriverID;
	string DriverName;
	string LisenceNo;
	string DriverAddress;
	string PhoneNumber;
};
#endif
