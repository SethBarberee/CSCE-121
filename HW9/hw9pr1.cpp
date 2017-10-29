#include "std_lib_facilities_4.h"
double pi = 3.14159;
class Shape{
    private:
    int x,y;
    double distance;

    protected:
    double area, perimeter, side_length;
    int num_sides;

    public:
    virtual void calc_perimeter(){
        perimeter = side_length * num_sides;
    };
    virtual void calc_area(){};
    Shape(int x, int y, double distance);
    Shape(int x, int y);
};
Shape :: Shape(int x1, int y1, double vertex_distance) : x(x1), y(y1), distance(vertex_distance){}
Shape :: Shape(int x1, int y1) : x(x1), y(y1){}

class Equilateral_Triangle : public Shape{
    public:
    Equilateral_Triangle(int x, int y, double distance);
};
Equilateral_Triangle :: Equilateral_Triangle(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){}

class Square : public Shape{
    public:
    Square(int x, int y, double distance);
};
Square :: Square(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){}

class Circle : public Shape{
    private:
    double radius;
    void calc_area(){
        area = 2 * pi * radius * radius;
    };
    void calc_perimeter(){
        perimeter = 2 * pi * radius;
    }
    public:
    Circle(int x, int y, int radius);
};
Circle :: Circle(int x1, int y1, int rad) : Shape(x1, y1), radius(rad){
    calc_area();
    calc_perimeter();
}

class Right_Triangle : public Shape{
    int x2,x3,y2,y3;
    public:
    Right_Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
};
Right_Triangle :: Right_Triangle(int x1, int y1, int x_2, int y_2, int x_3, int y_3) : Shape(x1,y1), x2(x_2), y2(y_2), x3(x_3), y3(y_3){}

class Rectangle : public Shape{
    private:
    int width;
    int height;
    void calc_area(){
        area = width * height;
    };
    void calc_perimeter(){
        perimeter = (2 * width) + (2 * height);
    };
    public:
    Rectangle(int x, int y, int width, int height);
};
Rectangle :: Rectangle(int x1, int y1, int width_r, int height_r) : Shape(x1, y1), width(width_r), height(height_r){
    calc_area();
    calc_perimeter();
}

class Regular_Pentagon : public Shape{
    public:
    Regular_Pentagon(int x, int y, double distance);
};
Regular_Pentagon :: Regular_Pentagon(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    num_sides = 5;
    side_length = 0; // Placeholder for calculation
}

class Regular_Hexagon : public Shape{
    public:
    Regular_Hexagon(int x, int y, double distance);
};
Regular_Hexagon :: Regular_Hexagon(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    num_sides = 6;
    side_length = vertex_distance / 2;
}

void import_file(string input, vector<Shape>& a){
    ifstream ist{input};
    if(!ist) error("Can't open input file: ", input);

    char shape_type;
    int x, y, x2, y2, x3, y3, width, height, rad;
    double vertex_distance;
    while(true){
        ist >> shape_type;
        switch(shape_type){
            case 'T':
                // import is a right triangle
                ist >> x >> y >> x2 >> y2 >> x3 >> y3;
                Shape_s = new Right_Triangle(x, y, x2, y2, x3, y3);
                a.push_back(Shape_s);
                break;
            case 'R':
                // import is a rectangle
                ist >> x >> y >> width >> height;
                Shape_s = new Rectangle(x, y, width, height);
                a.push_back(Shape_s);
                break;
            case 'E':
                // import is a equilateral triangle
                ist >> x >> y >> vertex_distance;
                Shape_s = new Equilateral_Triangle(x, y, vertex_distance);
                a.push_back(Shape_s);
                break;
            case 'S':
                // import is a square
                ist >> x >> y >> vertex_distance;
                Shape_s = new Square(x, y, vertex_distance);
                a.push_back(Shape_s);
                break;
            case 'P':
                // import is a pentagon
                ist >> x >> y >> vertex_distance;
                Shape_s = new Regular_Pentagon(x, y, vertex_distance);
                a.push_back(Shape_s);
                break;
            case 'H':
                // import is a hexagon
                ist >> x >> y >> vertex_distance;
                Shape_s = new Regular_Hexagon(x, y, vertex_distance);
                a.push_back(Shape_s);
                break;
            case 'C':
                // import is a circle
                ist >> x >> y >> rad;
                Shape_S = new Circle(x, y, rad);
                a.push_back(Shape_s);
                break;
            default:
                break;
            }
    }
}

int main(){
    try {
        string inputfile;
        vector<Shape> Shapes;
        cout << "What is the file name?" << endl;
        cout << "File name: ";
        cin >> inputfile;
        import_file(inputfile, Shapes);
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
