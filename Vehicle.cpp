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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "ReadWritable.h"
#include "Parking.h"
#include "Vehicle.h"
namespace sdds {
	Vehicle::Vehicle() : ReadWritable() {
		setEmpty();
	}
	Vehicle::Vehicle(const char* plate, const char* makeModel) : ReadWritable(){
		if ((makeModel != nullptr && plate != nullptr && plate[0] != 0 && makeModel[0] != 0) && strlen(makeModel)> 1 && strlen(plate) <= MAX_PLATE)
		{
			delete[] this->makeModel;
			
			this->makeModel = new char[strlen(makeModel) + 1];
			strcpy(this->makeModel, makeModel);
			for (unsigned int i = 0; i < strlen(plate) + 1; i++)
			{
				licensePlate[i] = toupper(plate[i]);
				licensePlate[MAX_PLATE] = 0;
			}
			this->parking = 0;
		}
		else
		{
			setEmpty();
		}
	}
	

	void sdds::Vehicle::setEmpty()
	{
		delete[] this->makeModel;
		makeModel = nullptr;
		this->licensePlate[0] = 0;
		parking = 0;
	}
	sdds::Vehicle::~Vehicle()
	{
		setEmpty();
	}

	bool sdds::Vehicle::isEmpty() const
	{
		return makeModel == nullptr;
	}

	std::string sdds::Vehicle::getLicensePlate() const
	{
		
		return licensePlate;
	}

	std::string sdds::Vehicle::getMakeModel() const
	{
		return makeModel;
	}

	void sdds::Vehicle::setMakeModel(const char* makeModel)
	{
		delete[] this->makeModel;
		this->makeModel = new char[strlen(makeModel) + 1];
		strcpy(this->makeModel, makeModel);
	}

	int sdds::Vehicle::getParkingSpot() const
	{
		return parking;
	}

	void sdds::Vehicle::setParkingSpot(int spot)
	{
		parking = spot;
	}

	bool sdds::Vehicle::operator==(const char* plate) const
	{
		bool returnValue = false;
		int j = 0;
		char temp[MAX_PLATE + 1] = { 0 };
	
		if (plate != nullptr && licensePlate != nullptr && plate[0] != 0 && strlen(plate) == strlen(licensePlate)) {
			while (plate[j]) {
				temp[j] = toupper(licensePlate[j]);
				
				j++;
			}
			if (strcmp(licensePlate, temp) == 0) {
				returnValue = true;
			}
		}
		return returnValue;
	}

	bool sdds::Vehicle::operator==(const Vehicle& V) const
	{
		bool returnValue = false;
		if (!isEmpty() && !V.isEmpty()) {
			if (*this == V.licensePlate) {
				returnValue = true;
			}
		}
		return returnValue;
	}

	std::istream& sdds::Vehicle::read(std::istream& istr)
	{
		
		
	
		if (commaSeparated) {
			
			//temporary stringhh
			std::string temp;
			std::getline(istr, temp, ',');
			parking = std::stoi(temp);
			std::getline(istr,temp, ',');
			//capitalizing
			strcpy(licensePlate, temp.c_str());
			for (unsigned int i = 0; i < temp.size(); i++) {
				licensePlate[i] = toupper(licensePlate[i]);
			}
			
			
			std::getline(istr, temp, ',');
			delete[] makeModel;
			makeModel = new char[temp.size() + 1];
			strcpy(this->makeModel, temp.c_str());

			
		}
		else
		{
			std::string temp;
			std::string tempPL;
			std::cout << "Enter Licence Plate Number: ";
			do{
				std::getline(istr, tempPL);
				
				if (tempPL.size() > MAX_PLATE || tempPL.size() < 1)
				{
					
					std::cout << "Invalid Licence Plate, try again: ";
					
				}
				else
				{
					strcpy(licensePlate, tempPL.c_str());
					for (unsigned int i = 0; i < tempPL.size(); i++) {
						licensePlate[i] = toupper(licensePlate[i]);
					}
					
					licensePlate[MAX_PLATE] = 0;
				
			}
			} while (licensePlate[0] == 0 || tempPL.size() > MAX_PLATE || tempPL.size() < 1);
			std::cout << "Enter Make and Model: ";
			
			while (temp.size() < 2 || temp.size() > 60)
			{
				std::getline(istr, temp, '\n');
				if (temp.size() < 2 || temp.size() > 60)
				{
					std::cout << "Invalid Make and model, try again: ";
					istr.clear();
					
				}
				else
				{
					delete[] makeModel;
					makeModel = new char[temp.size() + 1];
					strcpy(makeModel, temp.c_str());
				}
			}
			
			parking = 0;
		}
		if (istr.fail())
		{
			setEmpty();
		}
		return istr;
	}

	std::ostream& sdds::Vehicle::write(std::ostream& ostr) const
	{
		if (!isEmpty() && parking >= 0)
		{
			if (commaSeparated)
			{
				ostr << parking << "," << licensePlate << "," << makeModel << ",";
			}
			else
			{
				ostr << "Parking Spot Number: ";
				if (parking == 0)
				{
					ostr << "N/A" << std::endl;
				}
				else
				{
					ostr << parking << std::endl;
				}
				ostr << "Licence Plate: " << licensePlate << std::endl;
				ostr << "Make and Model: " << makeModel << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid Vehicle Object" << std::endl;
		}
		return ostr;
	}
}