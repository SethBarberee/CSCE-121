// Author: Seth Barberee
// Assignment: Homework 8 Problem 1
// Purpose: Currency Convertor
// Currency: US Dollars, Euro, English Pound, Indian Rupee, and Australian Dollar

#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//----------------------------------------------------------
// define a struct that is a window in which lines can be
// entered via a GUI

struct Lines_window : Graph_lib::Window {       // inherits from Window

  // constructor
  Lines_window(Point xy,             // top lefthand corner
	       int w,                // width
	       int h,                // height
	       const string& title); // label

private:
  // widgets:
  In_box money_in;                   // the amount of money to convert
  Out_box money_out;                 // the converted money amount
  Button quit_button;                // end program
  Menu currency_menu1;               // menu of currencies to convert from
  Menu currency_menu2;               // menu of currencies to convert to
  Button menu1_button;               // button to display menu 1
  Button menu2_button;               // button to display menu 2

  // function members

  void hide_menu1() {     
    currency_menu1.hide(); 
    menu1_button.show(); 
  }

  void hide_menu2() {
    currency_menu2.hide();
    menu2_button.show();
  }

  // actions invoked by callbacks:

  void US_Dollar_pressed1() {
    hide_menu1();        // once a color is chosen from the menu, hide the menu
  }

  void US_Dollar_pressed2() {
    hide_menu2();
  }

  void EU_Euro_pressed1() {
    hide_menu1();
  }

  void EU_Euro_pressed2() {
    hide_menu2();
  }

  void GB_Pound_pressed1() {
    hide_menu1();
  }

  void GB_Pound_pressed2() {
    hide_menu2();
  }

  void IN_Rupee_pressed1() {
    hide_menu1();
  }

  void IN_Rupee_pressed2() {
    hide_menu2();
  }

  void AU_Dollar_pressed1() {
    hide_menu1();
  }

  void AU_Dollar_pressed2() {
    hide_menu2();
  }

  void menu_pressed1() {
    // when menu button is pressed, hide the menu button and show the 
    // actual menu of colors
    menu1_button.hide();    
    currency_menu1.show();
  }

  void menu_pressed2() {
    menu2_button.hide();
    currency_menu2.show();
  }

  void quit();   // defined below

  // callback functions; declared here and defined below.

  static void cb_US_Dollar1(Address, Address);
  static void cb_US_Dollar2(Address, Address);
  static void cb_EU_Euro1(Address, Address);
  static void cb_EU_Euro2(Address, Address);
  static void cb_GB_Pound1(Address, Address);
  static void cb_GB_Pound2(Address, Address);
  static void cb_IN_Rupee1(Address, Address);
  static void cb_IN_Rupee2(Address, Address);
  static void cb_AU_Dollar1(Address, Address);
  static void cb_AU_Dollar2(Address, Address);
  static void cb_menu1(Address, Address);
  static void cb_menu2(Address, Address);
  static void cb_quit(Address, Address);
};

// ----------------------------------------------------------
// now define the parts of Lines_window that were only declaUS_Dollar
// inside the class

// constructor:

