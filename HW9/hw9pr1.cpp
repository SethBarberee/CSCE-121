// Author: Seth Barberee
// Assignment: Homework 9 Problem 1
// Purpose: Import a file with shapes given x and y coordinates and radius. Calculate area, perimeter, vertex points.

#include "std_lib_facilities_4.h"
const double pi = 3.14159; // tweak this for accuracy of polar coordinates

struct Point{
    double Point_x,Point_y;
    Point(double Point_x, double Point_y);
    double get_x(){return Point_x;}
    double get_y(){return Point_y;}
};
// Print out everything about Points in a pretty fashion
Point :: Point(double x, double y) : Point_x(x), Point_y(y){}
ostream& operator <<(ostream& out, Point& a){
    out << "(" << a.get_x() << ", " << a.get_y() << ")";
}

Point Point_1 = Point(0,0);
Point Point_2 = Point(0,0);
Point Point_3 = Point(0,0);
Point Point_4 = Point(0,0);


class Shape{
    private:
    int num_sides;
    double distance;
    char type;
    vector<Point> Points;

    protected:
    int x, y;
    double area, perimeter, side_length;
    virtual void calc_perimeter(){
        perimeter = side_length * num_sides;
    };
    virtual void calc_area(){};

    public:
    void set_num_sides(int sides){num_sides = sides;}
    int get_num_sides(){return num_sides;}
    void set_type(char shape_type){type = shape_type;}
    char get_type(){return type;}
    double get_perimeter(){return perimeter;}
    double get_area(){return area;};
    void add_point(Point a){
        Points.push_back(a); // add the point to the vector
    }
    void print_points(){
        for (int i = 0; i < Points.size(); i++){
            cout << Points[i] << endl; // print out all the points
        }
    }
    vector<Point> get_points(){return Points;}
    Point get_point(int id){return Points[id];}
    double deg2rad(double degrees){ // used for polar coordinates
        double rad;
        rad = (degrees/180) * pi;
        return rad;
    }
    Shape(int x, int y, double distance);
    Shape(int x, int y);
};
Shape :: Shape(int x1, int y1, double vertex_distance) : x(x1), y(y1), distance(vertex_distance){}
Shape :: Shape(int x1, int y1) : x(x1), y(y1){}
ostream& operator <<(ostream& out, Shape& a){
         out << "Type: " << a.get_type() << endl << "Num_Sides: " << a.get_num_sides() << endl << "Area: " << a.get_area() << endl << "Perimeter: " << a.get_perimeter() << endl << "Points:" << endl;
        return out;
    }

class Equilateral_Triangle : public Shape{
    public:
    Equilateral_Triangle(int x, int y, double distance);
    protected:
    void calc_area(){
        area = (side_length * side_length) * (sqrt(3)/4);
    }
};
Equilateral_Triangle :: Equilateral_Triangle(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    set_type('E');
    set_num_sides(3);
    side_length = (vertex_distance * 2) / sqrt(3);
    for(int i = 0; i < 360; i = i + (360/3)){
        Point_1 = Point(x1 +( cos(deg2rad(i))*side_length),y1 + (sin(deg2rad(i))*side_length));
        add_point(Point_1);
    }
    calc_area();
    calc_perimeter();
}

class Square : public Shape{
    protected:
    void calc_area(){
        area = side_length * side_length;
    }
    public:
    Square(int x, int y, double distance);
};
Square :: Square(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    set_type('S');
    set_num_sides(4);
    side_length = (vertex_distance * 2);
    Point_1 = Point(x1-vertex_distance,y1+vertex_distance);
    Point_2 = Point(x1+vertex_distance,y1+vertex_distance);
    Point_3 = Point(x1-vertex_distance,y1-vertex_distance);
    Point_4 = Point(x1+vertex_distance,y1-vertex_distance);
    add_point(Point_1);
    add_point(Point_2);
    add_point(Point_3);
    add_point(Point_4);
    calc_area();
    calc_perimeter();
}

class Circle : public Shape{
    private:
    double radius;
    protected:
    void calc_area(){
        area = 2 * pi * radius * radius;
    };
    void calc_perimeter(){
        perimeter = 2 * pi * radius; // Perimeter for a circle is circumference
    }
    public:
    double get_radius(){return radius;}
    Circle(int x, int y, int radius);
};
Circle :: Circle(int x1, int y1, int rad) : Shape(x1, y1), radius(rad){
    set_type('C');
    set_num_sides(1);
    Point_1 = Point(x1, y1);
    add_point(Point_1);
    calc_area();
    calc_perimeter();
}

class Right_Triangle : public Shape{
    int x2,x3,y2,y3;
    double side_a;
    double side_b;
    double side_c;
    double a2;
    double b2;
    double c2;
    protected:
    void calc_area(){
        area = (side_a * side_b)/2;
    }
    void calc_perimeter(){
        perimeter = side_a + side_b + side_c;
    }
    public:
    Right_Triangle(int x, int y, int x2, int y2, int x3, int y3);
};
Right_Triangle :: Right_Triangle(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3) : Shape(x_1, y_1), x2(x_2), y2(y_2), x3(x_3), y3(y_3){
    set_type('T');
    set_num_sides(3);
    side_a = sqrt(((x2-x) * (x2-x)) + ((y2 -y) * (y2-y)));
    side_b = sqrt(((x3-x) * (x3-x)) + ((y3 -y) * (y3-y)));
    side_c = sqrt((x2-x3 * (x2-x3)) + ((y2-y3) * (y2-y3)));
    a2 = side_a * side_a;
    b2 = side_b * side_b;
    c2 = side_c * side_c;
    if (a2+b2 == c2 || c2+b2 == a2 || c2+a2 == b2){ // if it passes Pythagorean's theorem then it's a right triangle
        cout << "Definitely is a right triangle" << endl;
    }
    else{
        cout << "Not a right triangle" << endl;
    }
    Point_1 = Point(x_1, y_1);
    Point_2 = Point(x_2, y_2);
    Point_3 = Point(x_3, y_3);
    add_point(Point_1);
    add_point(Point_2);
    add_point(Point_3);
    calc_area();
    calc_perimeter();
}

