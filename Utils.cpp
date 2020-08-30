/*
Final Project Milestone 2
Module:Menu
Filename: Menu.h
Author Alexander Balandin
STUDENT ID 132145194
EMAIL abalandin@myseneca.ca
_____________________________________________________________________
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments
_____________________________________________________________________
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds{
	//get an integer. It will not accept any type that is not an integer.
	int getInt() 
	{
		
			char NL = 'x';
			int Value = 0;
			while (NL != '\n')
			{
				scanf("%d%c", &Value, &NL);
				if (NL != '\n')
				{
					cin.clear();
					cin.ignore(1000, '\n');

					printf("Invalid Integer, try again: ");
				}

			}
			return Value;
		
	}
	//asking the user yes or no. Only y(Y) and n(N) are accepted
	bool YesNo()
	{
		char answer = 0;
		char NL = 'x';
		
		bool yesNo = false;
		
		while (NL != '\n') {
			scanf("%c%c", &answer, &NL);
			
			if (tolower(answer) == 'y' && NL == '\n') {
				yesNo = true;
			}
			else if (tolower(answer) == 'n' && NL == '\n') {
				yesNo = false;
			}
			else{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				
			}
		}
		return yesNo;
	}
}