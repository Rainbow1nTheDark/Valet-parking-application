/*
Final Project Milestone 2
Module:Menu
Filename: Parking.h
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/


#ifndef SDDS_PARKING_H
#define  SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"
namespace sdds {
	const int MAX_NUM_OF_SPOTS = 100;
	class Parking
	{
		//MS6____________________________
		int numOfSpots;
		Vehicle* parkingSpots[MAX_NUM_OF_SPOTS] = {nullptr};
		int numOfParked;
		//_______________________________
		//parking title
		char name[sdds::MAX_NAME + 1];
		Menu menu;
		Menu submenu;
		//checking if an object is empty
		bool isEmpty() const;
		void displayStatus() const;
		//vehicle menu
		
		
		
		
		//exit parking
		bool exit() const;
		//load from
		bool load();

		
		//empty state
		void setSave();
		//stage A of the run function
		int stageA() const;


		//ms6____________________
	
		
		// updated
		void returning();
		// Listing Parked Vehicles
		void listing() const;
		//close the parking
		bool close();
		void save() const;
		void vehicle();
		//______________________
	public:
		Parking();
		//do not set Parking to another Parking object
		Parking(const Parking& parking) = delete;
		Parking(const char* name, int noOfSpots);
		std::string returnName()const;
		~Parking();
		Parking& operator=(const Parking& parking) = delete;
		//the heart of the class
		int run();
	
	};

	
}

#endif