#include "time.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
 
                          31, 31, 30, 31, 30, 31};
/*
* Constructor: Time
* Usage: Time as a default constructor.
*---------------------------------------------------------------------------
* Initialises the values of the instance variables to different strings values.
*/
Time::Time()
{
	years = "0000";
	months = "00";
	days = "00";
	hours = "00";
	minutes = "00";
	seconds = "00";
}


/*
* Constructor: Time(date, TimeO)
* Usage: Point as the constructor.
*---------------------------------------------------------------------------
* Get different values of the years, months and other instance variables extracting the part of the string.
*/
Time::Time(string date, string TimeO)
{
	years = date.substr(0, 4);
	months = date.substr(5,2);
	days = date.substr(8,2);
	hours = TimeO.substr(0,2);
	minutes = TimeO.substr(3,2);
	seconds = TimeO.substr(6,2);
}

/*
* Function: countLeapYears(year, month)
* Usage: counts how many leap years are there exactly before the year
*-------------------------------------------------------------------------
* Return: returns the number of the leap years before the year
*/
int countLeapYears(int year, int month)
{
    	if (month <= 2)
        	year--;
 
    	return year / 4 - year / 100 + year / 400;
}


/*
* Method: duration(object1)
* Usage: calculates the duration between two dates and two times
* --------------------------------------------------------------------------
* Return: Number of seconds between two dates and two times.
*/
int Time::duration(Time object1)
{
	//Converts the string years, months and all other instance variables to integers.
	int year1;	istringstream (years) >> year1;		
	int month1;	istringstream(months) >>month1;
	int day1;	istringstream(days) >> day1;
	int hour1;	istringstream(hours) >> hour1;
	int minute1;	istringstream(minutes) >> minute1;
	int second1;	istringstream(seconds) >> second1;

	int year2; 	istringstream (object1.years) >> year2;
	int month2; 	istringstream (object1.months) >> month2;
	int day2; 	istringstream (object1.days) >> day2;
	int hour2; 	istringstream (object1.hours) >> hour2;
	int minute2; 	istringstream (object1.minutes) >> minute2;
	int second2; 	istringstream (object1.seconds) >> second2;

	long int n1 = year1*365 + day1;					//Calculates the total number of days from 0000-00-00 to the given date excluding the month.

    	for (int i=0; i<month1 - 1; i++)
        	n1 += monthDays[i];					//adds the total number of the days using the monthDays constant using the indices
 
    	n1 += countLeapYears(year1, month1);				//adding the total days using the function countLeapYears

    	long int n2 = year2*365 + day2;
    	for (int i=0; i< month2 - 1; i++)
        	n2 += monthDays[i];
    	n2 += countLeapYears(year2, month2);
 	
	long daysdif;							//calculates the difference in days between the two number of days
	daysdif = n1 - n2;
	
	long secondsinDays;
	secondsinDays = abs(daysdif) * 86400;				//calculates the total number of seconds of the days difference
	
	//calculate the difference of the seconds of the time
	if(second2 > second1)
    	{
        	--minute1;
        	second1 += 60;
    	}
	long difseconds;
    	difseconds = second1 - second2;
    	if(minute2 > minute1)
    	{
        	--hour1;
        	minute1 += 60;
    	}
	long difminutes;
	long difhours;
    	difminutes = minute1- minute2;
    	difhours = hour1- hour2;

	long diftime;
	diftime = (difhours * 60 * 60 + difminutes * 60 + difseconds);	//calculates the total difference in time
	return (diftime + secondsinDays); 				//returns the total seconds including the difference in days and seconds in time
}


/*
* Method: toString()
* Usage: string str = time.toString()
* --------------------------------------------------------------------------
* Returns the strings also uses the << operator to print the time in string
form.
*/
string Time::toString()
{
	string dateTime = years+ "-" + months+"-" + days+" "+hours+":" +minutes+ ":" + seconds; 
	return dateTime;
}


/*
* Method: date()
* Usage: string str = time.date()
* --------------------------------------------------------------------------
* Returns the strings also uses the << operator to print the date in string
form.
*/
string Time::date()
{
	string dateOnly = years+ "-" + months+"-" + days;
	return dateOnly;
}


/*
* Method: time()
* Usage: string str = time.date()
* --------------------------------------------------------------------------
* Returns the strings also uses the << operator to print the time in string
form.
*/
string Time::time()
{
	string timeOnly = hours+":" +minutes+ ":" + seconds;
	return timeOnly;
}

//just overloads the << operator so that it can be used to print
ostream & operator<<(ostream & os, Time t1)
{
	return os << t1.toString();
}






