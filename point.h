/*
* File: point.h
* ----------------------------
*This interface imports the point class, which represents a point.
*/
#include <string>
#include "time.h"
class Point
{
	private:
		//instance variables
		double x;  // instance variables
		double y;
		Time timeStamp; //Time object as the instance variable

	public:
		/*
		* Constructor: Point
		* Usage: Point as a default constructor.
		*---------------------------------------------------------------------------
		* Initialises the values of the instance variables to the type doubles.
		*/
		Point();
 

		/*
		* Constructor: Point(initX, initY)
		* Usage: Point with instance variables set as the different values.
		*---------------------------------------------------------------------------
		* Equates the instance variables to double type of two values.
		*/          
		Point(double initX, double initY);


		/*
		* Constructor: Point
		* Usage: Introduces the time object to the previous constructor.
		*---------------------------------------------------------------------------
		* Equates the instance variables to double type of two values along with the time object.
		*/
		Point(double initX, double initY, Time time);


		/*
		* Method: SetX()
		* Usage: x = newX; It equates the x co-ordinate of the point to the newX
		* --------------------------------------------------------------------------
		* Return: None
		*/
		void setX(double newX);  // method prototypes/signatures

		/*
		* Method: SetY()
		* Usage: y = newY; It equates the co-ordinate of the point to the newY.
		* --------------------------------------------------------------------------
		* Return: None
		*/
		void setY(double newY);


		/*
		* Method: getX()
		* Usage: x.getX();
		* --------------------------------------------------------------------------
		* Return: x as the double data type
		*/
		double getX();


		/*
		* Method: getY()
		* Usage: y.getY();
		* --------------------------------------------------------------------------
		* Return: y as the double data type
		*/
		double getY();


		/*
		* Method: distance(otherPoint)
		* Usage: it calcualates the distance between two different point objects
		* --------------------------------------------------------------------------
		* Return: the distance in double data type.
		*/
		double distance(Point otherPoint);


		/*
		* Method: toString
		* Usage: string str = point.toString()
		* --------------------------------------------------------------------------
		* Returns the strings also uses the << operator to print the point in string
		form.
		*/
		std::string toString();

		
		/*
		* Operator: ==
		* Usage: checks if two operands are equal or not on the basis of Boolean output.
		* ----------------------------------------------------------------------------
		* Overloads the == operator so that it is able to compare the two operands.
		*/
		bool operator==(Point otherPoint);


		/*
		* Operator: !=
		* Usage: checks if two operands are not equal on the basis of Boolean output.
		* ----------------------------------------------------------------------------
		* Overloads the != operator so that it is able to compare the two operands.
		*/
		bool operator!=(Point otherPoint);


		/*
		* Method: getTime()
		* Usage: returns the timeStamp of the time object
		* ----------------------------------------------------------------------------
		* Returns the time object extracted from the time class.
		*/
		Time getTime();

};









