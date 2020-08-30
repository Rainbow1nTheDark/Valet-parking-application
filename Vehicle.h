/*
Final Project Milestone 4
Module:Menu
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/


#ifndef SDDS_VEHICLE_H
#define  SDDS_VEHICLE_H

#include "ReadWritable.h"
namespace sdds {
	const int MAX_PLATE = 8;
	class Vehicle : public ReadWritable
	{
		
		char licensePlate[MAX_PLATE + 1];
		char* makeModel = nullptr;
		int parking;
		
	protected:
		void setEmpty();
		bool isEmpty() const;
		
		std::string getMakeModel() const;
		void setMakeModel(const char* makeModel);
	public:
		Vehicle();
		Vehicle(const char* plate, const char* makeModel);
		//cannot get copied
		Vehicle& operator=(const Vehicle& V) = delete;
		~Vehicle();
		//MS6 changing: the function is made as public in order to compare the license plate
		std::string getLicensePlate() const;
		int getParkingSpot() const;
		void setParkingSpot(int spot);
		bool operator==(const char* plate) const;
		bool operator==(const Vehicle& V) const;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;

	};
}
#endif