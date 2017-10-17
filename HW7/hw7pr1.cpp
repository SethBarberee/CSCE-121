class Place {
    private:
    string name;
    string address;
    string category;

    public:
    void set_category(string cat) {category = cat;}
}

class school : public Place{
    private:
    int grade_level;
}

class park : public Place {
    private:
    int hours_open;
    bool has_pool;
}

class hospital : public Place {
    private:
    int num_doctors;
}

class retail_shop : public Place {
    private:
    string items;
}

class mall : public Place {
    private:
    int num_shops;
}

class stadium : public Place {
    private:
    string team;
    bool has_roof;
}

class restaraunt : public Place {
    private:
    string food_style;
}

class insurance : public Place {
    private:
    string insurance_style;
}

class arena : public stadium {
    private:
    string arena_type;
    stadium :: stadium.has_roof = true;
}

class field : public statidum {
    private:
    stadium :: stadium.has_roof = false;
}
