// test_point.cpp
/*
This is the unit test for the point class as it tests various constructors, methods and member function written in point.cpp
*/

#include "point.h"
#include <iostream>
#include <cassert>

using namespace std;

void testConstructors()
{
	Point p1(18.98, 34.76);
	cout << p1.toString();					//prints out the string of the point p1
	assert(p1.toString() == "(18.98, 34.76)");
	assert((p1.getX() == 18.98) && (p1.getY() == 34.76));	//just checks if the x and y co-ordinates are equal or not using assert.

	Point p2(6.58, 8.67);
	cout << p2.toString();					//prints out the string of the point p1
	assert(p2.toString() == "(6.58, 8.67)");
	assert((p2.getX() == 6.58) && (p2.getY() == 8.67));

}

void testSet()
{
	Point p1(6.4, 4.5);
	p1.setX(8.9);						//sets the x value to be 8.9
	assert(p1.getX() == 8.9);				//checks if the value of x is changed by the above statement
	p1.setY(17.34);
	assert(p1.getY() == 17.34);

	Point p2(6.58, 8.67);
	p2.setX(9.98);
	assert(p2.getX() == 9.98);
	p2.setY(13.55);
	assert(p2.getY() == 13.55);
}

void testDistance()
{
	Point p1(6.4 , 4.5);
	Point p2(4.1 , 9.8);
	assert(p1.getX() == 6.4);
	assert(p2.getY() == 9.8);
	assert(p1.distance(p2) < 5.77755);			//checks if the calculated distance is smaller than 5.77755
	assert(p1.distance(p2) > 5.77753);			//checks if the calculated distance is bigger than 5.77753

	Point p3(6.58, 8.67);
	Point p4(23.90, 16.43);
	assert(p3.distance(p4) < 18.979);
	assert(p3.distance(p4) > 18.977);
}

void testTime()
{
	Point p1(6.4, 5.8);
	Time time1 = p1.getTime();
	assert(time1.toString() == "0000-00-00 00:00:00");	//checks if the time of the object time1 is set to be the value.
}

void testOperator()
{
	Point p1(9.8, 4.7);
	Point p2(9.8, 4.7);
	Point p3(7.6, 5.6);
	assert(p1 == p2);					//checks the operator == if the two points are equal
	assert(!(p1==p3));					//checks the operator != if two are not equal to each other
	assert(!(p2==p3));
}
int main()
{
	testConstructors();
	testDistance();
	testSet();
	testTime();
	testOperator();
	return 0;
}
