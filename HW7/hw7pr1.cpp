class Place {
    private:
    string name;
    string address;
    string category;
}

class School : public Place{
    private:
    int grade_level;
}

School :: School(string nam, string addr, tring cat, int grade) : name(nam), address(addr), category(cat), grade_level(grade){}

class Park : public Place {
    private:
    int hours_open;
    bool has_pool;
}

Park :: Park(string nam, string addr, string cat, int hours, bool pool) : name(nam), address(addr), category(cat), hours_open(hours), has_pool(pool){}

class Hospital : public Place {
    private:
    int num_doctors;
}

Hospital :: Hospital(string nam, string addr, string cat, int docs) : name(nam), address(addr), category(cat), num_doctors(doc){}

class Retail_shop : public Place {
    private:
    string items;
}

Retail_shop :: Retail_shop(string nam, string addr, string cat, string item) : name(nam), address(addr), category(cat), items(item){}

class Mall : public Place {
    private:
    int num_shops;
}

Mall :: Mall(string nam, string addr, string cat, int nums) : name(nam), address(addr), category(cat), num_shops(nums){}

class Stadium : public Place {
    private:
    string team;
    bool has_roof;
    
    public:
    void set_roof(bool roof){has_roof = roof;}
}

Stadium :: Stadium(string nam, string addr, string cat, string tem, bool roof) : name(nam), address(addr), category(cat), team(tem), has_roof(roof){}

class Restaraunt : public Place {
    private:
    string food_style;
}

Restaraunt :: Restaraunt(string nam, string addr, string cat, string style) : name(nam), address(addr), category(cat), food_style(style){}

class Insurance : public Place {
    private:
    string insurance_style;
}

Insurance :: Insurance(string nam, string addr, string cat, string style) : name(nam), address(addr), category(cat), style(insurance_style){}

class Arena : public Stadium {
    private:
    string arena_type;
}

Arena :: Arena(string nam, string addr, string cat, string type) : name(nam), address(addr), category(cat), arena_type(type){
    Stadium :: Stadium.set_roof(true);
}

class Field : public Stadium {
    private:
    string field_type;
}

Field :: Field(string nam, string addr, string cat, string type) : name(nam), address(addr), category(cat), field_type(type){
    Stadium :: Stadium.set_roof(false);
}
