/*
File: test_time.cpp
This file contains different tests for the time class using different member functions and constructors.
*/
#include <string>
#include "time.h"
#include <cassert>
#include <iostream>

void testConstructor()
{
	Time t1("2018-06-17", "12:07:34");
	cout << t1 << endl;
	assert(t1.toString() == "2018-06-17 12:07:34");

	Time t2("2013-11-08", "03:33:09");
	cout << t2 << endl;
	assert(t2.toString() == "2013-11-08 03:33:09");		//converts the time object t2 into the string and prints it
}

void test_method()
{
	Time t1("2018-06-17", "12:07:34");
	assert(t1.date() == "2018-06-17");
	assert(t1.time() == "12:07:34");		//Equates if the times are equal.

	Time t2("2013-11-08", "03:33:09");
	assert(t2.date() == "2013-11-08");		//Equates if the dates are equal
	assert(t2.time() == "03:33:09");

}

void test_duration()
{
	Time t1("2018-01-17", "23:04:50");
	Time t2("2013-11-08", "03:33:09");
	assert(t1.duration(t2) == 132348701);		//Calculates the duration between two dates and two times

	Time t3("1997-06-17", "09:04:09");
	Time t4("2007-02-25" , "14:18:28");
	assert(t3.duration(t4) == 305837141);

	Time t5("1998-06-13" , "22:30:00");
	Time t6("1998-06-14", "22:30:00");
	assert(t5.duration(t6) == 86400);
}

int main()
{
	testConstructor();
	test_method();
	test_duration();
	return 0;
}
