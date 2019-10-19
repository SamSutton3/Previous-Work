#pragma once
#ifndef RIDEPOOL_H
#define RIDEPOOL_H
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

#include "ride.h"

using namespace std;

class ridepool {
// public methods
public:
	// Default Constructor
	ridepool();
	// Overloaded Constructor
	ridepool(int, int, int, int, string, string, string, double, double, double, double);
	// Deconstructor
	~ridepool();
	// Function to fill Vector from text file
	void fillVectorRide(vector <Ride>&);
	// Function to display all values stored in  the vector
	void displayVectorRide(const vector <Ride>&);
	// Function Writes to the ride file
	void writeToRide(string line);
	// Function to find a new unused Ride ID
	int createRideID(const vector <Ride>&);
	// Function Compiles Ride Information from User Inputs
	string complileNewRide(const vector <Ride>&);
	// Function Gets user inputs for string variables
	string inputPU();
	string inputDes();
	string inputDate();
	// Fucntion that calculates cost 
	double calculateCost(double, double, double);
	void createRide(vector <Ride>& vecRides);
	// Query Functions
	void queryDriver(vector <Ride>& vecRides);
	void queryCustomer(vector <Ride>& vecRides);
	void queryTaxi(vector <Ride>& vecRides);
	void queryDate(vector <Ride>& vecRides);
	void queryPU(vector <Ride>& vecRides);
	void queryDes(vector <Ride>& vecRides);
	// Function to show the result of queries
	void queryResults(vector <Ride>& queryR);
	//Functions to select and delete Rides
	void deleteRide(vector <Ride>& vecRides);
	void rewriteRide(vector <Ride>& vecRides);
private:
	// creates temporary variables to be used as reference 
	// private variables
	int tRideID;
	int tRTaxiID;
	int tRDriverID;
	int tRCustomerID;
	string tPickUp;
	string tDestination;
	string tDate;
	// Time will be stored in decimal spaces HH.MM eg. 06.30 = 6:30 AM
	double tTimeStart;
	double tEstimatedTime;
	double tMiles;
	double tCost;
};




#endif // !RIDEPOOL_H
