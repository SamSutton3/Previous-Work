#include "stdafx.h"
#include <iostream>
#include <string>
#include "ride.h"
using namespace std;

// Default Constructor
Ride::Ride()
{
	// Sets Integer and Double Values to default as 0
	int RideID = 0;
	int TaxiID = 0;
	int DriverID = 0;
	int CustomerID = 0;
	double TimeStart = 0.0;
	double EstimatedTime = 0.0;
	double Miles = 0.0;
	double Cost = 0.0;
}
// Overloaded Constructor
Ride::Ride(int newID, int newTID, int newDID, int newCID, string newPickUp, string newDestination, string newDate, double newTimeStart, double newEstimatedTime, double newMiles, double newCost)
{
	// assigns values to private variables when passed as parameters
	RideID = newID;
	TaxiID = newTID;
	DriverID = newDID;
	CustomerID = newCID;
	PickUp = newPickUp;
	Destination = newDestination;
	Date = newDate;
	TimeStart = newTimeStart;
	EstimatedTime = newEstimatedTime;
	Miles = newMiles;
	Cost = newCost;
}
// Deconstructor
Ride::~Ride()
{
}
// Return Functions of a constant private variable
int Ride::getID() const
{
	return RideID;
}
int Ride::getTID() const
{
	return TaxiID;
}
int Ride::getDID() const
{
	return DriverID;
}
int Ride::getCID() const
{
	return CustomerID;
}
string Ride::getPickUp() const
{
	return PickUp;
}
string Ride::getDestination() const
{
	return Destination;
}
string Ride::getDate() const
{
	return Date;
}
double Ride::getTimeStart() const
{
	return TimeStart;
}
double Ride::getEstimatedTime() const
{
	return EstimatedTime;
}
double Ride::getMiles() const
{
	return Miles;
}
double Ride::getCost() const
{
	return Cost;
}
// Declarations of Functions to set private variables
void Ride::setID(int ID)
{
	RideID = ID;
}
void Ride::setTID(int TID)
{
	TaxiID = TID;
}
void Ride::setDID(int DID)
{
	DriverID = DID;
}
void Ride::setCID(int CID)
{
	CustomerID = CID;
}
void Ride::setPickUp(string PU)
{
	PickUp = PU;
}
void Ride::setDestination(string Des)
{
	Destination = Des;
}
void Ride::setDate(string D)
{
	Date = D;
}
void Ride::setTimeStart(double TS)
{
	TimeStart = TS;
}
void Ride::setEstimatedTime(double ET)
{
	EstimatedTime = ET;
}
void Ride::setMiles(double M)
{
	Miles = M;
}
void Ride::setCost(double C)
{
	Cost = C;
}