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

int currency_1 = 0; // row in currency table
int currency_2 = 0; // column in currency table
vector<vector<double>> currency_table = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
};

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
  Button calc_button;                // button to convert the currency

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
    currency_1 = 0;
  }

  void US_Dollar_pressed2() {
    hide_menu2();
    currency_2 = 0;
  }

  void EU_Euro_pressed1() {
    hide_menu1();
    currency_1 = 1;
  }

  void EU_Euro_pressed2() {
    hide_menu2();
    currency_2 = 1;
  }

  void GB_Pound_pressed1() {
    hide_menu1();
    currency_1 = 2;
  }

  void GB_Pound_pressed2() {
    hide_menu2();
    currency_2 = 2;
  }

  void IN_Rupee_pressed1() {
    hide_menu1();
    currency_1 = 3;
  }

  void IN_Rupee_pressed2() {
    hide_menu2();
    currency_2 = 3;
  }

  void AU_Dollar_pressed1() {
    hide_menu1();
    currency_1 = 4;
  }

  void AU_Dollar_pressed2() {
    hide_menu2();
    currency_2 = 4;
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

  void calculate(); // defined below

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
  static void cb_calculate(Address, Address);
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
         Point(100, 20),
         80, 20,
         Menu::vertical,
         "Currency to convert from"),
  currency_menu2(                        
	     Point(x_max()-310,20),   // location of menu
	     80, 20,                 // dimensions of menu
	     Menu::vertical,         // list menu items vertically
	     "Currency to convert to"),               // label of menu 
  menu1_button(
          Point(100, 20),
          80, 20,
          "Currency to convert from",
          cb_menu1),
  // initialize the menu button
  menu2_button(
	      Point(x_max()-310,20),  // location of menu button
	      80, 20,                // dimensions of button 
	      "Currency to convert to", // label of button
	      cb_menu2),               // callback for button
  calc_button(
          Point(x_max()-210, 0),
          50, 20,
          "Calculate",
          cb_calculate),
  // initialize the currency inbox
  money_out(
          Point(x_max()-310,0),
          100,20,
          "Amount Converted"),
  //  initialize the currency output
  money_in(
          Point(100,0),
          100, 20,
          "Amount")

  // body of constructor follows
{
  // attach buttons and boxes to window
  attach(quit_button);
  attach(money_in);
  attach(money_out);
  money_out.put("0");

  currency_menu1.attach(new Button(Point(0,0),0,0,"US_Dollar",cb_US_Dollar1)); 
  currency_menu1.attach(new Button(Point(0,0),0,0,"EU_Euro",cb_EU_Euro1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"GB_Pound",cb_GB_Pound1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"IN_Rupee",cb_IN_Rupee1));
  currency_menu1.attach(new Button(Point(0,0),0,0,"AU_Dollar",cb_AU_Dollar1));
  attach(currency_menu1);
  currency_menu1.hide(); 


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
  attach(calc_button);

}

void Lines_window::cb_quit(Address, Address pw) {
  reference_to<Lines_window>(pw).quit();   // quit is defined next
}

void Lines_window::quit() {
  hide();                   // FLTK idiom for delete window
}

void Lines_window::cb_calculate(Address, Address pw) {
  reference_to<Lines_window>(pw).calculate();
}

void Lines_window::calculate(){
    double money_to_convert = money_in.get_int();
    double rate = currency_table[currency_1][currency_2];
    double money_converted = money_to_convert * rate;
    stringstream ss;
    ss << ' ' << money_converted << ' ';
    money_out.put(ss.str());

    redraw();
}

void Lines_window::cb_US_Dollar1(Address, Address pw) {
  reference_to<Lines_window>(pw).US_Dollar_pressed1();  
}

void Lines_window::cb_US_Dollar2(Address, Address pw) {
  reference_to<Lines_window>(pw).US_Dollar_pressed2();  
}

void Lines_window::cb_EU_Euro1(Address, Address pw) {
  reference_to<Lines_window>(pw).EU_Euro_pressed1();  
}

void Lines_window::cb_EU_Euro2(Address, Address pw) {
  reference_to<Lines_window>(pw).EU_Euro_pressed2();  
}

void Lines_window::cb_GB_Pound1(Address, Address pw) {
  reference_to<Lines_window>(pw).GB_Pound_pressed1();  
}

void Lines_window::cb_GB_Pound2(Address, Address pw) {
  reference_to<Lines_window>(pw).GB_Pound_pressed2();  
}

void Lines_window::cb_IN_Rupee1(Address, Address pw) {
  reference_to<Lines_window>(pw).IN_Rupee_pressed1();  
}

void Lines_window::cb_IN_Rupee2(Address, Address pw) {
  reference_to<Lines_window>(pw).IN_Rupee_pressed2();  
}

void Lines_window::cb_AU_Dollar1(Address, Address pw) {
  reference_to<Lines_window>(pw).AU_Dollar_pressed1();  
}

void Lines_window::cb_AU_Dollar2(Address, Address pw) {
  reference_to<Lines_window>(pw).AU_Dollar_pressed2();  
}

void Lines_window::cb_menu1(Address, Address pw)
{  
  reference_to<Lines_window>(pw).menu_pressed1();
} 

void Lines_window::cb_menu2(Address, Address pw)
{  
  reference_to<Lines_window>(pw).menu_pressed2();
}

void import_file(string input, vector< vector<double>>& table){
    vector<double> currency_row;
    double rate;
    ifstream ist (input);
    if (!ist) error("Can't open input file: ", input);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
           ist >> rate;
           currency_table[i][j] = rate;
        }
    }
}

// ---------------------------------------------------
// main - just creates window and invokes gui_main

int main()
  try {
    string inputfile;
    cout << "What is the datafile?" << endl;
    cout << "Datafile: ";
    cin >> inputfile;
    import_file(inputfile, currency_table);

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
