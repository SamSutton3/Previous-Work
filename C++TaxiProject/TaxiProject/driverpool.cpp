#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "driver.h"
#include "driverpool.h"
using namespace std;
// Default Constructor
driverpool::driverpool()
{
	// Sets Integer values to default to 0
	int tDriverID = 0;
}
// Overloaded Constructor
driverpool::driverpool(int newID, string newName, string newLN, string newAddress, string newNumber)
{
	// assigns values to private variables when passed as parameters
	tDriverID = newID;
	tName = newName;
	tLisenceNo = newLN;
	tAddress = newAddress;
	tPhoneNumber = newNumber;
}
// Deconstructor
driverpool::~driverpool()
{
}
// Function to fill Vector from text file
void driverpool::fillVectorDriver(vector<Driver>& newVecDriver)
{
	// connects to text file
	ifstream inFile("DriverFile.txt");
	// checks if text file is open
	if (!inFile.is_open())
	{
		cout << "Press any key to close. " << endl;
	}
	// whilst the program can read in lines
	while (inFile.good())
	{
		// takes in variables from text file and stores them in private variables set by class
		inFile >> tDriverID;
		inFile >> tName;
		inFile >> tLisenceNo;
		inFile >> tAddress;
		inFile >> tPhoneNumber;
		// pushes data took in from text file to vector
		Driver newDriver(tDriverID, tName, tLisenceNo, tAddress, tPhoneNumber);
		newVecDriver.push_back(newDriver);
	}
}
// Function to display all values stored in the vector
void driverpool::displayVectorDriver(const vector<Driver>& newVecDriver)
{
	// finds the size of the vector and loops for length of vector
	unsigned int vecSize = newVecDriver.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// returns private variables stored in each instance of the vector
		cout << "Driver ID: " << newVecDriver[i].getID() << endl;
		cout << "Driver Name: " << newVecDriver[i].getName() << endl;
		cout << "Lisence No.: " << newVecDriver[i].getLisenceNo() << endl;
		cout << "Address: " << newVecDriver[i].getAddress() << endl;
		cout << "Phone Number: " << newVecDriver[i].getNumber() << endl;
		cout << endl;
	}
}
// Function to Write to file in append mode
void driverpool::writeToDriver(string line)
{
	ofstream oFile("DriverFile.txt", ios::app);
	// creates a new line and inserts new data into the text file
	oFile << endl;
	oFile << line;
}
// Function that Compiles Information from User Inputs
string driverpool::complileNewDriver(const vector<Driver>& newVecDriver)
{
	// Uses private variables from class to store data temporarily
	// to concatenate values - variables which would normally be stored as integers are being stored as strings
	string line;
	// gets unused ID 
	tDriverID = createDriverID(newVecDriver);
	// formats integer to string
	string tID;
	stringstream newID;
	newID << tDriverID;
	tID = newID.str();
	// gets user input from a seperate functions
	tName = inputName();
	tLisenceNo = inputLisenceNo();
	tAddress = inputAddress();
	tPhoneNumber = inputPhoneNumber();
	// constructs and returns line to be wrote into the file
	line = tID + " " + tName + " " + tLisenceNo + " " + tAddress + " " + tPhoneNumber;
	return line;
}
// Function to find a new unused ID
int driverpool::createDriverID(const vector<Driver>& newVecDriver)
{
	// finds the size of the vector and loops for the length of vector
	int max = 0;
	unsigned int vecSize = newVecDriver.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// compares value of ID against current max
		if (newVecDriver[i].getID() > max)
		{
			// if value of ID is greater it is set as the new maximum
			max = newVecDriver[i].getID();
		}
	}
	// increments the value stored in max and stores it in another variable before returning it
	tDriverID = max + 1;
	return tDriverID;
}
// Function gets user inputs for string variables and return them back to other functions
string driverpool::inputName()
{
	cout << "Enter the Name: ";
	cin >> tName;
	cout << endl;
	return tName;
}
string driverpool::inputLisenceNo()
{
	cout << "Enter the Lisence Number: ";
	cin >> tLisenceNo;
	cout << endl;
	return tLisenceNo;
}
string driverpool::inputAddress()
{
	cout << "Enter the Postcode of the Address: ";
	cin >> tAddress;
	cout << endl;
	return tAddress;
}
string driverpool::inputPhoneNumber()
{
	cout << "Enter the Phone Number of the Customer: ";
	cin >> tPhoneNumber;
	cout << endl;
	return tPhoneNumber;
}
// creates Driver Data for Ride Class
char driverpool::createRD()
{
	// Allows user to chose to select a current Driver or create a new one
	vector <Driver> newVecDriver;
	string line;
	cout << "--- WOULD YOU LIKE TO CREATE NEW DRIVER DATA? ---" << endl;
	int decision = 0;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;
	cout << "Please select an option (1/2) >> ";
	cin >> decision;
	if (decision == 1)
	{
		// creates driver data and writes it to text file
		cout << endl;
		cout << "You have selected to Create New Driver Data" << endl;
		fillVectorDriver(newVecDriver);
		line = complileNewDriver(newVecDriver);
		writeToDriver(line);
	}
	// Allows user to select a customer ID and shows the options 
	vector <Driver> newVecDriver2;
	fillVectorDriver(newVecDriver2);
	displayVectorDriver(newVecDriver2);
	cout << "Please select a Driver ID >> ";
	cin >> tDriverID;
	return tDriverID;
}
// Function to format functions necessary to write to text file
void driverpool::createDriver(vector <Driver>& vecDrivers)
{
	string line;
	fillVectorDriver(vecDrivers);
	line = complileNewDriver(vecDrivers);
	writeToDriver(line);
	cout << "Successful addition to the Driver File" << endl;
}
// Query Functions
void driverpool::queryName(vector <Driver>& vecDrivers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newName;
	vector <Driver> queryD;
	cout << "Please enter the Name of the Driver you`d like to find >> ";
	cin >> tName;
	unsigned int vecSize = vecDrivers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newName = vecDrivers[i].getName();
		if (tName.compare(newName) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tDriverID = vecDrivers[i].getID();
			tName = vecDrivers[i].getName();
			tLisenceNo = vecDrivers[i].getLisenceNo();
			tAddress = vecDrivers[i].getAddress();
			tPhoneNumber = vecDrivers[i].getNumber();
			Driver queryDriver(tDriverID, tName, tLisenceNo, tAddress, tPhoneNumber);
			queryD.push_back(queryDriver);
		}
	}
	queryResults(queryD);
}
void driverpool::queryLisenceNo(vector <Driver>& vecDrivers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newLN;
	vector <Driver> queryD;
	cout << "Please enter the Lisence Number of the Driver you`d like to find >> ";
	cin >> tLisenceNo;
	unsigned int vecSize = vecDrivers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newLN = vecDrivers[i].getLisenceNo();
		if (tLisenceNo.compare(newLN) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tDriverID = vecDrivers[i].getID();
			tName = vecDrivers[i].getName();
			tLisenceNo = vecDrivers[i].getLisenceNo();
			tAddress = vecDrivers[i].getAddress();
			tPhoneNumber = vecDrivers[i].getNumber();
			Driver queryDriver(tDriverID, tName, tLisenceNo, tAddress, tPhoneNumber);
			queryD.push_back(queryDriver);
		}
	}
	queryResults(queryD);

}
void driverpool::queryAddress(vector <Driver>& vecDrivers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newAddress;
	vector <Driver> queryD;
	cout << "Please enter the Postcode of the Address of the Driver you`d like to find >> ";
	cin >> tAddress;
	unsigned int vecSize = vecDrivers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newAddress = vecDrivers[i].getAddress();
		if (tAddress.compare(newAddress) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tDriverID = vecDrivers[i].getID();
			tName = vecDrivers[i].getName();
			tLisenceNo = vecDrivers[i].getLisenceNo();
			tAddress = vecDrivers[i].getAddress();
			tPhoneNumber = vecDrivers[i].getNumber();
			Driver queryDriver(tDriverID, tName, tLisenceNo, tAddress, tPhoneNumber);
			queryD.push_back(queryDriver);
		}
	}
	queryResults(queryD);
}
void driverpool::queryPhoneNumber(vector <Driver>& vecDrivers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newPN;
	vector <Driver> queryD;
	cout << "Please enter the Phone Number of the Driver you`d like to find >> ";
	cin >> tPhoneNumber;
	unsigned int vecSize = vecDrivers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newPN = vecDrivers[i].getName();
		if (tPhoneNumber.compare(newPN) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tDriverID = vecDrivers[i].getID();
			tName = vecDrivers[i].getName();
			tLisenceNo = vecDrivers[i].getLisenceNo();
			tAddress = vecDrivers[i].getAddress();
			tPhoneNumber = vecDrivers[i].getNumber();
			Driver queryDriver(tDriverID, tName, tLisenceNo, tAddress, tPhoneNumber);
			queryD.push_back(queryDriver);
		}
	}
	queryResults(queryD);
}
// Function to show the result of queries
void driverpool::queryResults(vector <Driver>& queryD)
{
// displays data stored in vectors that may have been pushed there by a correct query
	unsigned int querySize = queryD.size();
	if (querySize > 0)
	{
		cout << endl;
		cout << "--- Driver Query Results ---" << endl;
		displayVectorDriver(queryD);
	}
	else if (querySize < 0)
	{
		cout << "No results matched your search" << endl;
	}
}
// Delete Function - Allows the user to select a customer to delete
void driverpool::deleteDriver(vector <Driver>& vecDrivers)
{
	int newID = 0;
	fillVectorDriver(vecDrivers);
	displayVectorDriver(vecDrivers);
	cout << endl;
	cout << "Please enter in a Driver ID of the Driver you would like to delete >> ";
	cin >> tDriverID;
	for (unsigned int i = 0; i < vecDrivers.size(); i++)
	{
		newID = vecDrivers[i].getID();
		if (newID == tDriverID)
		{
			vecDrivers.erase(vecDrivers.begin() + i);
		}
	}
	rewriteDriver(vecDrivers);
}
// Function that rewrites the text file with the new data generated to appear as if the data has been deleted
void driverpool::rewriteDriver(vector <Driver>& vecDrivers)
{
	string line;
	ofstream oFile("DriverFile.txt");
	for (unsigned int i = 0; i < vecDrivers.size(); i++)
	{
		tDriverID = vecDrivers[i].getID();
		tName = vecDrivers[i].getName();
		tLisenceNo = vecDrivers[i].getLisenceNo();
		tAddress = vecDrivers[i].getAddress();
		tPhoneNumber = vecDrivers[i].getNumber();
		string outID;
		stringstream newID;
		newID << tDriverID;
		outID = newID.str();
		line = outID + " " + tName + " " + tLisenceNo + " " + tAddress + " " + tPhoneNumber;
		oFile << line;
		oFile << endl;
	}
}