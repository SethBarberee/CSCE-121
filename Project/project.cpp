class Customer {
    protected:
    string name;
    double balance;
    string photo;

    public:
    string get_name() const {return name;}
    double get_balance() const {return balance;}
    string get_photo() const {return photo;}
    Customer(string name, double balance, string photo);
};
class Location {
    private:
    double longitude;
    double latitude;

    public:
    double get_longitude() const {return longitude;}
    double get_latitude() const {return latitude;}
    double set_longitude(double lon) {longitude = lon;}
    double set_latitude(double lat) {latitude = lat;}
    Location(double latitude, double longitude);
};
class Driver : public Customer {
    public:
    Location driver_location;
    Driver(string name, double balance, string photo, Location driver_location);
};
class Place {
    private:
    string name;
    string photo;
    vector<string> tags;

    public:
    Location place_location;
    string get_name() const {return name;}
    string get_photo() const {return photo;}
    string get_tag(int id) {return tags[id];}
    vector<string> get_tags(return tags;)
    Place(string name, vector<string> tags, double latitude, double longitude);
};