class Rectangle : public Shape{
    private:
    int width;
    int height;
    protected:
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
    set_type('R');
    set_num_sides(4);
    Point_1 = Point(x1, y1);
    Point_2 = Point(x1+width_r, y1);
    Point_3 = Point(x1+width_r, y1-height_r);
    Point_4 = Point(x1, y1-height_r);
    add_point(Point_1);
    add_point(Point_2);
    add_point(Point_3);
    add_point(Point_4);
    calc_area();
    calc_perimeter();
}

class Regular_Pentagon : public Shape{
    protected:
    void calc_area(){
        area = (side_length * side_length * sqrt(25 + (10 * sqrt(5))))/4;
    }
    public:
    Regular_Pentagon(int x, int y, double distance);
};
Regular_Pentagon :: Regular_Pentagon(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    set_type('P');
    set_num_sides(5);
    side_length = 2 * vertex_distance * sin((pi/5));
    for(int i = 0; i < 360; i = i + (360/5)){
        Point_1 = Point(x1 +( cos(deg2rad(i))*side_length),y1 + (sin(deg2rad(i))*side_length));
        add_point(Point_1);
    }
    calc_area();
    calc_perimeter();
}

class Regular_Hexagon : public Shape{
    protected:
    void calc_area(){
        area = ((3 * sqrt(3))/2) * side_length * side_length;
    }
    public:
    Regular_Hexagon(int x, int y, double distance);
};
Regular_Hexagon :: Regular_Hexagon(int x1, int y1, double vertex_distance) : Shape(x1, y1, vertex_distance){
    set_type('H');
    set_num_sides(6);
    side_length = vertex_distance;
    for(int i = 0; i < 360; i = i + (360/6)){
        Point_1 = Point(x1 +( cos(deg2rad(i))*side_length),y1 + (sin(deg2rad(i))*side_length));
        add_point(Point_1);
    }
    calc_area();
    calc_perimeter();
}

void import_file(string input, vector<Shape>& a){
    ifstream ist{input};
    if(!ist) error("Can't open input file: ", input);
    char shape_type = ' ';
    int x, y, x2, y2, x3, y3, width, height, rad;
    double vertex_distance;
    // Pointers for each object type that will be created
    Right_Triangle* Shape_T = nullptr;
    Rectangle* Shape_R = nullptr;
    Equilateral_Triangle* Shape_E = nullptr;
    Square* Shape_S = nullptr;
    Regular_Pentagon* Shape_P = nullptr;
    Regular_Hexagon* Shape_H = nullptr;
    Circle* Shape_C = nullptr;
    while(!ist.eof()){
        ist >> shape_type;
        switch(shape_type){
            case 'T':
                // import is a right triangle
                ist >> x >> y >> x2 >> y2 >> x3 >> y3;
                Shape_T = new Right_Triangle(x, y, x2, y2, x3, y3);
                a.push_back(*Shape_T); // push the right triangle object to the vector
                shape_type = ' ';
                break;
            case 'R':
                // import is a rectangle
                ist >> x >> y >> width >> height;
                Shape_R = new Rectangle(x, y, width, height);
                a.push_back(*Shape_R); // push the rectangle object to the vector
                shape_type = ' ';
                break;
            case 'E':
                // import is a equilateral triangle
                ist >> x >> y >> vertex_distance;
                Shape_E = new Equilateral_Triangle(x, y, vertex_distance);
                a.push_back(*Shape_E); // push the equilateral triangle object to the vector
                shape_type = ' ';
                break;
            case 'S':
                // import is a square
                ist >> x >> y >> vertex_distance;
                Shape_S = new Square(x, y, vertex_distance);
                a.push_back(*Shape_S); // push the square object to the vector
                shape_type = ' ';
                break;
            case 'P':
                // import is a pentagon
                ist >> x >> y >> vertex_distance;
                Shape_P = new Regular_Pentagon(x, y, vertex_distance);
                a.push_back(*Shape_P); // push the pentagon object to the vector
                shape_type = ' ';
                break;
            case 'H':
                // import is a hexagon
                ist >> x >> y >> vertex_distance;
                Shape_H = new Regular_Hexagon(x, y, vertex_distance);
                a.push_back(*Shape_H); // push the hexagon object to the vector
                shape_type = ' ';
                break;
            case 'C':
                // import is a circle
                ist >> x >> y >> rad;
                Shape_C = new Circle(x, y, rad);
                a.push_back(*Shape_C); // push the circle object to the vector
                shape_type = ' ';
                break;
            default:
                // Doesn't meet criteria for shape so quit
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

        for(int i = 0; i < Shapes.size(); i++){
            cout << Shapes[i]; // output each shape info to the screen
            Shapes[i].print_points(); // print out all the points
            cout << endl;
        }
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
