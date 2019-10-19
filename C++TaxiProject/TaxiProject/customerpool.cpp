#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "customer.h"
#include "customerpool.h"
using namespace std;
// Default Constructor
customerpool::customerpool()
{
	// Sets Integer values to default to 0
	int CustomerID = 0;
}
// Overloaded Constructor
customerpool::customerpool(int newID, string newName, string newAddress, string newNumber)
{
	// assigns values to private variables when passed as parameters
	tCustomerID = newID;
	tName = newName;
	tAddress = newAddress;
	tPhoneNumber = newNumber;
}
// Deconstructor
customerpool::~customerpool()
{
}
// Function to fill Vector from text file
void customerpool::fillVectorCustomer(vector<Customer>& newVecCustomer)
{
	// connects to text file
	ifstream inFile("CustomerFile.txt");
	// checks if text file is open
	if (!inFile.is_open())
	{
		cout << "Press any key to close. " << endl;
	}
	// whilst the program can read in lines
	while (inFile.good())
	{
		// takes in variables from text file and stores them in private varaibles set by class
		inFile >> tCustomerID;
		inFile >> tName;
		inFile >> tAddress;
		inFile >> tPhoneNumber;
		// pushes data took in from text file to vector
		Customer newCustomer(tCustomerID, tName, tAddress, tPhoneNumber);
		newVecCustomer.push_back(newCustomer);
	}
}
// Function to display all values stored in the vector
void customerpool::displayVectorCustomer(const vector<Customer>& newVecCustomer)
{
	// finds the size of the vector
	unsigned int vecSize = newVecCustomer.size();
	// loops for length of vector
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// returns private variables stored in each instance of the vector
		cout << "Customer ID: " << newVecCustomer[i].getID() << endl;
		cout << "Customer Name: " << newVecCustomer[i].getName() << endl;
		cout << "Address: " << newVecCustomer[i].getAddress() << endl;
		cout << "Phone Number: " << newVecCustomer[i].getNumber() << endl;
		cout << endl;
	}
}
// Function to Write to file
void customerpool::writeToCustomer(string line)
{
	// connects to file in append mode
	ofstream oFile("CustomerFile.txt", ios::app);
	// creates a new line and inserts new data into the text file
	oFile << endl;
	oFile << line;
}
// Function that Compiles Information from User Inputs
string customerpool::complileNewCustomer(const vector<Customer>& newVecCustomer)
{
	// to concatenate values - variables which would normally be stored as integers are being stored as strings
	string line;
	// Uses private variables from class to store data temporarily
	tCustomerID = createCustomerID(newVecCustomer);
	// formats integer to string
	string outID;
	stringstream newID;
	newID << tCustomerID;
	outID = newID.str();
	// gets user input from a seperate function
	tName = inputName();
	tAddress = inputAddress();
	tPhoneNumber = inputPhoneNumber();
	// cosntructs line to be wrote into the file
	line = outID + " " + tName + " " + tAddress + " " + tPhoneNumber;
	// returns line
	return line;
}
// Function to find a new unused ID
int customerpool::createCustomerID(const vector<Customer>& newVecCustomer)
{
	int max = 0;
	// finds the size of the vector
	unsigned int vecSize = newVecCustomer.size();
	// loops for length of vector
	for (unsigned int i = 0; i < vecSize; i++)
	{
		// compares value of ID against current max
		if (newVecCustomer[i].getID() > max)
		{
			// if value of ID is greater it is set as the new maximum
			max = newVecCustomer[i].getID();
		}
	}
	// increments the value stored in max and stores it in another variable before returning it
	tCustomerID = max + 1;
	return tCustomerID;
}
// creates Customer Data for Ride Class
char customerpool::createRC()
{
	vector <Customer> newVecCustomer;
	string line;
	// Allows user to chose to select a current customer or create a new one
	int decision = 0;
	cout << "--- WOULD YOU LIKE TO CREATE NEW CUSTOMER DATA? ---" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;
	cout << "Please select an option (1/2) >> ";
	cin >> decision;
	if (decision == 1)
	{
		cout << endl;
		cout << "You have selected to Create New Customer Data" << endl;
		// creates customer data and writes it to text file
		fillVectorCustomer(newVecCustomer);
		line = complileNewCustomer(newVecCustomer);
		writeToCustomer(line);
	}
	// Allows user to select a customer ID and shows the options 
	vector <Customer> newVecCustomer2;
	fillVectorCustomer(newVecCustomer2);
	displayVectorCustomer(newVecCustomer2);
	cout << "Please select a Customer ID >> ";
	cin >> tCustomerID;
	return tCustomerID;
}
// Functions to get user inputs for string variables and return them back to other functions
string customerpool::inputName()
{
	cout << "Enter the Name: ";
	cin >> tName;
	cout << endl;
	return tName;
}
string customerpool::inputAddress()
{
	cout << "Enter the Postcode of the Address: ";
	cin >> tAddress;
	cout << endl;
	return tAddress;
}
string customerpool::inputPhoneNumber()
{
	cout << "Enter the Phone Number of the Customer: ";
	cin >> tPhoneNumber;
	cout << endl;
	return tPhoneNumber;
}
// Function to format functions necessary to write to text file
void customerpool::createCustomer(vector <Customer>& vecCustomers)
{
	string line;
	fillVectorCustomer(vecCustomers);
	line = complileNewCustomer(vecCustomers);
	writeToCustomer(line);
	cout << "Successful addition to the Customer File" << endl;
}
// Query Functions
void customerpool::queryName(vector <Customer>& vecCustomers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector 
	string newName;
	vector <Customer> queryC;
	cout << "Please enter the Name of the Customer you`d like to find >> ";
	cin >> tName;
	unsigned int vecSize = vecCustomers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newName = vecCustomers[i].getName();
		if (tName.compare(newName) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tCustomerID = vecCustomers[i].getID();
			tName = vecCustomers[i].getName();
			tAddress = vecCustomers[i].getAddress();
			tPhoneNumber = vecCustomers[i].getNumber();
			Customer queryCustomer(tCustomerID, tName, tAddress, tPhoneNumber);
			queryC.push_back(queryCustomer);
		}
	}
	queryResults(queryC);
}
void customerpool::queryAddress(vector <Customer>& vecCustomers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newAddress;
	vector <Customer> queryC;
	cout << "Please enter the Postcode of the Address of the Customer you`d like to find >> ";
	cin >> tAddress;
	unsigned int vecSize = vecCustomers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newAddress = vecCustomers[i].getAddress();
		if (tAddress.compare(newAddress) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tCustomerID = vecCustomers[i].getID();
			tName = vecCustomers[i].getName();
			tAddress = vecCustomers[i].getAddress();
			tPhoneNumber = vecCustomers[i].getNumber();
			Customer queryCustomer(tCustomerID, tName, tAddress, tPhoneNumber);
			queryC.push_back(queryCustomer);
		}
	}
	queryResults(queryC);
}
void customerpool::queryPhoneNumber(vector <Customer>& vecCustomers)
{
	// Compares user input against existing values in the text file if a match is successful then data is pushed onto a new vector
	string newPN;
	vector <Customer> queryC;
	cout << "Please enter the Phone Number of the Customer you`d like to find >> ";
	cin >> tPhoneNumber;
	unsigned int vecSize = vecCustomers.size();
	for (unsigned int i = 0; i < vecSize; i++)
	{
		newPN = vecCustomers[i].getNumber();
		if (tPhoneNumber.compare(newPN) != 0)
		{
			cout << "-" << endl;
		}
		else
		{
			tCustomerID = vecCustomers[i].getID();
			tName = vecCustomers[i].getName();
			tAddress = vecCustomers[i].getAddress();
			tPhoneNumber = vecCustomers[i].getNumber();
			Customer queryCustomer(tCustomerID, tName, tAddress, tPhoneNumber);
			queryC.push_back(queryCustomer);
		}
	}
	queryResults(queryC);
}
// Function to show the result of queries
void customerpool::queryResults(vector <Customer>& queryC)
{
	// displays data stored in vectors that may have been pushed there by a correct query
	unsigned int querySize = queryC.size();
	if (querySize > 0)
	{
		cout << endl;
		cout << "--- Query Customer Results ---" << endl;
		displayVectorCustomer(queryC);
	}
	else if (querySize < 0)
	{
		cout << "No results matched your search" << endl;
	}
}
// Delete Function - Allows the user to select a customer to delete
void customerpool::deleteCustomer(vector <Customer>& vecCustomers)
{
	int newID = 0;
	fillVectorCustomer(vecCustomers);
	displayVectorCustomer(vecCustomers);
	cout << endl;
	cout << "Please enter in a Customer ID of the Customer you would like to delete >> ";
	cin >> tCustomerID;
	for (unsigned int i = 0; i < vecCustomers.size(); i++)
	{
		newID = vecCustomers[i].getID();
		if (newID == tCustomerID)
		{
			vecCustomers.erase(vecCustomers.begin() + i);
		}
	}
	rewriteCustomer(vecCustomers);
}
// Function that rewrites the text file with the new data generated to appear as if the data has been deleted
void customerpool::rewriteCustomer(vector <Customer>& vecCustomers)
{
	string line;
	ofstream oFile("CustomerFile.txt");
	for (unsigned int i = 0; i < vecCustomers.size(); i++)
	{
		tCustomerID = vecCustomers[i].getID();
		tName = vecCustomers[i].getName();
		tAddress = vecCustomers[i].getAddress();
		tPhoneNumber = vecCustomers[i].getNumber();
		string outID;
		stringstream newID;
		newID << tCustomerID;
		outID = newID.str();
		line = outID + " " + tName + " " + " " + tAddress + " " + tPhoneNumber;
		oFile << line;
		oFile << endl;
	}
}