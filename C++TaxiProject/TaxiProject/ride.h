#pragma once

#ifndef RIDE_H
#define RIDE_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include "customer.h"
#include "driver.h"
#include "taxi.h"

using namespace std;
// Class Declaration
class Ride {
public:
	// Default Constructor
	Ride();
	// Overloaded Constructor
	Ride(int, int, int, int, string, string, string, double, double, double, double);
	// Deconstructor
	~Ride();
	// Functions to return private variables
	int getID() const;
	int getTID() const;
	int getDID() const;
	int getCID() const;
	string getPickUp() const;
	string getDestination() const;
	string getDate() const;
	double getTimeStart() const;
	double getEstimatedTime() const;
	double getMiles() const;
	double getCost() const;
	// Functions to return private variables
	void setID(int);
	void setTID(int);
	void setDID(int);
	void setCID(int);
	void setPickUp(string);
	void setDestination(string);
	void setDate(string);
	void setTimeStart(double);
	void setEstimatedTime(double);
	void setMiles(double);
	void setCost(double);
// private variables
private:
	int RideID;
	int TaxiID;
	int DriverID;
	int CustomerID;
	string PickUp;
	string Destination;
	string Date;
	// Time will be stored in decimal spaces HH.MM eg. 06.30 = 6:30 AM
	double TimeStart; 
	double EstimatedTime;
	double Miles;
	double Cost;
};

#endif
