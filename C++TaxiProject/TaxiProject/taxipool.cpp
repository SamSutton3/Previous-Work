#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "taxi.h"
#include "taxipool.h"
using namespace std;
// Default Constructor
taxipool::taxipool()
{
	// Sets Integer values to default to 0
	int tTaxiID = 0;
	int tSeats = 0;
}
// Overloaded Constructor
taxipool::taxipool(int newID, string newReg, int newSeats, string newManu, string newModel)
{
	// assigns values to private variables when passed as parameters
	tTaxiID = newID;
	tReg = newReg;
	tSeats = newSeats;
	tManu = newManu;
	tModel = newModel;
}
// Deconstructor
taxipool::~taxipool()
{
}
// Function to fill Vector from text file
void taxipool::fillVectorTaxi(vector<Taxi>& newVecTaxi)
{
	// connects to text file
	ifstream inFile("TaxiFile.txt");
	// checks if text file is open
	if (!inFile.is_open())
	{
		cout << "Press any key to close. " << endl;
	}
	// whilst the program can read in lines
	while (inFile.good())
	{
		// takes in variables from text file and stores them in private variables set by the class
		inFile >> tTaxiID;
		inFile >> tReg;
		inFile >> tSeats;
		inFile >> tManu;
		inFile >> tModel;
		// pushes data took in from text file to vector
		Taxi newTaxi(tTaxiID, tReg, tSeats, tManu, tModel);
		newVecTaxi.push_back(newTaxi);
	}
}
// Function to display all values stored in the vector
void taxipool::displayVectorTaxi(const vector<Taxi>& newVecTaxi)
{
	// finds the size of the vector and loops for length of vector
	unsigned int vecSize = newVecTaxi.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// returns private variables stored in each instance of the vector
		cout << "Taxi ID: " << newVecTaxi[i].getID() << endl;
		cout << "Registration: " << newVecTaxi[i].getReg() << endl;
		cout << "Passenger Seats: " << newVecTaxi[i].getSeats() << endl;
		cout << "Manufacturer: " << newVecTaxi[i].getManu() << endl;
		cout << "Model Name: " << newVecTaxi[i].getModel() << endl;
		cout << endl;
	}
}
// Function to Write to file in append mode
void taxipool::writeToTaxi(string line)
{
	ofstream oFile("TaxiFile.txt", ios::app);
	// creates a new line and inserts new data into the text file
	oFile << endl;
	oFile << line;
}
// Function that Compiles Information from User Inputs
string taxipool::complileNewTaxi(const vector<Taxi>& newVecTaxi)
{
	// Uses private variables from class to store data temporarily
	string line;
	// gets unused ID 
	tTaxiID = createTaxiID(newVecTaxi);
	// formats integer to string
	string outID;
	stringstream newID;
	newID << tTaxiID;
	outID = newID.str();
	// gets user input from a seperate function
	tReg = inputReg();
	cout << "Enter the Number of Passenger Seats: ";
	cin >> tSeats;
	cout << endl;
	// formats integer to string
	string outSeats;
	stringstream newSeats;
	newSeats << tSeats;
	outSeats = newSeats.str();
	// gets user input from a seperate functions
	tManu = inputManu();
	tModel = inputModel();
	// constructs and returns line to be wrote into the file
	line = outID + " " + tReg + " " + outSeats + " " + tManu + " " + tModel;
	return line;
}
// creates Taxi Data for Ride Class
char taxipool::createRT()
{
	// Allows user to chose to select a current Taxi or create a new one
	vector <Taxi> newVecTaxi;
	string line;
	int decision = 0;
	cout << "--- WOULD YOU LIKE TO CREATE NEW TAXI DATA? ---" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;
	cout << "Please select an option (1/2) >> ";
	cin >> decision;
	if (decision == 1)
	{
		cout << endl;
		// creates taxi data and writes it to text file
		cout << "You have selected to Create New Taxi Data" << endl;
		fillVectorTaxi(newVecTaxi);
		line = complileNewTaxi(newVecTaxi);
		writeToTaxi(line);
	}
	// Allows user to select a customer ID and shows the options 
	vector <Taxi> newVecTaxi2;
	fillVectorTaxi(newVecTaxi2);
	displayVectorTaxi(newVecTaxi2);
	cout << "Please select a Taxi ID >> ";
	cin >> tTaxiID;
	return tTaxiID;
}
// Function gets user inputs for string variables and return them back to other functions
string taxipool::inputReg()
{
	cout << "Enter the Registration Plate: ";
	cin >> tReg;
	cout << endl;
	return tReg;
}
string taxipool::inputManu()
{
	cout << "Enter the Manufacturer: ";
	cin >> tManu;
	cout << endl;
	return tManu;
}
string taxipool::inputModel()
{
	cout << "Enter the Model Name: ";
	cin >> tModel;
	cout << endl;
	return tModel;
}
// Function to find a new unused ID
int taxipool::createTaxiID(const vector<Taxi>& newVecTaxi)
{
	// finds the size of the vector and loops for the length of vector
	int max = 0;
	int tTaxiID = 0;
	unsigned int vecSize = newVecTaxi.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// compares value of ID against current max
		if (newVecTaxi[i].getID() > max)
		{
			// if value of ID is greater it is set as the new maximum
			max = newVecTaxi[i].getID();
		}
	}
	// increments the value stored in max and stores it in another variable before returning it
	tTaxiID = max + 1;
	return tTaxiID;
}

