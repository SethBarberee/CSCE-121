// Author: Seth Barberee
// Assignment: Homework 3 Problem 1
// Purpose: Calculates distances of 5 locations from the Bright Building and from an user-inputed location
// Date: 9/14/17

#include "std_lib_facilities_4.h"

class Geo_loc {
    public:
    double get_latitude() { return latitude; }
    double get_longitude() { return longitude; }
    Geo_loc(double latitude, double longitude);
    
    private:
    double latitude, longitude;
}; 
// Geo_loc constructor
Geo_loc :: Geo_loc(double lat, double lon) : latitude(lat), longitude(lon){};


class Place_info {
    public:
    Geo_loc location;
    string get_name() {return name;}
    string get_address() {return address;}
    double get_latitude() {
        return location.get_latitude();
    }
    double get_longitude() {
        return location.get_longitude();
    }
    // Iterate over all the tags and output them
    void get_tags() {
        for (int j = 0; j < tags.size(); j++){
            cout << "Tag: " << tags[j] << endl;
        }
    }
    Place_info(string name, string address, vector<string> tags, Geo_loc location);

    private:
    string name;
    string address;
    vector<string> tags;
};

// Place_info contructor
Place_info :: Place_info(string nam, string addr, vector<string> tag, Geo_loc loc) : 
name(nam), address(addr), tags(tag), location(loc){};

// Degree to radians function in order for the distance function to work
double deg2rad(double degrees){
   double rad;
   double pi = 3.14;

   rad = (degrees / 180) * pi;

   return rad;
}

// Find distance between two locations
double distance(Geo_loc location1, Geo_loc location2){
    double x1,x2,y1,y2,R,miles;

    x1 = deg2rad(location1.get_latitude());
    x2 = deg2rad(location2.get_latitude());
    y1 = deg2rad(location1.get_longitude());
    y2 = deg2rad(location2.get_longitude());
    R = 3963.1676;

    miles = acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos((y1-y2))) * R;
    return miles;
}



int main(){
    vector<Place_info> Brazos_locations;
    double latitude, longitude;

    // Bright Building
    Geo_loc Bright(30.618972,-96.338768);
    
    // Lechner Hall
    Geo_loc Lechner_loc(30.616196,-96.343897);
    Place_info Lechner("Lechner Hall", "Lechner Residence Hall, College Station, TX 77840",{"RA", "ResHall"}, Lechner_loc);
    Brazos_locations.push_back(Lechner);

    // Mosher Hall
    Geo_loc Mosher_loc(30.615445,-96.335147);
    Place_info Mosher("Mosher Hall", "725 Mosher Circle, College Station, TX 77840", {"President", "ResHall"}, Mosher_loc);
    Brazos_locations.push_back(Mosher);

    // Memorial Student Center
    Geo_loc MSC_loc(30.612282,-96.341376);
    Place_info MSC("Memorial Student Center", "275 Joe Routt Blvd #2240, College Station, TX 77843", {"Food", "Study"}, MSC_loc);
    Brazos_locations.push_back(MSC);

    // Millican
    Geo_loc Millican_loc(30.466705, -96.203211);
    Place_info Millican("Millican, TX", "Millican, TX", {"Town","Small"}, Millican_loc);
    Brazos_locations.push_back(Millican);

    // Wolf Pen
    Geo_loc Wolf_loc(30.6192,-96.3101);
    Place_info Wolf("Wolf Pen Creek Park", "1015 Colgate Dr, College Station, TX 77840", {"Park","Ampitheater"}, Wolf_loc);
    Brazos_locations.push_back(Wolf);


    // Print out all the info about the locations
    for (int i = 0; i < Brazos_locations.size(); i++){
        cout << "Place_info id: " << i << endl;
        cout << "Name: " << Brazos_locations[i].get_name() << endl;
        cout << "Address: " << Brazos_locations[i].get_address() << endl;
        Brazos_locations[i].get_tags();
        cout << "Latitude: " << Brazos_locations[i].get_latitude() << endl;
        cout << "Longitude: " << Brazos_locations[i].get_longitude() << endl;
        cout << "Distance from Bright Building: " << distance(Bright, Brazos_locations[i].location) <<  " miles" << endl;
        cout << endl;
    }

    cout << "Enter the latitude and longitude for a location that you would like to calculate distance from" << endl;
    cin >> latitude >> longitude;
    if(!cin){
        // If it's not a double, kill the program
        cout << "Invalid input! Must be a number between -90 to 90 degrees for latitude and between -180 and 180 for longitude" << endl;
        return -1;
    }
    else if (latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180 ){
        // Not within the range for valid latitude or longitude so print error message and kill the program
        cout << "Not within acceptable range\n";
        return -1;
    }
    // Create User location with the given latitude and longitude
    Geo_loc User_loc(latitude, longitude);

    // Output the locations with their info and their respective distances from the user location
    for (int i = 0; i < Brazos_locations.size(); i++){
        cout << "Place_info id: " << i << endl;
        cout << "Name: " << Brazos_locations[i].get_name() << endl;
        cout << "Address: " << Brazos_locations[i].get_address() << endl;
        Brazos_locations[i].get_tags();
        cout << "Latitude: " << Brazos_locations[i].get_latitude() << endl;
        cout << "Longitude: " << Brazos_locations[i].get_longitude() << endl;
        cout << "Distance from Given location: " << distance(User_loc, Brazos_locations[i].location) << " miles" << endl;
        cout << endl;
    }
}
