#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Class Name
class Customer{
// public methods
public:
	// Default Constructor
	Customer();
	// Overloaded Constructor
	Customer(int, string, string, string);
	// Deconstructor
	~Customer();
	// Functions to return private variables
	int getID() const;
	string getName() const;
	string getAddress() const;
	string getNumber() const;
	// Functions to set private variables
	void setID(int);
	void setName(string);
	void setAddress(string);
	void setNumber(string);
// private variables
private:
	int CustomerID;
	string CustomerName;
	string CustomerAddress;
	string PhoneNumber;
};
#endif 

