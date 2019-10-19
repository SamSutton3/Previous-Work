#pragma once
#ifndef CUSTOMERPOOL_H
#define CUSTOMERPOOL_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "customer.h"

using namespace std;
// Class Name
class customerpool
{
// public methods
public:
	// Default Constructor
	customerpool();
	// Overloaded Constructor
	customerpool(int, string, string, string);
	// Deconstructor
	~customerpool();
	// Function to fill Vector from text file
	void fillVectorCustomer(vector <Customer>&);
	// Function to display all values stored in  the vector
	void displayVectorCustomer(const vector <Customer>&);
	// Function Writes to the customer file
	void writeToCustomer(string line);
	// Function to find a new unused Customer ID
	int createCustomerID(const vector <Customer>&);
	// Function Compiles Information from User Inputs
	string complileNewCustomer(const vector <Customer>&);
	// creates Customer ID for Ride Class
	char createRC();
	// Function Gets user inputs for string variables
	string inputName();
	string inputAddress();
	string inputPhoneNumber();
	// creates customer data
	void createCustomer(vector <Customer>& vecCustomers);
	// Query Functions
	void queryName(vector <Customer>& vecCustomers);
	void queryAddress(vector <Customer>& vecCustomers);
	void queryPhoneNumber(vector <Customer>& vecCustomers);
	// Function to show the result of queries
	void queryResults(vector <Customer>& queryC);
	//Functions to select and delete from file
	void deleteCustomer(vector <Customer>& vecCustomers);
	void rewriteCustomer(vector <Customer>& vecCustomers);
private:
	// creates temporary variables to be used as reference
	// private variables
	int tCustomerID;
	string tName;
	string tAddress;
	string tPhoneNumber;
};
#endif
