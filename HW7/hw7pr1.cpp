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

class School : public Place{
    private:
    int grade_level;

    public:
    int get_grade_level(){return grade_level;}
    void set_grade_level(int grade){grade_level = grade;}
    School(string name, string address, string category, int grade_level);
    School(string name, string address, string category);
};

School :: School(string nam, string addr, string cat, int grade) : Place(nam, addr, cat),  grade_level(grade){}
School :: School(string nam, string addr, string cat) : Place(nam, addr, cat){}

class High_School : public Place{
    private:
    string certification;

    public:
    string get_certification(){return certification;}
    High_School(string name, string address, string category, certification);
};

High_School :: High_School(string nam, string addr, string cat, string cert) : School(nam, addr, cat), certification(cert){
    set_grade_level(12);
}

class College : public Place{
    private:
    string degrees;

    public:
    string get_degrees(){return degrees;}
    College(string name, string address, string category, string degrees);
}

College :: College(string nam, string addr, string cat, string degree) : School(nam, addr, cat), degrees(degree){
    set_grade_level(16);
}

class Park : public Place {
    private:
    int hours_open;
    bool has_pool;

    public:
    int get_hours_open(){return hours_open;}
    bool get_has_pool(){return has_pool;}
    Park(string name, string address, string category, int hours_open, bool has_pool);
};

Park :: Park(string nam, string addr, string cat, int hours, bool pool) : Place(nam, addr, cat), hours_open(hours), has_pool(pool){}

class Hospital : public Place {
    private:
    int num_doctors;

    public:
    int get_num_doctors(){return num_doctors;}
    Hospital(string name, string address, string category, int num_doctors);
};

Hospital :: Hospital(string nam, string addr, string cat, int docs) : Place(nam, addr, cat), num_doctors(docs){}

class Clinic : public Hospital {
    private:
    string surgeries;

    public:
    string get_surgeries(){return surgeries;}
    Clinic(string name, string address, string category, int num_doctors, string surgeries);
};

Clinic :: Clinic(string nam, string addr, string cat, int docs, string sur) : Hospital(nam, addr, cat, docs), surgeries(sur){}

class Stadium : public Place {
    private:
    string team;
    bool has_roof;
    
    public:
    void set_roof(bool roof){has_roof = roof;}
    bool get_has_roof(){return has_roof;}
    string get_team(){return team;}
    Stadium(string name, string address, string category, string team, bool has_roof);
    Stadium(string name, string address, string category); // Lets child classes use the Place constructor
};

Stadium :: Stadium(string nam, string addr, string cat, string tem, bool roof) : Place(nam, addr, cat), team(tem), has_roof(roof){}
Stadium :: Stadium(string nam, string addr, string cat) : Place(nam,addr,cat){} // Pass this constructor to Place class

class Arena : public Stadium {
    private:
    string arena_type;

    public:
    string get_arena_type(){return arena_type;}
    Arena(string name, string address, string category, string arena_type);
};

Arena :: Arena(string nam, string addr, string cat, string type) : Stadium(nam, addr, cat), arena_type(type){
    set_roof(true);
}

class Field : public Stadium {
    private:
    string field_type;

    public:
    string get_field_type(){return field_type;}
    Field(string name, string address, string category, string field_type);
};

Field :: Field(string nam, string addr, string cat, string type) : Stadium(nam, addr, cat), field_type(type){
    set_roof(false);
}

int main(){
    return 0;
}
