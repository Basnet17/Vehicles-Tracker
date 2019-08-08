/*
* File: track.cpp
* Authors: Pritam Basnet.
* ---------------------------------------------
* This file implements the track class.
*/

#include <cmath>
#include "track.h"
#include "vector.h"

/*
Function: radians
--------------------------------------------------------------------------------
Usage: it returns the degrees as the radians
*/
double radians(double degrees)
{
	return degrees / 180.0 * M_PI;
}


/*
* Constructor: Track
* Usage: Track as a default constructor.
*---------------------------------------------------------------------------
* Initialises the values of the instance variables to the type string and vectors.
*/
Track::Track()
{
	name = "";
	points = {};
}


/*
* Constructor: Track(n)
* Usage: Track as the constructor with string as the parameter.
*---------------------------------------------------------------------------
* Equates the instance variable to the parameter passed
*/
Track::Track(string n)
{
	name = n;
}


/*
* Constructor: Track(n,p)
* Usage: Track as the constructor with string and vector p as the parameters.
*---------------------------------------------------------------------------
* Equates the instance variable to the parameter passed
*/
Track::Track(string n, Vector<Point> p)
{
	name = n;
	points = p;
}

// Return the approximate distance (in km) between two geographical points.
double Track::distance(Point point1, Point point2)
{
	double kmPerLat = 111.0;
	double kmPerLong = 111.32 * cos(radians(abs(point1.getY() + point2.getY()) / 2.0));
	double differenceLong = abs(point1.getX() - point2.getX());
	double differenceLat = abs(point1.getY() - point2.getY());
	double kmLong = differenceLong * kmPerLong;
	double kmLat = differenceLat * kmPerLat;
	double distanceKm = sqrt(kmLong * kmLong + kmLat * kmLat);
	return distanceKm;						//returns the distance in kilometers between the points p1 and p2
}
    
// Return the approximate distance (in km) between the two points
// in the track with the given indices.
double Track::distanceIndices(int index1, int index2)
{
	Point point1 = points[index1];					//gets the first point from the vectors points
    	Point point2 = points[index2];
    	return distance(point1, point2);				//returns the distance between the point1 and point2
}
        
// Return the approximate speed traveled between the two points
// in the track with the given indices.
double Track::speed(int index1, int index2)
{
	if (index1 == index2) return 0;					//when index1 and index2 are equal 0 is returned.
	Point point1 = points[index1];
	Point point2 = points[index2];
	return distance(point1, point2)/point1.getTime().duration(point2.getTime());		//returns the speed between two points 
}
        
// Add a point and time to the end of the track.
void Track::append(double longitude, double latitude, string date, string time)
{
	Time t(date, time);						//time object initialized with date and time
	Point p(longitude, latitude, t);
	points.add(p);							//appending time and point to the end of the points			
}
        
// Return the number of points on the track.
int Track::length()
{
	return points.size();						//returns the total entries in the vectors as the length
}
			
// Return the average speed over the track.
double Track::averageSpeed()
{
	double TotalDistance;
	double TotalTime;
	int i = 0;
	while (i < (points.size()-1))
	{
		Point point1 = points[i];				//point1 as the first index
		Point point2 = points[i+1];				//point2 as the second index
		TotalDistance = TotalDistance + distance(point1, point2);	//totaldistance is the totaldistance + distance
		TotalTime = TotalTime + point1.getTime().duration(point2.getTime());	//totalTime is the total time 	
		i++;							//increment of the index i
	}
	return TotalDistance/TotalTime;
}
	
// Return the total distance traversed on the track.
double Track::totalDistance()
{
	double TotalDistance;
	int i = 0;
	while (i < (points.size() -1))
	{
		Point point1 = points[i];				//basically calculating the total distance
		Point point2 = points[i+1];
		TotalDistance = TotalDistance + distance(point1, point2);
		i++;
	}
	return TotalDistance;	
}

// Return the distance between the two points that are 
// farthest apart on the track.
double Track::diameter()
{
	double total = 0.0;
	double Tdistance;
	for(int i = 0; i<points.size(); i++)
	{
		for (int j = i+1; j<points.size(); j++)
		{
			Point point1 = points[i];
			Point point2 = points[j];
			Tdistance = Tdistance + distance(point1, point2);		//returns the distance between two points that are the farthest on the track
			if (Tdistance >  total)
			{
				total = Tdistance;			//if Tdistance is greater than total, then total is assigned to total.			
			}
		}
	}
	return Tdistance;					//returns the farthest distance
}
	
// Find the closest distance a point on the track comes to the 
// given point; return this distance and the time(s) when the 
// track comes within error of this distance.
double Track::closestDistance(Point location, double error, Vector<Time>& times)
{
	Point point;
	Time time;
	double minDistance = points[0].distance(location);		//calculates the mini distance from the first point to the location
	for (int i = 1; i < points.size()-1; i++)
	{	
		point = points[i];
		if (point.distance(location) < minDistance + error){	//it has to be minDistance + error
			minDistance = point.distance(location);
		}
	}
	
	for (int i = 0; i<points.size()-1; i++)
	{
		point  = points[i];
		time = point.getTime();
		if (point.distance(location) < minDistance + error)
		{
			times.add(time);
		}
	}
	return minDistance;
}


// Draw the track, using the degToPix function to convert each
// geographical point to an equivalent pixel location in the
// graphics window.

void Track::draw(GWindow gw)
{
	gw.setColor("BLUE");
	for (int index = 1; index < length(); index++)
	{
		gw.drawLine(degToPix(points[index - 1]).getX(), degToPix(points[index - 1]).getY(), 
		            degToPix(points[index]).getX(), degToPix(points[index]).getY());
	}
}

// Convert a Point object containing a geographical location to a tuple
// representing the equivalent pixel in the graphics window.
Point degToPix(Point geoPoint)
{
    double longitude = geoPoint.getX();
    double latitude = geoPoint.getY();
    double x = MAP_WIDTH * ((longitude - MIN_LONG) / (MAX_LONG - MIN_LONG));
    double y = MAP_HEIGHT - MAP_HEIGHT * ((latitude - MIN_LAT) / (MAX_LAT - MIN_LAT));
    return Point(x, y);
}
                
// Convert a Point object containing a pixel location in the graphics window
// to a tuple representing the equivalent geographical location.
Point pixToDeg(Point turtlePoint)
{
    double x = turtlePoint.getX();
    double y = turtlePoint.getY();
    double longitude = MIN_LONG + (x / MAP_WIDTH) * (MAX_LONG - MIN_LONG);
    double latitude = MIN_LAT + (1 - (y / MAP_HEIGHT)) * (MAX_LAT - MIN_LAT);
    return Point(longitude, latitude);
}









