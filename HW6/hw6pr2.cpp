/* Author: Seth Barberee
 * Assignment: Homework 6 Problem 2
 * Purpose: Draw a n-gon closed inside the n+1-gon
 * */

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
 
// Specify size, location, and number of sides (starts from 3 to 8)
class Regular_polygon :  public Shape {
    private:
    double side_number;
    double side_length;
    double calculate_side_length(double side_number, double radius);
    public:
    Regular_polygon(double num, double radius, Point cen);
    double deg2rad(double number);
};

// Calculate the side length based on the Law of Cosines
double Regular_polygon :: calculate_side_length(double n, double r){
    double side_length;
    side_length = r * sqrt(2 - 2 * cos((360/n)));
    return side_length;
}

// Convert degrees to radians for the trig calculations
double Regular_polygon :: deg2rad(double number){
    double rad = (number * 3.141596)/180;
    return rad;
} 

// Regular_polygon constructor
Regular_polygon :: Regular_polygon(double num, double radius, Point cen) : side_number(num), side_length(calculate_side_length(num, radius)){
    double angle = 360 / num; // Interior angles
    double current_angle = 0;
    for (double i = 0; i <= 361; i = i + angle){ // Add the points in a circle from 0 to 360 degrees (361 because septagon can be troublesome since the interior angles aren't perfect integers
       if (i != 360)
        current_angle = deg2rad(i);
       else
        current_angle = 0;
       add(Point(cen.x + (radius * cos(current_angle)), cen.y - (-radius * sin(current_angle)))); // Add the point in polar coordinates 
    }
}

int main()
try {
  double r3,r4,r5,r6,r7;
  double r = 200;
  int centerx = 300;
  int centery = 300;
  Point center = Point(centerx,centery);
  Simple_window win1(Point(0,0),1000,1000,"Enclosed Polygons");
  r3 = (r * 3)/8;
  Regular_polygon triangle(3,r3, center);
  r4 = (r * 4)/8;
  Regular_polygon quad(4, r4, center);
  r5 = (r * 5)/8;
  Regular_polygon pentagon(5, r5, center);
  r6 = (r * 6)/8;
  Regular_polygon hexagon(6, r6, center);
  r7 = (r * 7)/8;
  Regular_polygon septagon(7, r7, center);
  Regular_polygon octagon(8, r, center);
  win1.attach(triangle);
  win1.attach(quad);
  win1.attach(pentagon);
  win1.attach(hexagon);
  win1.attach(septagon);
  win1.attach(octagon);
  win1.wait_for_button();
  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
