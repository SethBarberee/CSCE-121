#include "std_lib_facilities_4.h"

// Author: Seth Barberee
// Assignment: Homework 5 Problem 1
// Purpose: MyRide but also read/write to a file

class Customer {
    public:
    string get_name() const {return name;}
    double get_balance() const {return balance;}
    void add_funds(double funds) {balance = balance + funds;}
    Customer(string name, double balance);

    private:
    string name;
    double balance;
};

// Print out Customers in a pretty manner
ostream& operator<<(ostream& os, const Customer& a){
    return os << "Name: " << a.get_name() << endl << "Balance: $" << a.get_balance() << endl;
}

istream& operator>>(istream& is, Customer& a){
    string nam;
    double bal;
    is >> nam >> bal;
    a = Customer(nam, bal);
    return is;
}

// Customer constructor
Customer :: Customer(string nam, double bal) : name(nam), balance(bal){}

class Location {
    public:
    string get_name() const {return name;}
    string get_address() const {return address;}
    double get_latitude() const { return latitude; }
    double get_longitude() const { return longitude; }
    string get_tag(int id) {return tags[id];}
    vector<string> get_tags() {return tags;}
    void print_tags() {
        for (unsigned int i = 0; i < tags.size(); i++){
            if (tags[i] == "null"){
                break;
            }
            cout << "Tag: " << tags[i] << endl;
        }
    }
    void set_latitude(double lat) {latitude = lat;}
    void set_longitude(double lon) {longitude = lon;}
    Location(string name, string address, vector<string> tags, double latitude, double longitude);
    Location(string name, double latitude, double longitude);

    private:
    string name;
    string address;
    vector<string> tags;
    double latitude, longitude;
};

// Print out Locations in a pretty manner
ostream& operator<<(ostream& os, const Location& a){
    return os << "Name: " << a.get_name() << endl << "Address: " << a.get_address() << endl << "Latitude: " << a.get_latitude() << endl << "Longitude: " << a.get_longitude() << endl;
}

istream& operator>>(istream& is, Location& a){
    string nam, addr, tags;
    vector<string> tag;
    double lat, lon;
    int tag_num;
    is >> nam >> addr >> lat >> lon >> tag_num;
    // Get each tag and add it to the location's tags vector
    for (int i = 0; i < tag_num; i++){
        is >> tags;
        tag.push_back(tags);
    }
    a = Location(nam, addr, tag, lat, lon);
    return is;
}

// Location constructors
// Usually for adding a location
Location :: Location(string nam, string addr, vector<string> tag, double lat, double lon) : name(nam), address(addr), tags(tag), latitude(lat), longitude(lon){}
// Mainly used for driver location
Location :: Location(string nam, double lat, double lon) : name(nam), latitude(lat), longitude(lon){}

// Driver class
class Driver {
    private:
    string name;
    double balance;
    
    public:
    Location location;
    string get_name() const {return name;}
    double get_balance() const {return balance;}
    void add_funds(double funds) {balance = balance + funds;}
    Driver(string name, double balance, Location location);
};

// Print out Drivers in a pretty manner
ostream& operator<<(ostream& os, const Driver& a){
    return os << "Name: " << a.get_name() << endl << "Balance: $" << a.get_balance() << endl << "Latitude: " << a.location.get_latitude() << endl << "Longitude: " << a.location.get_longitude() << endl;
}

istream& operator>>(istream& is, Driver& a){
    string nam;
    double bal, lat, lon;
    is >> nam >> bal >> lat >> lon;
    Location Driver_loc = Location(nam,lat,lon);
    a = Driver(nam, bal,Driver_loc);
    return is;
}

// Driver constructor
Driver :: Driver(string nam, double bal, Location loc) : name(nam), balance(bal), location(loc){}

// Convert degrees to radians for the distance function
double deg2rad(double degrees){
   double rad;
   double pi = 3.14;

   rad = (degrees / 180) * pi;

   return rad;
}

// Find distance between two locations
double distance(Location location1, Location location2){
    double x1,x2,y1,y2,R,miles;

    x1 = deg2rad(location1.get_latitude());
    x2 = deg2rad(location2.get_latitude());
    y1 = deg2rad(location1.get_longitude());
    y2 = deg2rad(location2.get_longitude());
    R = 3963.1676;

    miles = acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos((y1-y2))) * R;
    return miles;
}

// Print list of locations in database
void get_Locations(vector<Location> a){
    for (unsigned int i = 0; i < a.size(); i++){
        cout << a[i].get_name() << endl;
    }
}

