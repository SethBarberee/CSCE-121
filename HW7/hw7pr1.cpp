#include "std_lib_facilities_4.h"

class Place {
    private:
    string name;
    string address;
    string category;

    public:
    string get_name(){return name;}
    string get_address(){return address;}
    string get_category(){return category;}
    Place(string name, string address, string category);
};

Place :: Place(string nam, string addr, string cat) : name(nam), address(addr), category(cat){}

ostream& operator<< (ostream& out, Place& a){
    out << "Name: " << a.get_name() << endl << "Address: " << a.get_address() << endl << "Category: " << a.get_category() << endl;
    return out;
}

class School : public Place{
    private:
    int grade_level;

    public:
    void set_grade_level(int grade){grade_level = grade;}
    int get_grade_level(){return grade_level;}
    School(string name, string address, string category);
};

School :: School(string nam, string addr, string cat) : Place(nam, addr, cat){}

ostream& operator<< (ostream& out, School& a){
    cout << (Place&)a << endl;
    out << "Grade Level: " << a.get_grade_level() << endl;
    return out;
}

class High_School : public School{
    private:
    string certification;

    public:
    string get_certification(){return certification;}
    High_School(string name, string address, string category, string certification);
};

High_School :: High_School(string nam, string addr, string cat, string cert) : School(nam, addr, cat), certification(cert){
    set_grade_level(12);
}

ostream& operator<< (ostream& out, High_School& a){
    cout << (School&)a << endl;
    out << "Certification: " << a.get_certification() << endl;
    return out;
}

istream& operator>>(istream& is, High_School& a){
    string nam, addr, cat, certification;

    is >> nam >> addr >> cat >> certification;
    a = High_School(nam, addr, cat, certification);
    return is;
}

class College : public School{
    private:
    string degrees;

    public:
    string get_degrees(){return degrees;}
    College(string name, string address, string category, string degrees);
};

College :: College(string nam, string addr, string cat, string degree) : School(nam, addr, cat), degrees(degree){
    set_grade_level(16);
}

ostream& operator<< (ostream& out, College& a){
    cout << (School&)a << endl;
    out << "Degrees: " << a.get_degrees() << endl;
    return out;
}

istream& operator>>(istream& is, College& a){
    string nam, addr, cat, degrees;

    is >> nam >> addr >> cat >> degrees;
    a = College(nam, addr, cat, degrees);
    return is;
}

class Elementary_School : public School{
    private:
    bool has_recess;

    public:
    bool get_has_recess(){return has_recess;}
    Elementary_School(string name, string address, string category, bool has_recess);
};

Elementary_School :: Elementary_School(string nam, string addr, string cat, bool recess) : School(nam, addr, cat), has_recess(recess){
    set_grade_level(4);
}

ostream& operator<<(ostream& out, Elementary_School& a){
    cout << (Elementary_School&)a << endl;
    out << "Has Recess: " << a.get_has_recess() << endl;
    return out;
}

istream& operator>>(istream& is, Elementary_School& a){
    string nam, addr, cat;
    bool recess;

    is >> nam >> addr >> cat >> recess;
    a = Elementary_School(nam, addr, cat, recess);
    return is;
}

class Hospital : public Place {
    private:
    int num_doctors;

    public:
    int get_num_doctors(){return num_doctors;}
    Hospital(string name, string address, string category, int num_doctors);
};

Hospital :: Hospital(string nam, string addr, string cat, int docs) : Place(nam, addr, cat), num_doctors(docs){}

ostream& operator<<(ostream& out, Hospital& a){
    cout << (Place&)a << endl;
    out << "Number of Doctors: " << a.get_num_doctors() << endl;
    return out;
}

class Clinic : public Hospital {
    private:
    string surgeries;

    public:
    string get_surgeries(){return surgeries;}
    Clinic(string name, string address, string category, int num_doctors, string surgeries);
};

Clinic :: Clinic(string nam, string addr, string cat, int docs, string sur) : Hospital(nam, addr, cat, docs), surgeries(sur){}

ostream& operator<<(ostream& out, Clinic& a){
    cout << (Hospital&)a << endl;
    out << "Surgeries: " << a.get_surgeries() << endl;
    return out;
}

istream& operator>>(istream& is, Clinic& a){
    string nam, addr, cat, surgeries;
    int docs;

    is >> nam >> addr >> cat >> docs >> surgeries;
    a = Clinic(nam, addr, cat, docs, surgeries);
    return is;
}

class Stadium : public Place {
    private:
    string team;
    bool has_roof;
    
    public:
    void set_roof(bool roof){has_roof = roof;}
    bool get_has_roof(){return has_roof;}
    string get_team(){return team;}
    Stadium(string name, string address, string category, string team); // Lets child classes use the Place constructor
};

Stadium :: Stadium(string nam, string addr, string cat, string tem) : Place(nam,addr,cat), team(tem){} // Pass this constructor to Place class

ostream& operator<<(ostream& out, Stadium& a){
    cout << (Place&)a << endl;
    out << "Team Name: " << a.get_team() << endl << "Has Roof: " << a.get_has_roof() << endl;
    return out;
}

class Arena : public Stadium {
    private:
    string arena_type;

