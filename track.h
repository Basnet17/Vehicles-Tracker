/*
File: point.h
---------------------------------------------------------------------------------------
This file is the interface of the point class.
*/
#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "vector.h"
#include "gwindow.h"
#include "point.h"

using namespace std;

const int MAP_WIDTH = 770;              // width of background image muni.gif
const int MAP_HEIGHT = 657;             // height of background image muni.gif
const double MIN_LONG = -122.5256;      // longitude range represented in muni.gif
const double MAX_LONG = -122.3564;
const double MIN_LAT = 37.7;            // latitude range represented in muni.gif
const double MAX_LAT = 37.82;

// A sequence of geographical points with time stamps that track a moving object.
class Track
{
  private:
	string name;			//instance variables
	Vector<Point> points;
        
  public:
  
    Track();
    Track(string n);
    Track(string n, Vector<Point> p);

    // Return the approximate distance (in km) between two geographical points.
    double distance(Point point1, Point point2);
    
    // Return the approximate distance (in km) between the two points
    // in the track with the given indices.
    double distanceIndices(int index1, int index2);
        
    // Return the approximate speed traveled between the two points
    // in the track with the given indices.
    double speed(int index1, int index2);
	
        
    // Add a point and time to the end of the track.
    void append(double longitude, double latitude, string date, string time);
        
    // Return the number of points on the track.
    int length();
                
    // Return the average speed over the track.
    double averageSpeed();
        
    // Return the total distance traversed on the track.
    double totalDistance();
    
    // Return the distance between the two points that are 
    // farthest apart on the track.
    double diameter();
        
    // Return the closest distance a point on the track comes to the 
    // given point; return in a reference parameter the time(s) when the 
    // track comes within error of this distance.
    double closestDistance(Point location, double error, Vector<Time>& times);
        
	// Draw the track, using the degToPix function to convert each
    // geographical point to an equivalent pixel location in the
    // graphics window.
    void draw(GWindow gw);
};

// Convert a Point object containing a geographical location to a tuple
// representing the equivalent pixel in the graphics window.
Point degToPix(Point geoPoint);
                
// Convert a Point object containing a pixel location in the graphics window
// to a tuple representing the equivalent geographical location.
Point pixToDeg(Point turtlePoint);

#endif
