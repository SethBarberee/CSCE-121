double pi = 3.14159;
class Shape{
    private:
    int x,y;
    double distance;
    int num_vertex;
    double area;
    double perimeter;

    public:
    virtual double calc_perimeter(){};
    virtual double calc_area(){};

};
class Equilateral_Triangle : public Shape{};
class Square : public Shape{
    public:
    Square(int x, int y);
};
class Circle : public Shape{
    private:
    double radius;
    double calc_area(){
        area = 2 * pi * (radius)^2;
    };
    double calc_perimeter(){
        perimeter = 2 * pi * radius;
    }
    public:
    Circle(int x, int y, int radius);
};
class Right_Triangle : public Shape{
    int x1,x2,x3,y1,y2,y3;
    public:
    Right_Triangle(int x1, int y1, int x2, int, y2, int x3, int y3);
};
class Rectangle : public Shape{
    private:
    int width;
    int height;
    double calc_area(){
        area = width * height;
    };
    double calc_perimeter(){
        perimeter = (2 * width) + (2 * height);
    };
    public:
    Rectangle(int x, int y, int width, int height);
};
class Regular_Pentagon : public Shape{};

void import_file(string input, vector<Shape>& a){
    ifstream ist{input};
    if(!ist) error("Can't open input file: ", input);

    char shape_type;
    while(true){
        ist >> shape_type;
        switch(shape_type)
            case 'T':
                // import is a right triangle
                break;
            case 'R':
                // import is a rectangle
                break;
            case 'E':
                // import is a equilateral triangle
                break;
            case 'S':
                // import is a square
                break;
            case 'P':
                // import is a pentagon
                break;
            case 'H':
                // import is a hexagon
                break;
            case 'C':
                // import is a circle
                break;
            default:
                break;
    }
}

int main(){
    try {
        string inputfile;
        vector<Shape> Shapes;
        cout << "What is the file name?" << endl;
        cout << "File name: ";
        cin >> input;
        import_file(inputfille, Shapes);
    }
    catch(exception& e){
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...){
        cerr << "some exception\n";
        return 2;
    }

}
