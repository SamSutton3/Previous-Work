#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
// Includes Header files for external functions
#include "taxi.h"
#include "driver.h"
#include "customer.h"
#include "ride.h"
#include "customerpool.h"
#include "taxipool.h"
#include "driverpool.h"
#include "ridepool.h"
using namespace std;
// Declaration of Menu Systems
// Functions for Menu Systems 
void mainMenu();
void createDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers);
void viewDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers);
void deleteDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers);
// Functions for Query Menu Systems
void queryDataMenu();
void queryRideMenu(vector <Ride>& vecRides);
void queryTaxiMenu(vector <Taxi>& vecTaxis);
void queryDriverMenu(vector <Driver>& vecDrivers);
void queryCustomerMenu(vector <Customer>& vecCustomers);
// Function to quit
void quit();

int main()
{
	// calls the main menu function
	mainMenu();
	return 0;
}
// Function for main menu
void mainMenu()
{
	// creates an instance for classes
	ridepool rp;
	// creates vectors
	vector <Ride> vecRides;
	vector <Taxi> vecTaxis;
	vector <Driver> vecDrivers;
	vector <Customer> vecCustomers;
	// loops until correct option selected
	int x = 0;
	bool boolX = 1;
	while (boolX)
	{
		// prints out options for user and gets user input
		cout << "--- Taxi Company Database System ---" << endl;
		cout << endl;
		cout << "1 - Create Ride" << endl;
		cout << "2 - Create Data" << endl;
		cout << "3 - View Data" << endl;
		cout << "4 - Query Data" << endl;
		cout << "5 - Delete Data" << endl;
		cout << "6 - Quit" << endl;
		cout << "Please select an option > ";
		cin >> x;
		switch (x)
		{
		// takes user to a function to create ride data
		case 1:
			cout << endl;
			rp.createRide(vecRides);
			break;
		// takes user to different menu systems
		case 2:
			cout << endl;
			createDataMenu(vecRides,vecTaxis,vecDrivers,vecCustomers);
			break;
		case 3:
			cout << endl;
			viewDataMenu(vecRides, vecTaxis, vecDrivers, vecCustomers);
			break;
		case 4:
			cout << endl;
			queryDataMenu();
			break;
		case 5:
			cout << endl;
			deleteDataMenu(vecRides, vecTaxis, vecDrivers, vecCustomers);
			break;
		// exits the program
		case 6:
			cout << endl;
			boolX = 0;
			cout << "Exiting the program" << endl;
			quit();
			break;
		// returns to the current menu if incorrect input
		default:
			mainMenu();
			break;
		}
	}
}
// Fucntion to display data menu
void createDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers)
{
	// creates an instance for classes 
	ridepool rp;
	taxipool tp;
	driverpool dp;
	customerpool cp;
	// loops until correct option selected
	int y = 0;
	bool boolY = 1;
	while (boolY)
	{
		// prints out options for user and gets user input
		cout << "--- Create Data Menu ---" << endl;
		cout << endl;
		cout << "1 - Create Ride" << endl;
		cout << "2 - Create Taxi" << endl;
		cout << "3 - Create Driver" << endl;
		cout << "4 - Create Customer" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		// gets user input
		cin >> y;
		switch (y)
		{
		// takes user to a functions to create data
		case 1:
			cout << endl;
			rp.createRide(vecRides);
			break;

		case 2:
			cout << endl;
			tp.createTaxi(vecTaxis);
			break;
		case 3:
			cout << endl;
			dp.createDriver(vecDrivers);
			break;
		case 4:
			cout << endl;
			cp.createCustomer(vecCustomers);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolY = 0;
			mainMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			createDataMenu(vecRides, vecTaxis, vecDrivers, vecCustomers);
			break;
		}
	}
}
// Fucntion to display data menu
void viewDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers)
{
	// creates an instance for classes 
	ridepool rp;
	taxipool tp;
	driverpool dp;
	customerpool cp;
	// loops until correct option selected
	int y = 0;
	bool boolY = 1;
	while (boolY)
	{
		// prints out options for user and gets user input
		cout << "--- View Data Menu ---" << endl;
		cout << endl;
		cout << "1 - View All Rides" << endl;
		cout << "2 - View All Taxis" << endl;
		cout << "3 - View All Drivers" << endl;
		cout << "4 - View All Customers" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		cin >> y;
		switch (y)
		{
		// takes user to a function to view data
		case 1:
			cout << endl;
			rp.fillVectorRide(vecRides);
			rp.displayVectorRide(vecRides);
			break;
		case 2:
			cout << endl;
			tp.fillVectorTaxi(vecTaxis);
			tp.displayVectorTaxi(vecTaxis);
			break;
		case 3:
			cout << endl;
			dp.fillVectorDriver(vecDrivers);
			dp.displayVectorDriver(vecDrivers);
			break;
		case 4:
			cout << endl;
			cp.fillVectorCustomer(vecCustomers);
			cp.displayVectorCustomer(vecCustomers);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolY = 0;
			mainMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			viewDataMenu(vecRides, vecTaxis, vecDrivers, vecCustomers);
			break;
		}
	}
}
// Fucntion to display query menu
void queryDataMenu()
{
	// creates vectors
	vector <Ride> vecRides;
	vector <Taxi> vecTaxis;
	vector <Driver> vecDrivers;
	vector <Customer> vecCustomers;
	// prints out options for user and gets user input
	int y = 0;
	bool boolY = 1;
	while (boolY)
	{
		// prints out options for user and gets user input
		cout << "--- Query Data Menu ---" << endl;
		cout << endl;
		cout << "1 - Query Ride" << endl;
		cout << "2 - Query Taxi" << endl;
		cout << "3 - Query Driver" << endl;
		cout << "4 - Query Customer" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		cin >> y;
		switch (y)
		// takes user to different menu systems
		{
		case 1:
			cout << endl;
			queryRideMenu(vecRides);
			break;
		case 2:
			cout << endl;
			queryTaxiMenu(vecTaxis);
			break;
		case 3:
			cout << endl;
			queryDriverMenu(vecDrivers);
			break;
		case 4:
			cout << endl;
			queryCustomerMenu(vecCustomers);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolY = 0;
			mainMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			queryDataMenu();
			break;
		}
	}
}
// Function to display query menu
void queryRideMenu(vector <Ride>& vecRides)
{
	// creates an instance for classes 
	ridepool rp;
	// loops until correct option selected
	int z = 0;
	bool boolZ = 1;
	while (boolZ)
	{
		// prints out options for user and gets user input
		cout << "--- Query Ride Menu ---" << endl;
		cout << endl;
		cout << "1 - Query Taxi" << endl;
		cout << "2 - Query Driver" << endl;
		cout << "3 - Query Customerr" << endl;
		cout << "4 - Query Date" << endl;
		cout << "5 - Query Pick Up Location" << endl;
		cout << "6 - Query Destination" << endl;
		cout << "7 - Back" << endl;
		cout << "Please select an option > ";
		cin >> z;
		switch (z)
		{
		// takes user to a function to query data
		case 1:
			cout << endl;
			rp.queryTaxi(vecRides);
			break;
		case 2:
			cout << endl;
			rp.queryDriver(vecRides);
			break;
		case 3:
			cout << endl;
			rp.queryCustomer(vecRides);
			break;
		case 4:
			cout << endl;
			rp.queryDate(vecRides);
			break;
		case 5:
			cout << endl;
			rp.queryPU(vecRides);
			break;
		case 6:
			cout << endl;
			rp.queryDes(vecRides);
			break;
		// returns back to the previous menu
		case 7:
			cout << endl;
			boolZ = 0;
			queryDataMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			queryRideMenu(vecRides);
			break;
		}
	}
}

