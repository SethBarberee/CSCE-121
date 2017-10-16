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
  Circle door_knob(Point(10,10), 10); // centered at () with radius of 10
  win1.attach(frame);
  win1.attach(door_knob);
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