Lines_window::Lines_window(Point xy, int w, int h, const string& title) : 

  // initialization - start by calling constructor of base class 
  Window(xy,w,h,title),    

  // initialize quit button
  quit_button(
	      Point(x_max()-70,0),    // location of button
	      70, 20,                 // dimensions of button 
	      "Quit",                 // label of button
	      cb_quit),               // callback function for button
  // initialize the currency menu
  currency_menu1(
         Point(x_max()-310, 20),
         80, 20,
         Menu::vertical,
         "Currency to convert from"),
  currency_menu2(                        
	     Point(x_max()-80,30),   // location of menu
	     80, 20,                 // dimensions of menu
	     Menu::vertical,         // list menu items vertically
	     "Currency to convert to"),               // label of menu 
  menu1_button(
          Point(x_max()-310, 20),
          80, 20,
          "Currency to convert from",
          cb_menu1),
  // initialize the menu button
  menu2_button(
	      Point(x_max()-80,30),  // location of menu button
	      80, 20,                // dimensions of button 
	      "Currency to convert to", // label of button
	      cb_menu2),               // callback for button
   // initialize the currency inbox
   money_in(
          Point(x_max()-310,0),
          100,20,
          "Amount"),
  //  initialize the currency output
  money_out(
          Point(100,0),
          100, 20,
          "Amount Converted")

  // body of constructor follows
{
  // attach buttons and boxes to window
  attach(quit_button);
  attach(money_in);
  attach(money_out);

  currency_menu1.attach(new Button(Point(0,0),0,0,"US_Dollar",cb_US_Dollar1)); 
  currency_menu1.attach(new Button(Point(0,0),0,0,"EU_Euro",cb_EU_Euro1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"GB_Pound",cb_GB_Pound1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"IN_Rupee",cb_IN_Rupee1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"AU_Dollar",cb_AU_Dollar1));
  attach(currency_menu1);
  currency_menu1.hide(); 


  // attach currency to window
  currency_menu2.attach(new Button(Point(0,0),0,0,"US_Dollar",cb_US_Dollar2)); 
  currency_menu2.attach(new Button(Point(0,0),0,0,"EU_Euro",cb_EU_Euro2));
  currency_menu2.attach(new Button(Point(0,0),0,0,"GB_Pound",cb_GB_Pound2));
  currency_menu2.attach(new Button(Point(0,0),0,0,"IN_Rupee",cb_IN_Rupee2));
  currency_menu2.attach(new Button(Point(0,0),0,0,"AU_Dollar",cb_AU_Dollar2));
  attach(currency_menu2);
  currency_menu2.hide(); 

  // attach menu button
  attach(menu1_button);
  attach(menu2_button);

}

// ---------------------------- 
// callback function for quit button - boilerplate: 
// When the button is pressed, the system invokes the
// specified callback function.  First argument is address of the
// button (which we won't use, so we don't bother to name it).  Second
// argument, named pw, is address of the window containing the pressed
// button, i.e., address of our Lines_window object.  reference_to
// converts the address pw into a reference to a Lines_window object,
// so we can call the quit() function.  Objective is to call function
// quit() which does the real work specific to this button.

void Lines_window::cb_quit(Address, Address pw) {
  reference_to<Lines_window>(pw).quit();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::quit() {
  hide();                   // FLTK idiom for delete window
}

void Lines_window::cb_US_Dollar1(Address, Address pw) {
  reference_to<Lines_window>(pw).US_Dollar_pressed1();  
  // US_Dollar_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_US_Dollar2(Address, Address pw) {
  reference_to<Lines_window>(pw).US_Dollar_pressed2();  
  // US_Dollar_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_EU_Euro1(Address, Address pw) {
  reference_to<Lines_window>(pw).EU_Euro_pressed1();  
  // EU_Euro_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_EU_Euro2(Address, Address pw) {
  reference_to<Lines_window>(pw).EU_Euro_pressed2();  
  // EU_Euro_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_GB_Pound1(Address, Address pw) {
  reference_to<Lines_window>(pw).GB_Pound_pressed1();  
  // GB_Pound_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_GB_Pound2(Address, Address pw) {
  reference_to<Lines_window>(pw).GB_Pound_pressed2();  
  // GB_Pound_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_IN_Rupee1(Address, Address pw) {
  reference_to<Lines_window>(pw).IN_Rupee_pressed1();  
  // IN_Rupee_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_IN_Rupee2(Address, Address pw) {
  reference_to<Lines_window>(pw).IN_Rupee_pressed2();  
  // IN_Rupee_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_AU_Dollar1(Address, Address pw) {
  reference_to<Lines_window>(pw).AU_Dollar_pressed1();  
  // AU_Dollar_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_AU_Dollar2(Address, Address pw) {
  reference_to<Lines_window>(pw).AU_Dollar_pressed2();  
  // AU_Dollar_pressed defined in Lines_window class as part of declaration
}

void Lines_window::cb_menu1(Address, Address pw)
{  
    reference_to<Lines_window>(pw).menu_pressed1();
    // menu_pressed defined in Lines_window class as part of declaration
} 

void Lines_window::cb_menu2(Address, Address pw)
{  
    reference_to<Lines_window>(pw).menu_pressed2();
    // menu_pressed defined in Lines_window class as part of declaration
}

// ---------------------------------------------------
// main - just creates window and invokes gui_main

int main() 
  try {
    // construct the GUI window
    Lines_window win(Point(100,100),600,400,"Currency Converter");
    return gui_main();  // inherited from Window; calls FLTK's run
  }
  catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch(...) {
    cerr << "some exception\n";
    return 2;
  }