// Print string of driver who is the closest
string find_Driver(vector<Driver> a, Location location1){
    double min_miles = 1000000000000;
    string driver_name = "";

    for (unsigned int i = 0; i < a.size(); i++){
        Location Driver_loc(a[i].get_name(), a[i].location.get_latitude(),a[i].location.get_longitude());
        if (distance(Driver_loc, location1) < min_miles){
            min_miles = distance(Driver_loc, location1);
            driver_name = a[i].get_name();
        }
    }
    return driver_name;
}

// Find closest location from a start location
Location find_Location(vector<Location> a, Location location1){
    double min_miles = 10000000000;
    Location location = Location(" ",0,0);

    for (unsigned int i = 0; i < a.size(); i++){
        Location Tag_loc(a[i].get_name(), a[i].get_latitude(), a[i].get_longitude());
        if (distance(Tag_loc, location1) < min_miles){
            min_miles = distance(Tag_loc, location1);
            location = Tag_loc;
        }
    }
    return location;
}


// Import the given file name and add the data in it to the respective vectors in the database
void import_file(string input_file, vector<Driver> &a, vector<Customer> &b, vector<Location> &c, vector<string> &d){
    ifstream ist {input_file};
    int Customer_num, Driver_num, Location_num, tag_num;
    string Customer_name, Driver_name, Location_name, address, tag;
    vector<string> tags;

    if(!ist) error("Can't open input file: ", input_file);

    // Get number of Drivers from input file 
    ist >> Driver_num;
    
    // Import each Driver into the database
    for(signed int i = 0; i < Driver_num; i++){
        Driver D = Driver("", 0.0, Location{"", 0.0, 0.0});
        ist >> D;
        a.push_back(D);
    }

    // Get number of Customers from input file
    ist >> Customer_num;

    // Import each Customer into the database
    for(signed int j = 0; j < Customer_num; j++){
        Customer C = Customer("", 0.0);
        ist >> C;
        b.push_back(C);
    }

    // Get number of Locations from input file
    ist >> Location_num;

    // Import each Location into the database
    for(signed int k = 0; k < Location_num; k++){
        // Clear the tags vector in order to keep all tags unique to their location
        tags = {};
        Location L = Location("","",{},0.0,0.0);
        ist >> L;
        vector<string> tags = L.get_tags();
        tag_num = tags.size();
        // Iterate over the tags for the location and add it to the database
        for (signed int i = 0; i < tag_num; i++){
            d.push_back(tags[i]);
        }
        c.push_back(L);
    }
}

// Export the given file with the data from the database
void export_file(string output_file, vector<Driver> &a, vector<Customer> &b, vector<Location> &c){
    ofstream ost {output_file};
    int Customer_num, Driver_num, Location_num, tag_num;
    string Customer_name, Driver_name, Location_name, address, tag;

    if(!ost) error("Can't open output file: ", output_file);

    Driver_num = a.size();

    // Output number of Drivers
    ost << Driver_num << "\n ";
    
    // Output each driver with their respective data
    for(signed int i = 0; i < Driver_num; i++){
        ost << a[i].get_name() << " " <<  a[i].get_balance() << " " << a[i].location.get_latitude() << " " << a[i].location.get_longitude() << "\n ";
    }

    Customer_num = b.size();

    // Output number of Customers
    ost << Customer_num << "\n ";

    // Output each Customer with their respective data
    for(signed int j = 0; j < Customer_num; j++){
        ost << b[j].get_name() << " " << b[j].get_balance() << "\n ";
    }

    Location_num = c.size();

    // Output number of Locations
    ost << Location_num << "\n ";

    // Output each Location with their respective data
    for(signed int k = 0; k < Location_num; k++){
        // Clear the tags vector in order to keep all tags unique to their location
        ost << c[k].get_name() << " " << c[k].get_address() << " " << c[k].get_latitude() << " "  << c[k].get_longitude() << " ";
        vector<string> location_tags =  c[k].get_tags();
        tag_num = location_tags.size();
        ost << tag_num << " ";
        // Iterate over the tags for the location
        for (signed int i = 0; i < tag_num; i++){
            ost << c[k].get_tag(i) << " ";
        }
        ost << "\n ";
    }
}


