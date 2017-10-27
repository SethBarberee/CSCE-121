class Shape{
    private:
    double x,y;
    double distance;
    int num_vertex;
    double area;
    double perimeter;

    public:
    double calc_perimeter(){};
    double calc_area(){};

};
class Equilateral_Triangle : public Shape{};
class Square : public Shape{};
class Circle : public Shape{
    private:
    double radius;
    virtual double calc_area(){
        area = 2 * 3.14159 * (radius)^2;
    };
};
class Right_Triangle : public Shape{};
class Rectangle : public Shape{
    private:
    double width;
    double height;
    virtual double calc_area(){
        area = width * height;
    };
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
        import_file(inputfille);
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
