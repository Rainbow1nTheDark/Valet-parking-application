
/*
Final Project Milestone 2
Module:Menu
Filename: Parking.cpp
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Utils.h"
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
using namespace std;
namespace sdds {
	Parking::Parking() {
		//empty state
		setSave();
	}
	Parking::Parking(const char* name, int noOfSpots) {
		
		if (name != nullptr && name[0] != 0 && noOfSpots >= 10 && noOfSpots <= MAX_NUM_OF_SPOTS) {
			strcpy(this->name, name);
			numOfSpots = noOfSpots;
			for (int i = 0; i < numOfSpots; i++)
			{
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
			}
			numOfParked = 0;
			if (load()) {
				//passing an title
				menu = "Parking Menu, select an action:";
				//passing objects
				menu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
				//passing an title
				submenu = "Select type of the vehicle:";
				//passing objects
				submenu << "Car" << "Motorcycle" << "Cancel" ;
				//setting indentation for submenu
				submenu.setIndentation(1);
				//ms6
				
				
			}

			else {
				//if invalid
				cout << "Error in data file" << endl;
				setSave();
			}
		}
		else {
			//if invalid
			cout << "Error in data file" << endl;
			setSave();
		}
	}
	//************************************************
	std::string Parking::returnName() const
	{
		return name;
	}
	sdds::Parking::~Parking()
	{
		//save data
		save();
		setSave();
	}
	// checking if the object is empty
	bool sdds::Parking::isEmpty() const
	{
		
		return this->name == nullptr || this->name[0] == 0; 
	}
	// display status
	void sdds::Parking::displayStatus() const
	{
		
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		
		cout << left << (this->numOfSpots - numOfParked);
			
			cout << " *****" << endl;
		
	}
	//displaying vehicle menu

	//changed____________________________________
	void sdds::Parking::vehicle() 
	{
		if (numOfParked < numOfSpots) {
			switch (submenu.run()) {

			case 1:
				
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] == nullptr) {
						delete this->parkingSpots[i];
						parkingSpots[i] = new Car;

						// set commaSeparated to false
						cout << endl;
						parkingSpots[i]->setCsv(false);
						parkingSpots[i]->read();
						parkingSpots[i]->setParkingSpot(i + 1);
						cout << endl;
						cout << "Parking Ticket" << endl;
						parkingSpots[i]->write();
						numOfParked++;
						//break
						i = numOfSpots;
					}
				}
				
				break;
			case 2:
				
				for (int i = 0; i < numOfSpots; i++) {
					if (parkingSpots[i] == nullptr) {
						delete this->parkingSpots[i];
						parkingSpots[i] = new Motorcycle;

						// set commaSeparated to false
						
						parkingSpots[i]->setCsv(false);
						parkingSpots[i]->read();
						parkingSpots[i]->setParkingSpot(i + 1);
						
						cout << endl << "Parking Ticket" << endl;
						parkingSpots[i]->write();
						//increase the number of parked vehicles
						numOfParked++;
						i = numOfSpots;
					}
				}
				break;
			case 3:
				cout << "Parking cancelled";
				break;
			default:
				break;
			}
			cout << endl;
		}
		else
		{
			cout << "Parking is full" << endl;
		}
	}
	// printing a returning vehicle
	void sdds::Parking::returning()
	{
		bool nullByte = false;
		int found = 0;
		char licensePlate[9] = { 0 };
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		//receiving a license plate
		while (!nullByte || licensePlate[0] == 0)
		{
			cin >> licensePlate;
			//checking a null byte
			for (unsigned int i = 0; i <= strlen(licensePlate); i++)
			{
				if (licensePlate[i+2] == 0)
				{
					nullByte = true;
					i = strlen(licensePlate);
				}
			}
			if (!nullByte || licensePlate[0] == 0)
			{
				cout << "Invalid Licence Plate, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
			}

		}

		//touppercase the string
		for (unsigned int i = 0; i < strlen(licensePlate); i++) {
			licensePlate[i] = toupper(licensePlate[i]);
		}
		//looking for the plate in the existing plates
		for (int i = 0; i < numOfParked; i++)
		{
			if (this->parkingSpots[i] != nullptr && numOfParked > 0 && (strcmp(parkingSpots[i]->getLicensePlate().c_str(), licensePlate) == 0))
			{
				found = i;
				//break
				i = numOfParked;
			}
			else
			{
				found = -1;
			}
		}
		//output for the user
		if (found >= 0)
		{
			cout << endl << "Returning: " << endl;
			parkingSpots[found]->write();
			delete parkingSpots[found];
			parkingSpots[found] = nullptr;
			cout << endl;
			numOfParked--;
		}
		else
		{
			cout << "License plate " << licensePlate << " Not found" << endl;
		}
	}



	void sdds::Parking::listing() const
	{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numOfSpots; i++)
		{
			if (parkingSpots[i] != nullptr)
			{
				parkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	}
	// closing parking
	//MS6****************************************************************
	bool sdds::Parking::close()
	{
		bool exit = false;
		for (int i = 0; i < this->numOfSpots; i++)
		{
			if (parkingSpots[i] != nullptr)
			{
				exit = true;
				i = numOfSpots;
			}
		}
		if (!exit)
		{
			cout << "Closing Parking" << endl;
			
		}
		else
		{
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			exit = YesNo();
			if (exit)
			{
				cout << "Closing Parking" << endl << endl;
				for (	int i = 0; i < numOfSpots; i++)
				{
					if (parkingSpots[i] != nullptr && numOfParked > 0) {
						cout << "Towing request" << endl;
						cout << "*********************" << endl;
						parkingSpots[i]->write();
						if (i < numOfSpots - 2) {
							cout << endl;
						}
						
						delete parkingSpots[i];
						parkingSpots[i] = nullptr;
						numOfParked--;
					}
				}
			}
			else {
				cout << "Aborted!" << endl;
			}
		}

		return exit;
	}
	// exit parking
	bool sdds::Parking::exit() const
	{
		bool answer = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		answer = YesNo();
		if (answer) {
			cout << "Exiting program!" << endl;
			
		}
		
		return answer;
	}
	// load from
	bool sdds::Parking::load()
	{
		string x;
		std::fstream f(name);
		bool value = false;
		if (!this->isEmpty()) {

			value = true;
			
			
			//read unt il the end of the file
			while (f.good()) {
				
				getline(f, x, ',');
					if (strcmp(x.c_str(), "C") == 0 )
					{
						
						
								delete parkingSpots[numOfParked];
								parkingSpots[numOfParked] = new Car;
								parkingSpots[numOfParked]->setCsv(true);
								parkingSpots[numOfParked]->read(f);
								parkingSpots[numOfParked]->setCsv(false);
								numOfParked++;
								
							
								
							
					}

					else if (strcmp(x.c_str(), "M") == 0 )
					{
						
								delete parkingSpots[numOfParked];
								parkingSpots[numOfParked] = new Motorcycle;
								parkingSpots[numOfParked]->setCsv(true);
								parkingSpots[numOfParked]->read(f);
								parkingSpots[numOfParked]->setCsv(false);
								numOfParked++;
								
								
								
								
							
					
				}
				
			}
		}
		f.close();
		return value;
	}
	//save data into 
	void sdds::Parking::save() const
	{
		if (!isEmpty()) {
	
			ofstream f(name);
			
			for (int i = 0; i < numOfSpots; i++)
			{
				if (parkingSpots[i] != nullptr)
				{
					parkingSpots[i]->setCsv(true);
					parkingSpots[i]->write(f);
					parkingSpots[i]->setCsv(false);
				}
			}
	}
	}
	//empty state
	void Parking::setSave()
	{
		name[0] = 0;
		this->menu = nullptr;
		
		this->submenu = nullptr;
		//MS6
		
		for (int i = 0; i < numOfSpots; i++)
		{
			delete parkingSpots[i];
			parkingSpots[i] = nullptr;
		}
		numOfParked = 0;
		numOfSpots = 0;
		//________
	}
	// stage A of the run function
	int Parking::stageA() const
	{
		this->displayStatus();
		return menu.run();
	}

	



	
	//the heart of the class
	int sdds::Parking::run()
	{
		bool run = true;
		int answer = 0;
		if (submenu && menu) {
			while (run) {
				if (!isEmpty()) {
 					answer = stageA();
					switch (answer) {
					case 1:
						this->vehicle();

						break;
					case 2:
						this->returning();

						break;
					case 3:
						listing();

						break;
					case 4:
						run = !close();
						break;
					case 5:
						run = !exit();
						break;
					}
				}

			}
		}
		return 0;
	}
}