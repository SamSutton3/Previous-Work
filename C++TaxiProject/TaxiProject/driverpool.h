#pragma once
#ifndef DRIVERPOOL_H
#define DRIVERPOOL_H
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "driver.h"

using namespace std;
// Class Name
class driverpool {
public:
	// Default Constructor
	driverpool();
	// Overloaded Constructor
	driverpool(int, string, string, string, string);
	// Deconstructor
	~driverpool();
	// Function to fill Vector from text file
	void fillVectorDriver(vector <Driver>&);
	// Function to display all values stored in the vector
	void displayVectorDriver(const vector <Driver>&);
	// Function Writes to the file
	void writeToDriver(string line);
	// Function to find a new unused ID
	int createDriverID(const vector <Driver>&);
	// Function Compiles Information from User Inputs
	string complileNewDriver(const vector <Driver>&);
	// Function Gets user inputs for string variables
	string inputName();
	string inputAddress();
	string inputPhoneNumber();
	string inputLisenceNo();
	// creates Driver ID for Ride Class
	char createRD();
	// creates driver data
	void createDriver(vector <Driver>& vecDrivers);
	// Query Functions
	void queryName(vector <Driver>& vecDrivers);
	void queryLisenceNo(vector <Driver>& vecDrivers);
	void queryAddress(vector <Driver>& vecDrivers);
	void queryPhoneNumber(vector <Driver>& vecDrivers);
	// Function to show the result of queries
	void queryResults(vector <Driver>& queryD);
	//Functions to select and delete from file
	void deleteDriver(vector <Driver>& vecDrivers);
	void rewriteDriver(vector <Driver>& vecDrivers);
private:
	// creates temporary variables to be used as reference 
	// private variables
	int tDriverID;
	string tName;
	string tLisenceNo;
	string tAddress;
	string tPhoneNumber;

};

#endif // !DRIVERPOOL_H
