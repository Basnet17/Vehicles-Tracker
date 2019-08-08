/*
* File: point.cpp
* Authors: Pritam Basnet.
* ---------------------------------------------
* This file implements the Point class.
*/

#include "point.h"
#include <cmath>
#include <sstream>

/*
* Constructor: Point
* Usage: Point as a default constructor.
*---------------------------------------------------------------------------
* Initialises the values of the instance variables to the type doubles.
*/
Point::Point()
{
	x = 0.0;
	y = 0.0;
}


/*
* Constructor: Point(initX, initY)
* Usage: Point with instance variables set as the different values.
*---------------------------------------------------------------------------
* Equates the instance variables to double type of two values.
*/
Point::Point(double initX, double initY)
{
	x = initX;
	y = initY;
}

/*
* Constructor: Point
* Usage: Introduces the time object to the previous constructor.
*---------------------------------------------------------------------------
* Equates the instance variables to double type of two values along with the time object.
*/
Point::Point(double initX, double initY, Time time)
{
	x = initX;
	y = initY;
	timeStamp = time;
}

/*
* Method: SetX()
* Usage: x = newX; It equates the x co-ordinate of the point to the newX
* --------------------------------------------------------------------------
* Return: None
*/

void Point::setX(double newX)
{
	x = newX;
}

/*
* Method: SetY()
* Usage: y = newY; It equates the co-ordinate of the point to the newY.
* --------------------------------------------------------------------------
* Return: None
*/
void Point::setY(double newY)
{
	y = newY;
}

/*
* Method: getX()
* Usage: x.getX();
* --------------------------------------------------------------------------
* Return: x as the double data type
*/
double Point::getX()
{
	return x;
}

/*
* Method: getY()
* Usage: y.getY();
* --------------------------------------------------------------------------
* Return: y as the double data type
*/
double Point::getY()
{
	return y;
}

/*
* Method: distance(otherPoint)
* Usage: it calcualates the distance between two different point objects
* --------------------------------------------------------------------------
* Return: the distance in double data type.
*/
double Point::distance(Point otherPoint)
{
	return sqrt((x - otherPoint.x) * (x - otherPoint.x) + 
				(y - otherPoint.y) * (y - otherPoint.y));
}

/*
* Method: toString
* Usage: string str = point.toString()
* --------------------------------------------------------------------------
* Returns the strings also uses the << operator to print the point in string
form.
*/
std::string Point::toString()
{
	std::stringstream ss;
	
	ss << "(" << x << ", " << y << ")";
	return ss.str();
}

/*
* Operator: ==
* Usage: checks if two operands are equal or not on the basis of Boolean output.
* ----------------------------------------------------------------------------
* Overloads the == operator so that it is able to compare the two operands.
*/
bool Point::operator==(Point otherPoint)
{
	return (x == otherPoint.x) && (y == otherPoint.y);
}

/*
* Operator: !=
* Usage: checks if two operands are not equal on the basis of Boolean output.
* ----------------------------------------------------------------------------
* Overloads the != operator so that it is able to compare the two operands.
*/
bool Point::operator!=(Point otherPoint)
{
	return !(*this == otherPoint);
}

/*
* Method: getTime()
* Usage: returns the timeStamp of the time object
* ----------------------------------------------------------------------------
* Returns the time object extracted from the time class.
*/
Time Point::getTime()
{
	return timeStamp;
}	









