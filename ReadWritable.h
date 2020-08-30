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


#ifndef SDDS_READWRITABLE_H
#define  SDDS_READWRITABLE_H

namespace sdds {
	class ReadWritable
	{
		
	protected:
		//comma separated values flag
		bool commaSeparated;
		ReadWritable();
		// empty destructor
		virtual ~ReadWritable();
	public:
		// returns commaSeparated
		bool isCsv() const;
		//sets commaSeparated
		void setCsv(bool value);
		//pure virtual functions
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
	};
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
	std::istream& operator>>(std::istream& istr, ReadWritable& rw);
}
#endif