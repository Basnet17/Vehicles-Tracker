/*
*File:muni.cpp
*-------------------------------------------------------------------------------
*This is actually a cool function that allows you to click on the screen-_-
*/

#include "track.h"
#include <fstream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"
#include "map.h"
#include <sstream>
#include <fstream>

using namespace std;

const string MAP_FILENAME = "muni.png"; // background image file name
        
//  Read tracking info from a file into a dictionary of Track objects.
void readTracks(string fileName, Map<string, Track>& tracks)
{
	ifstream infile;					//opening of the file using ifstream
	string tag;
	fileName = "muni_tracking.csv";
	infile.open(fileName);					//infile opens the file with the given filename
	string line1;
	getline(infile, line1);					//used for deleting the unwanted first line
	string line;
	int i = 0;
 	while(getline(infile, line))				//reading each line of the csv file
 	{		
		if (line != line1)				//if the line is not equal to the first line
		{
 		string TimeStamp = line.substr(5,19);		//Just the date and time
		string otherhalf = line.substr(25);
		tag = otherhalf.substr(0, otherhalf.find(',')); //Just the vehicle tag

		string longitudeLine = otherhalf.substr(1 + tag.length());		
		string longitude = longitudeLine.substr(0, longitudeLine.find(','));	//Just the longitude
		string latitudeLine = longitudeLine.substr(1 + longitude.length());
		string latitude = latitudeLine.substr(0, latitudeLine.find(','));	//Just the latitude

		double longi = 0.0;				//initializing the longitude to the double number
		double lat = 0.0;
		stringstream latss;				//exploiting stringstream to convert string to double
		latss << latitude;
		latss >> lat;
		
		stringstream longss;				//exploiting stringstream to convert string to double
		longss << longitude;
		longss >> longi;
		
		string d = TimeStamp.substr(0, 10);		//only the date from the Timestamp string
		string t = TimeStamp.substr(11);		//only the time from the Timestamp string

		//Creating the Map tracks
		if (tracks.containsKey(tag))			// if the map already contains the tag as the key
		{
				tracks[tag].append(longi, lat, d, t);	//append the values to the track which is the value of the key of the map
		}
			else {
				Track tr(tag);			//if the tag is not in the map, it initializes the new track object and then append
				tr.append(longi, lat, d, t);
				tracks[tag] = tr;
		}
		
	}

 	}
 	
}  

// Respond to a mouse click in the graphics window at position (x, y)
// by drawing the closest track and listing the times that the track
// comes within 100 meters of that position.
void clickMap(GWindow gw, int x, int y, const Map<string, Track>& tracks)
{
	if ((x < 0) or (x > MAP_WIDTH) or (y < 0) or (y > MAP_HEIGHT))
		return;

	gw.clear();
	GImage map(MAP_FILENAME);
	gw.draw(map);                 // redraw the map in the window
	
    GOval dot(x, y, 10, 10);
    dot.setFillColor("RED");
    dot.setFilled(true);
    gw.draw(dot);
    
    Point location = pixToDeg(Point(x, y));
    
    // find closest track and thae times when it comes 
    //   within 100 meters of location
    
    Vector<Time> minTimes, times;
    double minDist = 1000000;
    string minName;
    
    for (string name : tracks)
    {
        double distance = tracks[name].closestDistance(location, 0.1, times);  // 100 meters
        if (distance < minDist)
        {
            minDist = distance;
            minName = name;
            minTimes = times;
        }
    }
    
    // print the closest vehicle and times
    
    cout << endl << endl;
    cout << "Vehicle number " << minName << endl;
    cout << "Closest distance: " << /*setprecision(3) <<*/ minDist << " km" << endl;
    cout << "Times:" << endl;
    for (int index = 0; index < minTimes.size(); index++)
    {
        if ((index == 0) || (minTimes[index - 1].duration(minTimes[index]) >= 300))  // 5 minutes
        {
        	cout << minTimes[index].time() << endl;
       	}
    }

    tracks[minName].draw(gw);     // draw the track
}

int main()
{    
	Map<string, Track> tracks;                 // dictionary of tracks
	readTracks("muni_tracking.csv", tracks);   // read tracks into the dictionary

	GWindow gw(MAP_WIDTH, MAP_HEIGHT);
	GImage map(MAP_FILENAME);
	gw.draw(map);                 // draw the map in the window
	
	while(true)
	{
		GMouseEvent e = waitForEvent();
        if (e.getEventType() == MOUSE_PRESSED) 
        {
            clickMap(gw, e.getX(), e.getY(), tracks);
        }
	}
	return 0;
}
