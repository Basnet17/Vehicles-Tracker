// time.h
#include <string>
using namespace std;

class Time
{
	public:

		/*
		* Constructor: Time
		* Usage: Time as a default constructor.
		*---------------------------------------------------------------------------
		* Initialises the values of the instance variables to different strings values.
		*/
		Time();


		/*
		* Constructor: Time(date, TimeO)
		* Usage: Point as the constructor.
		*---------------------------------------------------------------------------
		* Get different values of the years, months and other instance variables extracting the part of the string.
		*/
		Time(string date, string TimeO);


		/*
		* Method: toString()
		* Usage: string str = time.toString()
		* --------------------------------------------------------------------------
		* Returns the strings also uses the << operator to print the time in string
		form.
		*/
		string toString();


		/*
		* Method: date()
		* Usage: string str = time.date()
		* --------------------------------------------------------------------------
		* Returns the strings also uses the << operator to print the date in string
		form.
		*/
		string date();


		/*
		* Method: time()
		* Usage: string str = time.date()
		* --------------------------------------------------------------------------
		* Returns the strings also uses the << operator to print the time in string
		form.
		*/
		string time();


		/*
		* Method: duration(object1)
		* Usage: calculates the duration between two dates and two times
		* --------------------------------------------------------------------------
		* Return: Number of seconds between two dates and two times.
		*/
		int duration(Time object1);
			
	private:
		//Instance Variables
		string years;
		string months;
		string days;
		string hours;
		string minutes;
		string seconds;
};

ostream & operator << (ostream & os, Time t1);