// Fucntion to display query menu
void queryTaxiMenu(vector <Taxi>& vecTaxis)
{
	// creates an instance for classes 
	taxipool tp;
	// loops until correct option selected
	int z = 0;
	bool boolZ = 1;
	while (boolZ)
	{
		// prints out options for user and gets user input
		cout << "--- Query Taxi Menu ---" << endl;
		cout << endl;
		cout << "1 - Query Reg" << endl;
		cout << "2 - Query Seats" << endl;
		cout << "3 - Query Manufacturer" << endl;
		cout << "4 - Query Model" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		cin >> z;
		switch (z)
		{
		// takes user to a functions to query data
		case 1:
			cout << endl;
			tp.queryReg(vecTaxis);
			break;
		case 2:
			cout << endl;
			tp.querySeats(vecTaxis);
			break;
		case 3:
			cout << endl;
			tp.queryManu(vecTaxis);
			break;
		case 4:
			cout << endl;
			tp.queryModel(vecTaxis);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolZ = 0;
			queryDataMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			queryTaxiMenu(vecTaxis);
			break;
		}
	}
}
// Fucntion to display query menu
void queryDriverMenu(vector <Driver>& vecDrivers)
{
	// creates an instance for classes 
	driverpool dp;
	// loops until correct option selected
	int z = 0;
	bool boolZ = 1;
	while (boolZ)
	{
		// prints out options for user and gets user input
		cout << "--- Query Driver Menu ---" << endl;
		cout << endl;
		cout << "1 - Query Name" << endl;
		cout << "2 - Query Lisence Number" << endl;
		cout << "3 - Query Address" << endl;
		cout << "4 - Query Phone Number" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		cin >> z;
		switch (z)
		{
		// takes user to a function to query data
		case 1:
			cout << endl;
			dp.queryName(vecDrivers);
			break;

		case 2:
			cout << endl;
			dp.queryLisenceNo(vecDrivers);
			break;
		case 3:
			cout << endl;
			dp.queryAddress(vecDrivers);
			break;
		case 4:
			cout << endl;
			dp.queryPhoneNumber(vecDrivers);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolZ = 0;
			queryDataMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			queryDriverMenu(vecDrivers);
			break;
		}
	}
}
// Function to display data menu
void queryCustomerMenu(vector <Customer>& vecCustomers)
{
	// creates an instance for classes 
	customerpool cp;
	// loops until correct option selected
	int z = 0;
	bool boolZ = 1;
	while (boolZ)
	{
		// prints out options for user and gets user input
		cout << "--- Query Customer Menu ---" << endl;
		cout << endl;
		cout << "1 - Query Name" << endl;
		cout << "2 - Query Address" << endl;
		cout << "3 - Query Phone Number" << endl;
		cout << "4 - Back" << endl;
		cout << "Please select an option > ";
		cin >> z;
		switch (z)
		{
		// takes user to a function to query data
		case 1:
			cout << endl;
			cp.queryName(vecCustomers);
			break;
		case 2:
			cout << endl;
			cp.queryAddress(vecCustomers);
			break;
		case 3:
			cout << endl;
			cp.queryPhoneNumber(vecCustomers);
			break;
		// returns back to the previous menu
		case 4:
			cout << endl;
			boolZ = 0;
			queryDataMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			queryCustomerMenu(vecCustomers);
			break;
		}
	}
}
// Fucntion to display data menu for delete
void deleteDataMenu(vector <Ride>& vecRides, vector <Taxi>& vecTaxis, vector <Driver>& vecDrivers, vector <Customer>& vecCustomers)
{
	// creates an instance for classes 
	ridepool rp;
	taxipool tp;
	driverpool dp;
	customerpool cp;
	// loops until correct option selected
	int y = 0;
	bool boolY = 1;
	while (boolY)
	{
		// prints out options for user and gets user input
		cout << "--- Delete Data Menu ---" << endl;
		cout << endl;
		cout << "1 - Delete Ride" << endl;
		cout << "2 - Delete Taxi" << endl;
		cout << "3 - Delete Driver" << endl;
		cout << "4 - Delete Customer" << endl;
		cout << "5 - Back" << endl;
		cout << "Please select an option > ";
		cin >> y;
		switch (y)
		{
		// takes user to a function to delete data
		case 1:
			cout << endl;
			rp.deleteRide(vecRides);
			break;

		case 2:
			cout << endl;
			tp.deleteTaxi(vecTaxis);
			break;
		case 3:
			cout << endl;
			dp.deleteDriver(vecDrivers);
			break;
		case 4:
			cout << endl;
			cp.deleteCustomer(vecCustomers);
			break;
		// returns back to the previous menu
		case 5:
			cout << endl;
			boolY = 0;
			mainMenu();
			break;
		// returns to the current menu if incorrect input
		default:
			deleteDataMenu(vecRides, vecTaxis, vecDrivers, vecCustomers);
			break;
		}
	}
}
// Function to exit the program
void quit()
{
	exit(1);
}