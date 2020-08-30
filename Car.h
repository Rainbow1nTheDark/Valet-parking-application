/*
Final Project Milestone 5
Module:Menu
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/


#ifndef SDDS_CAR_H
#define  SDDS_CAR_H
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle
	{
	private:
		bool carWash;
	public:
		Car();
		Car(const char* plate, const char* MaM);
		// no copying and assigning are permitted
		Car(const Car& car) = delete;
		Car& operator=(Car& car) = delete;
		void setsave();
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout)const;
	};
}
#endif
