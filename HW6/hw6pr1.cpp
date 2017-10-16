/* Author: Seth Barberee
 * Assignment: Homework 6 Problem 1
 * Purpose: Draw a house
 * */

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try {
  Simple_window win1(Point(100,200),600,400,"Simple House");
  Rectangle frame(Point(200, 200), 100, 100); // 100x100 rectangle at (200,200)
  Rectangle window1(Point(210, 260), 25, 25); // 25x25 rectangle window
  Rectangle window2(Point(210, 210), 25, 25); // Same as above
  Rectangle door(Point(265, 270), 20, 30); // 20x30 rectangle door
  Rectangle chimney(Point(280, 125), 20, 75); // 20x75 rectangle chimney
  Line roof1(Point(200,200), Point(250, 150)); // One half of the roof
  Line roof2(Point(250,150), Point(300, 200)); // Other half of the roof
  Circle door_knob(Point(280,285), 3); // centered at (280,285) with radius of 3
  // Attach them all to the screen
  win1.attach(frame);
  win1.attach(door);
  win1.attach(door_knob);
  win1.attach(roof1);
  win1.attach(roof2);
  win1.attach(chimney);
  win1.attach(window1);
  win1.attach(window2);
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