    public:
    string get_arena_type(){return arena_type;}
    Arena(string name, string address, string category, string team, string arena_type);
};

Arena :: Arena(string nam, string addr, string cat, string tem, string type) : Stadium(nam, addr, cat, tem), arena_type(type){
    set_roof(true);
}

ostream& operator<<(ostream& out, Arena& a){
    cout << (Stadium&)a << endl;
    out << "Arena Type: " << a.get_arena_type() << endl;
    return out;
}

istream& operator>>(istream& is, Arena& a){
    string nam, addr, cat, tem, arena_type;

    is >> nam >> addr >> cat >> tem >> arena_type;
    a = Arena(nam, addr, cat, tem, arena_type);
    return is;
}

class Field : public Stadium {
    private:
    string field_type;

    public:
    string get_field_type(){return field_type;}
    Field(string name, string address, string category, string team, string field_type);
};

Field :: Field(string nam, string addr, string cat, string tem, string type) : Stadium(nam, addr, cat, tem), field_type(type){
    set_roof(false);
}

ostream& operator<<(ostream& out, Field& a){
    cout << (Stadium&)a << endl;
    out << "Field Type: " << a.get_field_type() << endl;
    return out;
}

istream& operator>>(istream& is, Field& a){
    string nam, addr, cat, tem, type;

    is >> nam >> addr >> cat >> tem >> type;
    a = Field(nam, addr, cat, tem, type);
    return is;
}

class Services : public Place {
    private:
    int price;

    public:
    void set_price(int service_price){price = service_price;}
    int get_price(){return price;}
    Services(string name, string address, string category);
};

Services :: Services(string nam, string addr, string cat) : Place(nam, addr, cat){}

ostream& operator<<(ostream& out, Services& a){
    cout << (Place&)a << endl;
    out << "Price: " << a.get_price() << endl;
    return out;
}

class Trash : public Services {
    private:
    bool has_incenerator;

    public:
    bool get_has_incenerator(){return has_incenerator;}
    Trash(string name, string address, string category, bool has_incenerator);
};

Trash :: Trash(string nam, string addr, string cat, bool incenerator) : Services(nam, addr, cat), has_incenerator(incenerator){
    set_price(10);
}

ostream& operator<<(ostream& out, Trash& a){
    cout << (Services&)a << endl;
    out << "Has Incenerator: " << a.get_has_incenerator() << endl;
    return out;
}

istream& operator>>(istream& is, Trash& a){
    string nam, addr, cat;
    bool incenerator;

    is >> nam >> addr >> cat >> incenerator;
    a = Trash(nam, addr, cat, incenerator);
    return is;
}

class Recycling : public Services{
    private:
    string recyclable;
    
    public:
    string get_recyclable(){return recyclable;}
    Recycling(string name, string address, string category, string recyclable);
};

Recycling :: Recycling(string nam, string addr, string cat, string recycle) : Services(nam, addr, cat), recyclable(recycle){
    set_price(20);
}

ostream& operator<<(ostream& out, Recycling& a){
    cout << (Services&)a << endl;
    out << "Recyclables: " << a.get_recyclable() << endl;
    return out;
}

istream& operator>>(istream& is, Recycling& a){
    string nam, addr, cat, recyclables;

    is >> nam >> addr >> cat >> recyclables;
    a = Recycling(nam, addr, cat, recyclables);
    return is;
}

class Water : public Services {
    private:
    bool has_purifier;

    public:
    bool get_has_purifier(){return has_purifier;}
    Water(string name, string address, string category, bool has_purifier);
};

Water :: Water(string nam, string addr, string cat, bool purifier) : Services(nam, addr, cat), has_purifier(purifier){
    set_price(20);
}

ostream& operator<<(ostream& out, Water& a){
    cout << (Services&)a << endl;
    out << "Has Purifier: " << a.get_has_purifier() << endl;
    return out;
}

istream& operator>>(istream& is, Water& a){
    string nam, addr, cat;
    bool purifier;

    is >> nam >> addr >> cat >> purifier;
    a = Water(nam, addr, cat, purifier);
    return is;
}

class Post_Office : public Services {
    private:
    long zip_code;

    public:
    long get_zip_code(){return zip_code;}
    Post_Office(string name, string address, string category, long zip_code);
};

Post_Office :: Post_Office(string nam, string addr, string cat, long zip) : Services(nam, addr, cat), zip_code(zip){
    set_price(1);
}

ostream& operator<<(ostream& out, Post_Office& a){
    cout << (Services&)a << endl;
    out << "Zip Code: " << a.get_zip_code() << endl;
    return out;
}

istream& operator>>(istream& is, Post_Office& a){
    string nam, addr, cat;
    long zip;

    is >> nam >> addr >> cat >> zip;
    a = Post_Office(nam, addr, cat, zip);
    return is;
}

// Import the given file name and add the data in it to the respective vectors in the database
void import_file(string input_file, vector<High_School> &a, vector<College> &b, vector<Arena> &c, vector<Field> &d, vector<Clinic> &e, vector<Trash> &f, vector<Post_Office> &g, vector<Water> &h){
    ifstream ist {input_file};

    if(!ist) error("Can't open input file: ", input_file);

}

int main(){
    return 0;
}
