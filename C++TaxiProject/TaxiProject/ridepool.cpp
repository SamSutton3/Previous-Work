#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "ride.h"
#include "ridepool.h"
#include "driverpool.h"
#include "customerpool.h"
#include "taxipool.h"
using namespace std;
// Default Constructor
ridepool::ridepool()
{
	// Sets Integer and Double Values to default as 0
	int tRideID = 0;
	int tRTaxiID = 0;
	int tRDriverID = 0;
	int tRCustomerID = 0;
	double tTimeStart = 0.0;
	double tEstimatedTime = 0.0;
	double tMiles = 0.0;
	double tCost = 0.0;
}
// Overloaded Constructor
ridepool::ridepool(int newID, int newTID, int newDID, int newCID, string newPickUp, string newDestination, string newDate, double newTimeStart, double newEstimatedTime, double newMiles, double newCost)
{
	// assigns values to private variables when passed as parameters
	tRideID = newID;
	tRTaxiID = newTID;
	tRDriverID = newDID;
	tRCustomerID = newCID;
	tPickUp = newPickUp;
	tDestination = newDestination;
	tDate = newDate;
	tTimeStart = newTimeStart;
	tEstimatedTime = newEstimatedTime;
	tMiles = newMiles;
	tCost = newCost;
}
// Deconstructor
ridepool::~ridepool()
{
}
// Function to fill Vector from text file
void ridepool::fillVectorRide(vector<Ride>& newVecRide)
{
	// connects to text file
	ifstream inFile("RideFile.txt");
	// checks if text file is open
	if (!inFile.is_open())
	{
		cout << "Press any key to close. " << endl;
	}
	// whilst the program can read in lines
	while (inFile.good())
	{
		// takes in variables from text file and stores them in private variables set by class
		inFile >> tRideID;
		inFile >> tRTaxiID;
		inFile >> tRDriverID;
		inFile >> tRCustomerID;
		inFile >> tPickUp;
		inFile >> tDestination;
		inFile >> tDate;
		inFile >> tTimeStart;
		inFile >> tEstimatedTime;
		inFile >> tMiles;
		inFile >> tCost;
		// pushes data took in from text file to vector
		Ride newRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
		newVecRide.push_back(newRide);
	}
}
// Function to display all values stored in the vector
void ridepool::displayVectorRide(const vector<Ride>& newVecRide)
{
	// finds the size of the vector and loops for length of vector
	unsigned int vecSize = newVecRide.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// returns private variables stored in each instance of the vector
		cout << "Ride ID: " << newVecRide[i].getID() << endl;
		cout << "Taxi ID: " << newVecRide[i].getTID() << endl;
		cout << "Driver ID: " << newVecRide[i].getDID() << endl;
		cout << "Customer ID: " << newVecRide[i].getCID() << endl;
		cout << "Pick Up Location: " << newVecRide[i].getPickUp() << endl;
		cout << "Destination: " << newVecRide[i].getDestination() << endl;
		cout << "Date: " << newVecRide[i].getDate() << endl;
		cout << "Time Start: " << newVecRide[i].getTimeStart() << endl;
		cout << "Estimated Time: " << newVecRide[i].getEstimatedTime() << endl;
		cout << "Miles: " << newVecRide[i].getMiles() << endl;
		cout << "Cost: " << newVecRide[i].getCost() << endl;
		cout << endl;
	}
}
// Function to Write to file in append mode
void ridepool::writeToRide(string line)
{
	ofstream oFile("RideFile.txt", ios::app);
	// creates a new line and inserts new data into the text file
	oFile << endl;
	oFile << line;
}
// Function that Compiles Information from User Inputs
string ridepool::complileNewRide(const vector<Ride>& newVecRide)
{
	// to concatenate values - variables which would normally be stored as integers are being stored as strings
	// calls in other classes to get IDs generated from their functions
	customerpool cp;
	taxipool tp;
	driverpool dp;
	string line;
	// Uses private variables from class to store data temporarily
	// gets unused ID 
	tRideID = createRideID(newVecRide);
	// converts integer into string
	string outID;
	stringstream newID;
	newID << tRideID;
	outID = newID.str();
	// gets user input
	tRTaxiID = tp.createRT();
	// converts integer into string
	string outTaxi;
	stringstream newT;
	newT << tRTaxiID;
	outTaxi = newT.str();
	// gets user input
	tRDriverID = dp.createRD();
	// converts integer into string
	string outDriver;
	stringstream newD;
	newD << tRDriverID;
	outDriver = newD.str();
	// gets user input
	tRCustomerID = cp.createRC();
	// converts integer into string
	string outCustomer;
	stringstream newC;
	newC << tRCustomerID;
	outCustomer = newC.str();
	// Find Other Values needed
	// gets user input
	tPickUp = inputPU();
	// gets user input
	tDestination = inputDes();
	// gets user input
	tDate = inputDate();
	// gets user input
	cout << "Enter the Time the Journey will Start: ";
	cin >> tTimeStart;
	cout << endl;
	// converts double into string
	string outTime;
	stringstream newTS;
	newTS << tTimeStart;
	outTime = newTS.str();
	// gets user input
	cout << "Enter the Estimated Time Taken: ";
	cin >> tEstimatedTime;
	cout << endl;
	// converts double into string
	string esTime;
	stringstream newES;
	newES << tEstimatedTime;
	esTime = newES.str();
	// gets user input
	cout << "Enter the Miles Taken: ";
	cin >> tMiles;
	cout << endl;
	// converts double into string
	string outMil;
	stringstream newMil;
	newMil << tMiles;
	outMil = newMil.str();
	// calculates cost based on variables
	tCost = calculateCost(tTimeStart, tEstimatedTime, tMiles);
	// converts double into string
	string outCost;
	stringstream newCo;
	newCo << tCost;
	outCost = newCo.str();
	// concetenates strings
	line = outID + " " + outTaxi + " " + outDriver + " " + outCustomer + " " + tPickUp + " " + tDestination + " " + tDate + " " + outTime + " " + esTime + " " + outMil + " " + outCost;
	// returns string to be added to a text file
	return line;
}
// Function to Calculate the Cost of a ride
double ridepool::calculateCost(double TimeStart, double EstimatedTime, double Miles)
{
	double Cost = 0;
	// Tier 1
	if ((TimeStart > 21.00) || (TimeStart < 5.00))
	{
		if (Miles < 5)
		{
			if (EstimatedTime < 30)
			{
				cout << "14.50" << endl;
				Cost = 14.5;
			}
			else
			{
				cout << "18.50" << endl;
				Cost = 18.5;
			}
		}
		else if ((Miles > 5) && (Miles < 12.5))
		{
			if (EstimatedTime < 45)
			{
				cout << "22.50" << endl;
				Cost = 22.5;
			}
			else
			{
				cout << "26.50" << endl;
				Cost = 26.5;
			}
		}
		else if (Miles > 12.5)
		{
			if (EstimatedTime < 60)
			{
				cout << "32.50" << endl;
				Cost = 32.5;
			}
			else
			{
				cout << "48" << endl;
				Cost = 48;

			}
		}
	}
	// Tier 2
	else if ((TimeStart > 5.00) && (TimeStart < 20.59))
	{
		if (Miles < 5)
		{
			if (EstimatedTime < 30)
			{
				cout << "6" << endl;
				Cost = 6;
			}
			else
			{
				cout << "11" << endl;
				Cost = 11;
			}
		}
		else if ((Miles > 5) && (Miles < 12.5))
		{
			if (EstimatedTime < 45)
			{
				cout << "15" << endl;
				Cost = 15;
			}
			else
			{
				cout << "19" << endl;
				Cost = 19;
			}
		}
		else if (Miles > 12.5)
		{
			if (EstimatedTime < 60)
			{
				cout << "26" << endl;
				Cost = 26;
			}
			else
			{
				cout << "34" << endl;
				Cost = 34;
			}
		}
	}
	return Cost;
}
// Function to find a new unused ID
int ridepool::createRideID(const vector <Ride>& newVecRide)
{
	// finds the size of the vector and loops for the length of vector
	int max = 0;
	unsigned int vecSize = newVecRide.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// compares value of ID against current max
		if (newVecRide[i].getID() > max)
		{
			// if value of ID is greater it is set as the new maximum
			max = newVecRide[i].getID();
		}
	}
	// increments the value stored in max and stores it in another variable before returning it
	tRideID = max + 1;
	return tRideID;
}
// Function gets user inputs for string variables and return them back to other functions
string ridepool::inputPU()
{
	cout << "Enter the Pick Up Location: ";
	cin >> tPickUp;
	cout << endl;
	return tPickUp;
}
string ridepool::inputDes()
{
	cout << "Enter the Destination: ";
	cin >> tDestination;
	cout << endl;
	return tDestination;
}
string ridepool::inputDate()
{
	cout << "Enter the Date: ";
	cin >> tDate;
	cout << endl;
	return tDate;
}
// Function to format functions necessary to write to text file
void ridepool::createRide(vector <Ride>& vecRides)
{
	string line;
	fillVectorRide(vecRides);
	line = complileNewRide(vecRides);
	writeToRide(line);
	cout << "Successful addition to the Ride File" << endl;
}
// Query Functions
void ridepool::queryDriver(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	int newDriverID = 0;
	vector <Ride> queryR;
	driverpool dp;
	vector <Driver> vecDrivers;
	dp.fillVectorDriver(vecDrivers);
	dp.displayVectorDriver(vecDrivers);
	cout << endl;
	cout << "Please enter the Driver ID of the Rides you want to find  >> ";
	cin >> tRDriverID;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newDriverID = vecRides[i].getDID();
		if (newDriverID == tRDriverID)
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination,tDate,tTimeStart,tEstimatedTime,tMiles,tCost);
			queryR.push_back(queryRide);
		}
		else
		{
			cout << "-" << endl;
		}
	}
	queryResults(queryR);
}
void ridepool::queryCustomer(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	int newCustomerID = 0;
	vector <Ride> queryR;
	customerpool cp;
	vector <Customer> vecCustomers;
	cp.fillVectorCustomer(vecCustomers);
	cp.displayVectorCustomer(vecCustomers);
	cout << endl;
	cout << "Please enter the Customer ID of the Rides you want to find  >> ";
	cin >> tRCustomerID;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newCustomerID = vecRides[i].getCID();
		if (newCustomerID == tRCustomerID)
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
			queryR.push_back(queryRide);
		}
		else
		{
			cout << "-" << endl;
		}
	}
	queryResults(queryR);
}
void ridepool::queryTaxi(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	int newTaxiID = 0;
	vector <Ride> queryR;
	taxipool tp;
	vector <Taxi> vecTaxis;
	tp.fillVectorTaxi(vecTaxis);
	tp.displayVectorTaxi(vecTaxis);
	cout << endl;
	cout << "Please enter the Taxi ID of the Rides you want to find  >> ";
	cin >> tRTaxiID;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newTaxiID = vecRides[i].getCID();
		if (newTaxiID == tRTaxiID)
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
			queryR.push_back(queryRide);
		}
		else
		{
			cout << "-" << endl;
		}
	}
	queryResults(queryR);
}
void ridepool::queryDate(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newDate;
	vector <Ride> queryR;
	cout << "Please enter the Date of the Rides you want to find (In the format DDMMYY) >> ";
	cin >> tDate;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newDate = vecRides[i].getDate();
		if (tDate.compare(newDate) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
			queryR.push_back(queryRide);
		}
	}
	queryResults(queryR);

}
void ridepool::queryPU(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newPU;
	vector <Ride> queryR;
	cout << "Please enter the Postcode of the Pick Up Location of the Rides you want to find  >> ";
	cin >> tPickUp;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newPU = vecRides[i].getPickUp();
		if (tPickUp.compare(newPU) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
			queryR.push_back(queryRide);
		}
	}
	queryResults(queryR);

}
void ridepool::queryDes(vector <Ride>& vecRides)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newDestination;
	vector <Ride> queryR;
	cout << "Please enter the Postcode of the Destination of the Rides you want to find  >> ";
	cin >> tDestination;
	unsigned int vecSize = vecRides.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newDestination = vecRides[i].getPickUp();
		if (tDestination.compare(newDestination) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tRideID = vecRides[i].getID();
			tRTaxiID = vecRides[i].getTID();
			tRDriverID = vecRides[i].getDID();
			tRCustomerID = vecRides[i].getCID();
			tPickUp = vecRides[i].getPickUp();
			tDestination = vecRides[i].getDestination();
			tDate = vecRides[i].getDate();
			tTimeStart = vecRides[i].getTimeStart();
			tEstimatedTime = vecRides[i].getEstimatedTime();
			tMiles = vecRides[i].getMiles();
			tCost = vecRides[i].getCost();
			Ride queryRide(tRideID, tRTaxiID, tRDriverID, tRCustomerID, tPickUp, tDestination, tDate, tTimeStart, tEstimatedTime, tMiles, tCost);
			queryR.push_back(queryRide);
		}
	}
	queryResults(queryR);
}
// Function to show the result of queries
void ridepool::queryResults(vector <Ride>& queryR)
{
	// displays data stored in vectors that may have been pushed there by a correct query
	unsigned int querySize = queryR.size();
	if (querySize > 0)
	{
		cout << endl;
		cout << "--- Ride Query Results ---" << endl;
		displayVectorRide(queryR);
	}
	else if (querySize < 0)
	{
		cout << "No results matched your search" << endl;
	}
}
// Delete Function - Allows the user to select a customer to delete
void ridepool::deleteRide(vector <Ride>& vecRides)
{
	int newID = 0;
	fillVectorRide(vecRides);
	displayVectorRide(vecRides);
	cout << endl;
	cout << "Please enter in a Ride ID of the Ride you would like to delete >> ";
	cin >> tRideID;
	for (unsigned int i = 0; i < vecRides.size(); i++)
	{
		newID = vecRides[i].getID();
		if (newID == tRideID)
		{
			vecRides.erase(vecRides.begin() + i);
		}
	}
	rewriteRide(vecRides);
}
// Function that rewrites the text file with the new data generated to appear as if the data has been deleted
void ridepool::rewriteRide(vector <Ride>& vecRides)
{
	string line;
	ofstream oFile("RideFile.txt");
	for (unsigned int i = 0; i < vecRides.size(); i++)
	{
		// Gets Data stored in the instance of the class vector
		tRideID = vecRides[i].getID();
		// formats integer to string
		string outID;
		stringstream newID;
		newID << tRideID;
		outID = newID.str();
		tRTaxiID = vecRides[i].getTID();
		// formats integer to string
		string outTID;
		stringstream newTID;
		newID << tRTaxiID;
		outTID = newID.str();
		tRDriverID = vecRides[i].getDID();
		// formats integer to string
		string outDID;
		stringstream newDID;
		newDID << tRDriverID;
		outDID = newID.str();
		tRCustomerID = vecRides[i].getCID();
		// formats integer to string
		string outCID;
		stringstream newCID;
		newCID << tRCustomerID;
		outCID = newID.str();
		tPickUp = vecRides[i].getPickUp();
		tDestination = vecRides[i].getDestination();
		tDate = vecRides[i].getDate();
		tTimeStart = vecRides[i].getTimeStart();
		// converts double into string
		string outTime;
		stringstream newTS;
		newTS << tTimeStart;
		outTime = newTS.str();
		// gets user input
		tEstimatedTime = vecRides[i].getEstimatedTime();
		// converts double into string
		string esTime;
		stringstream newES;
		newES << tEstimatedTime;
		esTime = newES.str();
		tMiles = vecRides[i].getMiles();
		// converts double into string
		string outMil;
		stringstream newMil;
		newMil << tMiles;
		outMil = newMil.str();
		// calculates cost based on variables
		tCost = vecRides[i].getCost();
		// converts double into string
		string outCost;
		stringstream newCo;
		newCo << tCost;
		outCost = newCo.str();
		// formats string 
		line = outID + " " + outTID + " " + outDID + " " + outCID + " " + tPickUp + " " + tDestination + " " + tDate + " " + outTime + " " + esTime + " " + outMil + " " + outCost;
		// writes to file
		oFile << line;
		oFile << endl;
	}
}