int main(){

    int choice, tag_duplicate, tag_num;
    unsigned int id;
    double lon, lat, bal, funds, price;
    string nam, addr, tag, tag_choice, start, dest;
    Location star = Location(" ",0,0);
    Location end = Location(" ",0,0);
    vector<string> tags, Location_tags;
    vector<Location> tag_Location;

    // Vectors that will store all the Customer, Location, and Driver data
    vector<Customer> Customers;
    vector<Location> Locations;
    vector<Driver> Drivers;


    cout << "What is the name of the input file?" << endl;
    cout << "Name: ";
    string file_name;
    cin >> file_name;
    // Call the import function
    import_file(file_name, Drivers, Customers, Locations, tags);

    while(true){
        cout << "Welcome to MyRide!" << endl;
        cout << "Please select the option below:" << endl;
        cout << "1) Add a customer" << endl;
        cout << "2) Add a driver" << endl;
        cout << "3) Add a location" << endl;
        cout << "4) Add funds to customer account" << endl;
        cout << "5) Ride request" << endl;
        cout << "6) Print all customers" << endl;
        cout << "7) Print all drivers" << endl;
        cout << "8) Print all locations" << endl;
        cout << "9) Exit" << endl;
        cout << endl;
        cout << "Choice: ";

        cin >> choice;

        switch(choice){
            case 1:
                // Add customer
                cout << endl;
                cout << "What is your name?" << endl;
                cin >> nam;
                cout << "How much is in your balance?" << endl;
                cin >> bal;
                if (bal < 0 || !cin){
                    cout << "Must be a number equal to or greater than $0" << endl;
                    cout << endl;
                }
                // Add customer to database
                Customers.push_back(Customer(nam,bal));
                cout << "Customer added!" << endl;
                cout << endl;
                break;
            case 2:
                // Add driver
                cout << endl;
                cout << "What is the driver's name?" << endl;
                cin >> nam;
                cout << "How much is in the driver's account?" << endl;
                cin >> bal;
                if (bal < 0 || !cin){
                    cout << "Must be a number equal to or greater than $0" << endl;
                    cout << endl;
                }
                cout << "What latitude is the driver at?" << endl;
                cin >> lat;
                if (lat < -90 || lat > 90 || !cin){
                    cout << "Must be between -90 to 90 degrees" << endl;
                    cout << endl;
                    break;
                }
                cout << "What longitude is the driver at?" << endl;
                cin >> lon;
                if (lon < -180 || lon > 180 || !cin){
                    cout << "Must be between -180 to 180 degrees" << endl;
                    cout << endl;
                    break;
                }
                // Add driver to database
                Drivers.push_back(Driver(nam,bal,Location(nam,lat,lon)));
                cout << "Driver added!" << endl;
                cout << endl;
                break;
            case 3:
                // Add location
                // Duplicate tag counter
                tag_duplicate = 0;
                Location_tags = {};
                cout << endl;
                cout << "What is the name of the location?" << endl;
                cin >> nam;
                cout << "What is the address of the location?" << endl;
                cin >> addr;
                // Limit tags to three in order to iterate through later in ride request
                while (true){
                    cout << "Enter a tag for the location or enter done to stop entering tags" << endl;
                    cin >> tag;
                    if (tag == "done"){
                        break;
                    }
                    else {
                         Location_tags.push_back(tag);
                         // Cycle through vector all of tags to find duplicates
                         for (unsigned int i = 0; i < tags.size(); i++ ){
                            if (tags[i] == tag){
                                tag_duplicate = 1;
                                break;
                            }
                         }
                         // Add the tag when we know there are no duplicates
                         if (tag_duplicate < 1){
                            tags.push_back(tag);
                         }
                    }
                }
                cout << "What is the latitude of the location?" << endl;
                cin >> lat;
                if (lat < -90 || lat > 90 || !cin){
                    cout << "Must be between -90 to 90 degrees" << endl;
                    cout << endl;
                    break;
                }
                cout << "What is the longitude of the location?" << endl;
                cin >> lon;
                if (lon < -180 || lon > 180 || !cin){
                  cout << "Must be between -180 to 180 degrees" << endl;
                  cout << endl;
                  break;
                }
                Locations.push_back(Location(nam,addr,Location_tags,lat, lon));
                cout << "Location added!" << endl;
                cout << endl;
                break;
            case 4:
                // Add funds to customer account
                if (Customers.size() >= 1){
                    // Display all acounts
                    cout << "Which account are you adding funds to? (Enter the number to the side of the account desired)" << endl;
                    for(unsigned int i = 0; i < Customers.size(); i++){
                        cout << (i+1) << ") " << Customers[i].get_name() << endl;
                    }
                    cout << "Account: ";
                    cin >> id;
                    if (id > Customers.size() || !cin){
                        cout << "No such account exists in database!" << endl;
                        cout << endl;
                        break;
                    }
                    id = id - 1;
                    cout << "How much would you like to add?" << endl;
                    cout << "Funds: ";
                    cin >> funds;
                    if (funds < 0 || !cin){
                        cout << "Must be a number greater than $0" << endl;
                        cout << endl;
                        break;
                    }
                    Customers[id].add_funds(funds);
                    cout << "$" << funds << " added to " << Customers[id].get_name() << "'s account" << endl;
                    
                }
                else {
                    cout << "No Customers in Database. Can't add funds if there's no customers..." << endl;
                }
                break;
            case 5:
                // Ride request
                cout << endl;
                // We need at least two locations to do a ride request
                if (Locations.size() > 1 && Customers.size() >= 1 && Drivers.size() >= 1){
                    cout << "What location would you like a ride from?" << endl;
                    get_Locations(Locations);
                    cout << "Location: ";
                    cin >> start;
                    // Validate the start location is an actual place
                    for (unsigned int i = 0; i < Locations.size(); i++){
                        if (start == Locations[i].get_name()){
                            star = Location(Locations[i].get_name(),Locations[i].get_latitude(), Locations[i].get_longitude());
                            break;
                        }
                    }
                    // If it's still the default, we know the location doesn't exist
                    if (star.get_name() == " "){
                        cout << "Invalid start location!" << endl;
                        cout << endl;
                        break;
                    }
                    cout << endl;
                    cout << "Location (Bright Building, Memorial Student Center, etc.) or Tag Destination (Store, ResHall, etc.)" << endl;
                    cout << "Enter the number of your choice" << endl;
                    cout << "1) Location" << endl;
                    cout << "2) Tag" << endl;
                    cout << "Selection: ";
                    cin >> choice;
                    switch(choice){
                        case 1:
                            cout << endl;
                            cout << "Choose a destination from the list below" << endl;
                            get_Locations(Locations);
                            cout << "Location: ";
                            cin >> dest;
                            if (dest != start && cin){
                                for (unsigned int i = 0; i < Locations.size(); i++){
                                    if (dest == Locations[i].get_name()){
                                        end = Location(Locations[i].get_name(), Locations[i].get_latitude(), Locations[i].get_longitude());
                                        break;
                                    }
                                }
                                // If it's still the default, we know the location doesn't exist
                                if (end.get_name() == " "){
                                    cout << "Invalid destination!" << endl;
                                    cout << endl;
                                    break;
                                }
                                cout << endl;
                                price = distance(star,end);
                                cout << "The cost will be $" << price << endl;

                                cout << endl;
                                cout << "Which customer account will be debited with the ride request? (Enter the number of the account desired)" << endl;
                                for(unsigned int i = 0; i < Customers.size(); i++){
                                    cout << (i+1) << ") " << Customers[i].get_name() << endl;
                                }
                                cout << "Account: ";
                                cin >> id;
                                // Input not equal to a number
                                if (id == 0){
                                    break;
                                }
                                else if (id > Customers.size()){
                                    cout << "No such account exists in database!" << endl;
                                    cout << endl;
                                    break;
                                }
                                else{
                                    id = id - 1;
                                }

                                if (Customers[id].get_balance() < price){
                                    cout << "Not enough funds in account for ride request. Add funds to be able to do this ride request" << endl;
                                    break;
                                }
                                else {
                                    // Subtract the funds from the customer account
                                    funds = price * -1;
                                    Customers[id].add_funds(funds);
                                    cout << endl;
                                    cout << "$" << Customers[id].get_balance() << " is left in the account." << endl;
                                    // Find closest driver
                                    nam = find_Driver(Drivers,star);
                                    cout << nam << " will be your driver." << endl;
                                    for (unsigned int i = 0; i < Drivers.size(); i++){
                                        if (Drivers[i].get_name() == nam){
                                            id = i;
                                        }
                                    }
                                    // Add the funds to driver account
                                    Drivers[id].add_funds((price * 0.5));
                                    // Set driver's location to the destination since he/she is there now
                                    Drivers[id].location.set_latitude(end.get_latitude());
                                    Drivers[id].location.set_longitude(end.get_longitude());

                                   cout << "Thank you for using MyRide!" << endl;
                                   cout << endl;
                                }
                           }
                           else {
                                cout << "You cannot make the start and end location the same!" << endl;
                           }
                           break;
                        case 2:
                            // Tag based destination
                            cout << "Choose the tag for destination that you would like to go to. (Enter the number of choice)" << endl;
                            cout << endl;
                            for (unsigned int i = 0; i < tags.size(); i++){
                                cout << i+1 << ") " << tags[i] << endl;
                            }
                            cout << "Tag: ";
                            cin >> id;
                            if (id > tags.size() || !cin){
                                cout << "No such tag in database!" << endl;
                                cout << endl;
                                break;
                            }
                            tag_choice = tags[(id-1)];
                            for (unsigned int i = 0; i < Locations.size(); i++){
                                Location_tags = Locations[i].get_tags();
                                tag_num = Location_tags.size();
                                for (signed int j = 0; j < tag_num; j++){
                                    // Empty tag so skip it
                                    if (Locations[i].get_tag(j) == "null"){
                                        break;
                                    }
                                    else if (Locations[i].get_tag(j) == tag_choice){
                                        // We don't want to start and end in the same destination so we make sure not to add it to the vector
                                        if (Locations[i].get_name() == start){
                                            break;
                                        }
                                        // Add locations with that tag to a vector
                                        tag_Location.push_back(Locations[i]);
                                    }
                                }
                            }
                            end = find_Location(tag_Location, star);
                            cout << end.get_name() << " is the destination" << endl;
                            price = distance(star,end);
                            cout << "The cost will be $" << price << endl;

                            cout << endl;
                            cout << "Which customer account will be debited with the ride request? (Enter the number of the account desired)" << endl;
                            for(unsigned int i = 0; i < Customers.size(); i++){
                                cout << (i+1) << ") " << Customers[i].get_name() << endl;
                            }
                            cout << "Account: ";
                            cin >> id;
                            // Input not equal to a number
                            if (id == 0){
                                break;
                            }
                            else if (id > Customers.size() || !cin){
                                cout << "No such account exists in database!" << endl;
                                cout << endl;
                                break;
                            }
                            else{
                                id = id - 1;
                            }

                            if (Customers[id].get_balance() < price){
                                cout << "Not enough funds in account for ride request. Add funds to be able to do this ride request" << endl;
                                break;
                            }
                            else {
                                // Subtract the funds from the customer account
                                funds = price * -1;
                                Customers[id].add_funds(funds);
                                cout << endl;
                                cout << "$" << Customers[id].get_balance() << " is left in the account." << endl;
                                // Find closest driver
                                nam = find_Driver(Drivers,star);
                                cout << nam << " will be your driver." << endl;
                                for (unsigned int i = 0; i < Drivers.size(); i++){
                                    if (Drivers[i].get_name() == nam){
                                        id = i;
                                    }
                                }
                                // Add the funds to driver account
                                Drivers[id].add_funds((price * 0.5));
                                // Set driver's location to the destination since he/she is there now
                                Drivers[id].location.set_latitude(end.get_latitude());
                                Drivers[id].location.set_longitude(end.get_longitude());

                                cout << "Thank you for using MyRide!" << endl;
                                cout << endl;
                                break;
                            }
                        default:
                            break;
                    }
                }
                // Not enough locations for ride request
                else if (Locations.size() == 1){
                    cout << "You need at least two locations to do a ride request!" << endl;
                }
                // Not enough customers for ride request
                else if (Customers.size() < 1){
                    cout << "You need at least a customer account to do a ride request!" << endl;
                }
                // Not enough drivers for ride request
                else if (Drivers.size() < 1){
                    cout << "You need at least a driver in the database to drive the drive request!" << endl;
                }
                cout << endl;
                break;
            case 6:
                // Print customer info
                cout << endl;
                if (Customers.size() >= 1){
                    for (unsigned int i = 0; i < Customers.size(); i++){
                        cout << Customers[i] << endl;
                    }
                }
                else {
                    cout << "No Customers in Database" << endl;
                }
                cout << endl;
                break;
            case 7:
                // Print driver info
                cout << endl;
                if (Drivers.size() >= 1){
                    for (unsigned int i = 0; i < Drivers.size(); i++){
                        cout << Drivers[i] << endl;
                    }
                }
                else {
                    cout << "No Drivers in Database" << endl;
                }
                cout << endl;
                break;
            case 8:
                // Print location info
                cout << endl;
                if (Locations.size() >= 1){
                    for (unsigned int i = 0;  i < Locations.size(); i++){
                        cout << Locations[i];
                        Locations[i].print_tags();
                        cout << endl;
                    }
                }
                else {
                    cout << "No Locations in Database" << endl;
                }
                cout << endl;
                break;
            case 9:
                // Kill the program
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
    }
    // Kill the program
    if (choice == 9 || !cin){
        cout << "Killing Program..." << endl;
        // Export the database to the file
        export_file(file_name, Drivers, Customers, Locations);
        break;
    }
  }
}
