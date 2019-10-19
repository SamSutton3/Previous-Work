#pragma once
//Header

#ifndef TAXI_H
#define TAXI_H

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Class Declaration
class Taxi {
public:
	// Default Constructor
	Taxi();
	// Overloaded Constructor
	Taxi(int, string, int, string, string);
	// Deconstructor
	~Taxi();
	// Functions to return private variables
	int getID() const;
	string getReg() const;
	int getSeats() const;
	string getManu() const;
	string getModel() const;
	// Functions to set private variables
	void setID(int);
	void setReg(string);
	void setSeats(int);
	void setManu(string);
	void setModel(string);
// private variables
private:
	int TaxiID;
	string Registration;
	int PassengerSeats;
	string Manufacturer;
	string ModelName;
};


#endif
