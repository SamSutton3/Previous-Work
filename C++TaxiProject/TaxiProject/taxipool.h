#pragma once
#ifndef TAXIPOOL_H
#define TAXIPOOL_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "taxi.h"
using namespace std;

// Class Name
class taxipool {
// public methods
public:
	// Default Constructor
	taxipool();
	// Overloaded Constructor
	taxipool(int, string, int, string, string);
	// Deconstructor
	~taxipool();
	// Function to fill Vector from text file
	void fillVectorTaxi(vector <Taxi>&);
	// Function to display all values stored in  the vector
	void displayVectorTaxi(const vector <Taxi>&);
	// Function Writes to the file
	void writeToTaxi(string line);
	// Function to find a new unused ID
	int createTaxiID(const vector <Taxi>&);
	// Function Compiles Information from User Inputs
	string complileNewTaxi(const vector <Taxi>&);
	// creates Taxi ID for Ride Class
	char createRT();
	// Function Gets user inputs for string variables
	string inputReg();
	// integer inputs for the Taxi Class are embedded into the main to allow concatenation
	string inputManu();
	string inputModel();
	// creates Taxi Data
	void createTaxi(vector <Taxi>& vecTaxis);
	// Query Functions
	void queryReg(vector <Taxi>& vecTaxis);
	void querySeats(vector <Taxi>& vecTaxis);
	void queryManu(vector <Taxi>& vecTaxis);
	void queryModel(vector <Taxi>& vecTaxis);
	// Function to show the result of queries
	void queryResults(vector <Taxi>& queryT);
	//Functions to select and delete from file
	void deleteTaxi(vector <Taxi>& vecTaxis);
	void rewriteTaxi(vector <Taxi>& vecTaxis);
private:
	// creates temporary variables to be used as reference 
	// private variables
	int tTaxiID;
	string tReg;
	int tSeats;
	string tManu;
	string tModel;
};
#endif // !TAXIPOOL_H
