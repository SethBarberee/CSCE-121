/* Author: Seth Barberee
 * Assignment: Homework 6 Problem 3
 * Purpose: Tile 8 hexagons across the screen
 * */

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

// Derive from 
// Specify size and location
class Regular_hexagon : public Shape {
    public:
    Regular_hexagon(Point p1, int side){
        add(p1); 
        add(Point(p1.x - side, p1.y + side));
        add(Point(p1.x, p1.y + (2 * side)));
        add(Point(p1.x + side, p1.y + (2 * side)));
        add(Point(p1.x + (2 * side), p1.y + side));
        add(Point(p1.x + side, p1.y));
        add(p1);
    }
};
int main()
try{
  int side_length = 30;
  int start_location = 150;
  // 600 x 400 window named Hexagon Tiled
  Simple_window win1(Point(100,200),600,400,"Hexagon Tiled");
  Regular_hexagon hex1(Point(start_location,start_location),side_length); // Starting hexagon
  Regular_hexagon hex2(Point(start_location + 3*side_length, start_location), side_length); // Hexagon to the right of the start

  Regular_hexagon hex3(Point(start_location, start_location + 2 * side_length), side_length); // Hexagon above the start
  Regular_hexagon hex4(Point(start_location, start_location - 2 * side_length), side_length); // Hexagon below the start
  Regular_hexagon hex5(Point(start_location - 3*side_length, start_location), side_length); // Hexagon to the left of the start
  Regular_hexagon hex6(Point(start_location + 6*side_length, start_location), side_length); // 2nd Hexagon to the right of the start
  Regular_hexagon hex7(Point(start_location + 3*side_length, start_location - 2 * side_length), side_length); // Hexagon to the right down
  Regular_hexagon hex8(Point(start_location + 3*side_length, start_location + 2 * side_length), side_length); // Hexagon to the right up
  win1.attach(hex1);
  win1.attach(hex2);
  win1.attach(hex3);
  win1.attach(hex4);
  win1.attach(hex5);
  win1.attach(hex6);
  win1.attach(hex7);
  win1.attach(hex8);
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
