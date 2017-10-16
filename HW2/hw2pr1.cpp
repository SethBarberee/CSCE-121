// Author: Seth Barberee
// Assignment: HW 2 Problem 1
// Purpose: Takes the latitude and longitude of two locations and computes the distance between the two

#include "std_lib_facilities_4.h"

// Convert degrees to radians
double deg_to_rad(const double deg){
    double rad;
    double pi = 3.14;
    rad = (deg / 180) * pi;
    return rad;
}

// Given the radius of the Earth, we calculate the distance between to points given the latitude and longitude of the two points
double distance(const double x1, const double y1, const double x2, const double y2){
    const double R = 3963.1676;
    double miles;
    miles = acos(sin(deg_to_rad(x1))*sin(deg_to_rad(x2)) + cos(deg_to_rad(x1)) * cos(deg_to_rad(x2)) * cos(deg_to_rad((y1-y2)))) * R;
    return miles;
}

int main(){
    double lat1;
    double long1;
    double lat2;
    double long2;

    char direction_lat1;
    char direction_long1;
    char direction_lat2;
    char direction_long2;
    while(true){
        cout << endl;
        cout << "Input the coordinates for the two locations as:" << endl;
        cout << "Latitude for Location 1 Longitude for Location 1 Latitude for Location 2 Longitude for Location 2" << endl;
        cin >> lat1 >> long1 >> lat2 >> long2;
        if (!cin){
            // If it's not a double, kill the program
            cout << "Invalid input! Must be a number between -90 to 90 degrees for latitude and between -180 and 180 for longitude" << endl;
            break;
        }
        else if (lat1 < -90 || lat1 > 90 || long1 < -180 || long1 > 90 || lat2 < -90 || lat2 > 90 || long2 < -180 || long2 > 180){
            // Not within the range from the directions so print error message and kill the program
            cout << "Not within acceptable range\n";
            break;
        }

        if (lat1 < 0){
            // Negative Latitude so it's South
            direction_lat1 = 'S';
        }
        else {
            // Positive Latitude so it's North
            direction_lat1 = 'N';
        }

        if (long1 < 0){
            // Negative Longitude so it's East
            direction_long1 = 'E';
        }
        else {
            // Positive Longitude so it's West
            direction_long1 = 'W';
        }

        if (lat2 < 0){
            // Negative Latitude so it's South
            direction_lat2 = 'S';
        }
        else {
            // Positive Latitude so it's North
            direction_lat2 = 'N';
        }

        if (long2 < 0){
            // Negative Longitude so it's East
            direction_long2 = 'E';
        }
        else {
            // Positive Longitude so it's West
            direction_long2 = 'W';
        }


        // Print the data including the direction and distance
        cout << "Latitude 1: " << abs(lat1) << " degrees " << direction_lat1 << endl;
        cout << "Longitude 1: " << abs(long1) <<  " degrees " << direction_long1 << endl;
        cout << "Latitude 2: " << abs(lat2) <<  " degrees " << direction_lat2 << endl;
        cout << "Longitude 2: " << abs(long2) << " degrees " << direction_long2 << endl;
        cout << "Distance: " << distance(lat1,long1,lat2, long2) << " miles" << endl;
        cout << endl;
    }
}
