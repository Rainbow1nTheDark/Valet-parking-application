/*
Final Project Milestone 3
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/
#include <iostream>
#include "ReadWritable.h"
namespace sdds {
	ReadWritable::ReadWritable() {
		
		this->commaSeparated = false;
	}
	// empty destructor
	ReadWritable::~ReadWritable()
	{
	}
	// returns the flag
	bool ReadWritable::isCsv() const
	{
		return commaSeparated;
	}
	//sets the flag
	void ReadWritable::setCsv(bool value) 
	{
		commaSeparated = value;
	}
	
	
	//overloaded extruction && insertion
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw)
	{
		return rw.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, ReadWritable& rw)
	{
		
		return rw.read(istr);
	}

}