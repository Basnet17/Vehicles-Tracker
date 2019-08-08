//test_track.cpp

#include "track.h"
#include "vector.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void testThings()
{
	//Initializes the t1-t4 and p1-p4 and is being added to the vector later.
	Time t1("2001-10-10", "12:22:22");
	Point p1(5.0, 7.0 , t1);

	Time t2("2000-08-19", "12:32:32");
	Point p2(4.0 ,9.0 ,t2);

	Time t3("1998-12-17", "10:23:25");
	Point p3(8.0, 5.0, t3);

	Time t4("1997-05-07", "09:23:45");
	Point p4(3.0, 7.0 ,t4);

	Time timefor1 = p1.getTime();
	assert(timefor1.date() == "2001-10-10");		//equates the two strings to clarify if it is correct
	assert(timefor1.time() == "12:22:22");

	Time timefor2 = p2.getTime();
	assert(timefor2.date() == "2000-08-19");		//equates the two strings to clarify if it is correct
	assert(timefor2.time() == "12:32:32");

	//cout << p1.getX() << " " << timefor1.toString() << endl;	//prints the getX and getY of the point p1
	//cout << p1.getY() << " " << timefor1.toString() << endl;

	//equating the two instance variables x and y using the instance variables of the point class
	assert(p1.getX() == 5.0);
	assert(p1.getY() == 7.0);

	assert(p2.getX() == 4.0);
	assert(p2.getY() == 9.0);
	
	Vector <Point> vec1;
	//The four points are being added to the vector vec1
	vec1.add(p1);
	vec1.add(p2);
	vec1.add(p3);
	vec1.add(p4);

	Track z1("FirstTrack", vec1);
	//assert(z1.speed(1,2) == 1.18654e-05);

	assert(z1.distance(p1, p2) < 247.864);			//Calculates the distance between the points p1 and p2
	assert(z1.distance(p2,p1)  > 247.862);
	
	assert(z1.distance(p3, p4) < 596.409);			//Calculates the distance between the points p3 and p4
	assert(z1.distance(p4, p3) > 596.407);

	//uses the method distanceIndices to check the distance between two indices of the points
	assert(z1.distanceIndices(2,3) < 596.409);
	assert(z1.distanceIndices(1,2) > 247.861);

	double sp1 = z1.speed(2,1);
	assert(sp1 < 0.000118655);
	double sp2 = z1.speed(1, 2);
	assert(sp2 > 0.00000118655);

	assert(z1.speed(2,3) > 0.00000117188);			//Decimal approaximation at places
	assert(z1.speed(3,2) < 0.000117188);			//Decimal apporaximation at places

	assert(z1.speed(1,3) < 0.0000239039);
	assert(z1.speed(3,1) > 0.000000239039);

	assert(z1.length() == 4);					//length1
	z1.append(122.41144, 37.79438, "2014-12-01" , "11:03:03");
	assert(z1.length() == 5);					//lenght2

	assert(z1.averageSpeed() > 0.00000204963);			//averageSpeed 1 before adding next point
	assert(z1.diameter() < 52571.5);				//diameter 1 before adding the next point
	assert(z1.totalDistance() < 66798.9);				//totalDistance 1 before adding the next point
	
	z1.append(123.41144, 38.79438, "2015-12-01" , "12:03:03");
	assert(z1.length() == 6);					//length3

	assert(z1.averageSpeed() < 0.000198004);			//averageSpeed 2 after adding the next point
	assert(z1.totalDistance() > 14368.6);				//totalDistance 2 after addint the next point
	assert(z1.diameter() > 52571.3);				//diameter 2 before adding the next point

	Vector<Time> ttt1;
	double error = 17.17;
	Point pc(67.4, 35.98);
	z1.closestDistance(pc, error, ttt1) < 55.0415;			//closestDistance1 with the given values

	Vector<Time> ttt2;
	double error1 = 19.19;
	Point pc1(43.23, 7.44);
	z1.closestDistance(pc1, error1, ttt2) > 40.2340;		//closestDistance2 with the updated values
}


int main()
{
	testThings();	
	return 0;
}
