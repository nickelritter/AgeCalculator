/* File: AgeCalc.cpp
*  Programmer: Steven Heid
*
*  Purpose:
*  Purpose is to Write a program that takes your birthday and determins how old you are
*
*/
#include <iostream> //allows program to output data to the screen

using std::cout; // program uses cout
using std::cin; // program uses cin
using std::endl;

// function main begins program execution
int main()
{
	//variable declaration
	int bday;  // Bday in format YYYYMMDD
	int date;  // Date in format YYYYMMDD
	int YnumD;  // Date year YYYY
	int MnumD;  // Date month MM
	int DnumD;  // Date day DD
	int YnumB;  // Birthday year YYYY
	int MnumB;  // Birthday month MM
	int DnumB;  // Birthday day DD
	int YearAge;
	int MonthAge;
	int DayAge;

	cout << "When were you born?.. \nUse format YYYYMMDD" << endl;  // promt user for birthdate YYYYMMDD
	cin >> bday; // read int from user into bday

	cout << "What is todays date?.. \nUse format YYYYMMDD" << endl;  // promt user for current date YYYYMMDD
	cin >> date; // read int from user into date

	YnumB = (date - bday) / 10000; // isolates age year fomr int date/bday

	YnumD = date / 10000; // isolates date year from int date YYYY
	YnumB = bday / 10000;  // isolates birth year from int bday YYYY

	MnumD = (date - (YnumD * 10000)) / 100;  // isolates date month 1-12
	MnumB = (bday - (YnumB * 10000)) / 100;  // isolates birth month 1-12

	DnumD = date - (YnumD * 10000 + MnumD * 100);  // isolates date day 1-31
	DnumB = bday - (YnumB * 10000 + MnumB * 100);  // isolates birth day 1-31

	YearAge = YnumD - YnumB;  // calculates age in years

	// if/else to determine month age
	if (MnumB > MnumD)
	{
		//  if birth month is greater than date month, 
		//  subtracts 1year from age to add 12months to date and performs calculation
		//  to find remaning months in age
		YearAge -= 1;
		MonthAge = (MnumD + 12) - MnumB;
	}

	else MonthAge = MnumD - MnumB;

	// if/else to determine day age
	if (DnumB > DnumD)
	{
		//  if birth day is greater than date day, 
		//  subtracts 1month from age to add 31days to date and performs calculation
		//  to find remaning days in age
		MonthAge -= 1;
		DayAge = (DnumD + 31) - DnumB;

	}
	else DayAge = DnumD - DnumB;

	// outputs age in years, months and days to console
	cout << "You are " << YearAge << " years, " << MonthAge << " months, and " << DayAge << " days old." << endl;

	return 0; // indicates the program ended successfully
} // end function main

