/*
Final Project Milestone 5
Module:Menuh
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"
namespace sdds {
	Car::Car() : Vehicle()
	{
		setsave();
	}

	Car::Car(const char* plate, const char* MaM) : Vehicle(plate, MaM)
	{
		setsave();
	}

	void Car::setsave()
	{
		carWash = false;
	}

	std::istream& Car::read(std::istream& istr)
	{
		
		if (commaSeparated)
		{
			Vehicle::read(istr);
			istr >> carWash;
			istr.ignore(1);
		}
		else
		{
			std::cout <<  "Car information entry" << std::endl;
			Vehicle::read();
			std::cout << "Carwash while parked? (Y)es/(N)o: ";
			carWash = YesNo();
		}
		return istr;
	}

	std::ostream& Car::write(std::ostream& ostr) const
	{
		if (!isEmpty()) {
			if (commaSeparated)
			{
				ostr << "C,";
				Vehicle::write(ostr);
				ostr << ((carWash) ? "1" : "0") << std::endl;

			}
			else
			{
				std::cout << "Vehicle type: Car" << std::endl;
				Vehicle::write(ostr);
				std::cout << ((carWash) ? "With Carwash" : "Without Carwash") << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Car Object" << std::endl;
		}
		return ostr;
	}
}