// Function to Write to file in append mode
void taxipool::createTaxi(vector <Taxi>& vecTaxis)
{
	// creates a new line and inserts new data into the text file
	string line;
	fillVectorTaxi(vecTaxis);
	line = complileNewTaxi(vecTaxis);
	writeToTaxi(line);
	cout << "Successful addition to the Taxi File" << endl;
}
// Query Functions
void taxipool::queryReg(vector <Taxi>& vecTaxis)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newReg;
	vector <Taxi> queryT;
	cout << "Please enter the Registration Plate you`d like to find >> ";
	cin >> tReg;
	unsigned int vecSize = vecTaxis.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newReg = vecTaxis[i].getReg();
		if (tReg.compare(newReg) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tTaxiID = vecTaxis[i].getID();
			tReg = vecTaxis[i].getReg();
			tSeats = vecTaxis[i].getSeats();
			tManu = vecTaxis[i].getManu();
			tModel = vecTaxis[i].getModel();
			Taxi queryTaxi(tTaxiID, tReg, tSeats, tManu, tModel);
			queryT.push_back(queryTaxi);
		}
	}
	queryResults(queryT);
}
void taxipool::querySeats(vector <Taxi>& vecTaxis)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	int newSeats;
	vector <Taxi> queryT;
	cout << "Please enter the Number of Passenger Seats for a Car you want to find  >> ";
	cin >> tSeats;
	unsigned int vecSize = vecTaxis.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newSeats = vecTaxis[i].getSeats();
		if (newSeats == tSeats)
		{
			tTaxiID = vecTaxis[i].getID();
			tReg = vecTaxis[i].getReg();
			tSeats = vecTaxis[i].getSeats();
			tManu = vecTaxis[i].getManu();
			tModel = vecTaxis[i].getModel();
			Taxi queryTaxi(tTaxiID, tReg, tSeats, tManu, tModel);
			queryT.push_back(queryTaxi);
		}
		else
		{
			cout << "-" << endl;
		}
	}
	queryResults(queryT);
}
void taxipool::queryManu(vector <Taxi>& vecTaxis)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newManu;
	vector <Taxi> queryT;
	cout << "Please enter the Manufacturer of the Car you`d like to find >> ";
	cin >> tManu;
	unsigned int vecSize = vecTaxis.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newManu = vecTaxis[i].getManu();
		if (tManu.compare(newManu) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tTaxiID = vecTaxis[i].getID();
			tReg = vecTaxis[i].getReg();
			tSeats = vecTaxis[i].getSeats();
			tManu = vecTaxis[i].getManu();
			tModel = vecTaxis[i].getModel();
			Taxi queryTaxi(tTaxiID, tReg, tSeats, tManu, tModel);
			queryT.push_back(queryTaxi);
		}
	}
	queryResults(queryT);
}
void taxipool::queryModel(vector <Taxi>& vecTaxis)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newModel;
	vector <Taxi> queryT;
	cout << "Please enter the Model of the Car you`d like to find >> ";
	cin >> tModel;
	unsigned int vecSize = vecTaxis.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newModel = vecTaxis[i].getModel();
		if (tModel.compare(newModel) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tTaxiID = vecTaxis[i].getID();
			tReg = vecTaxis[i].getReg();
			tSeats = vecTaxis[i].getSeats();
			tManu = vecTaxis[i].getManu();
			tModel = vecTaxis[i].getModel();
			Taxi queryTaxi(tTaxiID, tReg, tSeats, tManu, tModel);
			queryT.push_back(queryTaxi);
		}
	}
	queryResults(queryT);
}

// Function to show the result of queries
void taxipool::queryResults(vector <Taxi>& queryT)
{
	// displays data stored in vectors that may have been pushed there by a correct query
	unsigned int querySize = queryT.size();
	if (querySize > 0)
	{
		cout << endl;
		cout << "--- Taxi Query Results ---" << endl;
		displayVectorTaxi(queryT);
	}
	else if (querySize < 0)
	{
		cout << "No results matched your search" << endl;
	}
}
// Delete Function - Allows the user to select a customer to delete
void taxipool::deleteTaxi(vector <Taxi>& vecTaxis)
{
	int newID = 0;
	fillVectorTaxi(vecTaxis);
	displayVectorTaxi(vecTaxis);
	cout << endl;
	cout << "Please enter in a Taxi ID of a Taxi you would like to delete >> ";
	cin >> tTaxiID;
	for (unsigned int i = 0; i < vecTaxis.size(); i++)
	{
		newID = vecTaxis[i].getID();
		if (newID == tTaxiID)
		{
			vecTaxis.erase(vecTaxis.begin() + i);
		}
	}
	rewriteTaxi(vecTaxis);
}
// Function that rewrites the text file with the new data generated to appear as if the data has been deleted
void taxipool::rewriteTaxi(vector <Taxi>& vecTaxis)
{
	string line;
	ofstream oFile("TaxiFile.txt");
	for (unsigned int i = 0; i < vecTaxis.size(); i++)
	{
		tTaxiID = vecTaxis[i].getID();
		tReg = vecTaxis[i].getReg();
		tSeats = vecTaxis[i].getSeats();
		tManu = vecTaxis[i].getManu();
		tModel = vecTaxis[i].getModel();
		string outID;
		stringstream newID;
		newID << tTaxiID;
		outID = newID.str();
		string outSeats;
		stringstream newSeats;
		newSeats << tSeats;
		outSeats = newSeats.str();
		line = outID + " " + tReg + " " + outSeats + " " + tManu + " " + tModel;
		oFile << line;
		oFile << endl;
	}
}