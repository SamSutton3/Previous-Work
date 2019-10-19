#include "stdafx.h"
#include <iostream>
#include <string>
#include "taxi.h"
using namespace std;
// Default Constructor
Taxi::Taxi()
{
	// Sets Integer values to default to 0
	int TaxiID = 0;
	int PassengerSeats = 0;
}
// Overloaded Constructor
Taxi::Taxi(int newID, string newReg, int newSeats, string newManu, string newModel) 
{
	// assigns values to private variables when passed as parameters
	TaxiID = newID;
	Registration = newReg;
	PassengerSeats = newSeats;
	Manufacturer = newManu;
	ModelName = newModel;
}
// Deconstructor
Taxi::~Taxi() 
{
}
// Return Functions of a constant private variable
int Taxi::getID() const
{
	return TaxiID;
}
string Taxi::getReg() const
{
	return Registration;
}
int Taxi::getSeats() const
{
	return PassengerSeats;
}
string Taxi::getManu() const
{
	return Manufacturer;
}
string Taxi::getModel() const
{
	return ModelName;
}
// Declarations of Functions to set private variables
void Taxi::setID(int ID)
{
	TaxiID = ID;
}
void Taxi::setReg(string Reg)
{
	Registration = Reg;
}
void Taxi::setSeats(int Seats)
{
	PassengerSeats = Seats;
}
void Taxi::setManu(string Manu)
{
	Manufacturer = Manu;
}
void Taxi::setModel(string Model)
{
	ModelName = Model;
}