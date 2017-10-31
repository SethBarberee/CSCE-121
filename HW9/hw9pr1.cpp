// Author: Seth Barberee
// Assignment: Homework 9 Problem 1
// Purpose: Import a file with shapes given x and y coordinates and radius. Calculate area, perimeter, vertex points.

#include "std_lib_facilities_4.h"
double pi = 3.14159;

class Shape{
    private:
    int num_sides;
    double distance;
    char type;

    protected:
    int x, y;
    double area, perimeter, side_length;
    virtual void calc_perimeter(){
        perimeter = side_length * num_sides;
    };
    virtual void calc_area(){};

    public:
    void set_num_sides(int sides){num_sides = sides;};
    int get_num_sides(){return num_sides;};
    void set_type(char shape_type){type = shape_type;};
    char get_type(){return type;};
    double get_perimeter(){return perimeter;};
    double get_area(){return area;};
    Shape(int x, int y, double distance);
    Shape(int x, int y);
};
Shape :: Shape(int x1, int y1, double vertex_distance) : x(x1), y(y1), distance(vertex_distance){}
Shape :: Shape(int x1, int y1) : x(x1), y(y1){}
ostream& operator <<(ostream& out, Shape& a){
    out << "Type: " << a.get_type() << endl << "Num_Sides: " << a.get_num_sides() << endl << "Area: " << a.get_area() << endl << "Perimeter: " << a.get_perimeter() << endl;
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
    side_length = (vertex_distance * 2) / sqrt(2);
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
    Circle(int x, int y, int radius);
};
Circle :: Circle(int x1, int y1, int rad) : Shape(x1, y1), radius(rad){
    set_type('C');
    set_num_sides(1);
    calc_area();
    calc_perimeter();
}

class Right_Triangle : public Shape{
    int x2,x3,y2,y3;
    double side_a;
    double side_b;
    double side_c;
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
    side_c = sqrt((side_a * side_a) + (side_b * side_b));
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
    calc_area();
    calc_perimeter();
}

void import_file(string input, vector<Shape>& a){
    ifstream ist{input};
    if(!ist) error("Can't open input file: ", input);
    bool keep_reading = true;
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
    while(keep_reading){
        ist >> shape_type;
        switch(shape_type){
            case 'T':
                // import is a right triangle
                ist >> x >> y >> x2 >> y2 >> x3 >> y3;
                Shape_T = new Right_Triangle(x, y, x2, y2, x3, y3);
                a.push_back(*Shape_T); // push the right triangle object to the vector
                delete[] Shape_T;
                shape_type = ' ';
                break;
            case 'R':
                // import is a rectangle
                ist >> x >> y >> width >> height;
                Shape_R = new Rectangle(x, y, width, height);
                a.push_back(*Shape_R); // push the rectangle object to the vector
                delete[] Shape_R;
                shape_type = ' ';
                break;
            case 'E':
                // import is a equilateral triangle
                ist >> x >> y >> vertex_distance;
                Shape_E = new Equilateral_Triangle(x, y, vertex_distance);
                a.push_back(*Shape_E); // push the equilateral triangle object to the vector
                delete[] Shape_E;
                shape_type = ' ';
                break;
            case 'S':
                // import is a square
                ist >> x >> y >> vertex_distance;
                Shape_S = new Square(x, y, vertex_distance);
                a.push_back(*Shape_S); // push the square object to the vector
                delete[] Shape_S;
                shape_type = ' ';
                break;
            case 'P':
                // import is a pentagon
                ist >> x >> y >> vertex_distance;
                Shape_P = new Regular_Pentagon(x, y, vertex_distance);
                a.push_back(*Shape_P); // push the pentagon object to the vector
                delete[] Shape_P;
                shape_type = ' ';
                break;
            case 'H':
                // import is a hexagon
                ist >> x >> y >> vertex_distance;
                Shape_H = new Regular_Hexagon(x, y, vertex_distance);
                a.push_back(*Shape_H); // push the hexagon object to the vector
                delete[] Shape_H;
                shape_type = ' ';
                break;
            case 'C':
                // import is a circle
                ist >> x >> y >> rad;
                Shape_C = new Circle(x, y, rad);
                a.push_back(*Shape_C); // push the circle object to the vector
                delete[] Shape_C;
                shape_type = ' ';
                break;
            default:
                // Doesn't meet criteria for shape so quit
                keep_reading = false;
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
            cout << Shapes[i] << endl; // output each shape info to the screen
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
