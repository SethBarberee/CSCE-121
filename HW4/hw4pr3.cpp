// Author: Seth Barberee
// Assignment: Homework 3 Problem 3
// Purpose: Binary Calculator that outputs 1 or 0s depending on the equation

#include "std_lib_facilities_4.h"

struct Token {
  char kind;
  int value;
  Token(char ch) : kind(ch), value(0) {}
  Token(char ch, int val) : kind(ch), value(val) {}
};

// A Token_stream gets the next token from the input stream and holds
// most recently obtained token that has not yet been used, in data
// member buffer.
class Token_stream {
  bool full;      // indicates whether there is something in buffer
  Token buffer;   // if full then this is the token to be returned by get

public:
  // constructor
  Token_stream() : full(false), buffer(0) {}

  // lets user put something in the buffer (but only if buffer is not
  // already holding something)
  void putback(Token t) {
    if (full) error("putback into a full buffer");
    buffer = t;
    full = true;
  }

  // Returns a token from the input stream cin by checking the next
  // character.  If the next character indicates that the next token
  // will be a number, then we use the built-in ability of C++ to obtain
  // numbers (by reading from cin into a int).
  Token get() {
    if (full) { full = false; return buffer;}
    char ch;
    cin >> ch;
    switch(ch) {
    case '(': case ')': case '^': case '|': case '&': case ';':      // new token ;
      return Token(ch);
    case '0': case '1':{
      cin.putback(ch);  // put digit back into the input stream
      int val;
      cin >> val;
      return Token('#',val);
    }
    default: error("Bad token");
    }
  }
};

// global variable (not desirable, but shortcut to focus on other issues)
Token_stream ts;      // global variable

// Functions corresponding to grammar rules coming up next.

// declaration of function expression to deal with indirect recursion; 
// definition is below.
int expression(); 

// function primary tries to extract a primary from the input, i.e.,
// something of the form "( expression )" or a number.
int primary() {
  Token t = ts.get();
  switch (t.kind) {
  case '(' : {
    int d = expression();
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return d; }
  case '#' : return t.value;
  default  : error ("primary expected");
  }
}

int term() {
    int val = primary();
    Token t = ts.get();
    switch (t.kind) {
    case '&' :{
      if (val == term()){
        val = 1;
      }
      else {
        val = 0;
      }
      break;
      }
    case '^':{
      val = term() != val;
      break;
     }
    case '|' : {
      if(term() == 1 || val == 1){
        val = 1;
      }
      else
      {
        val = 0;
      }
      break;
      }
    default :
      ts.putback(t);
      return val;
  }
}

int expression() {
    int val = term();
    Token t = ts.get();
    switch (t.kind) {
    default : ts.putback(t); return val; }
}

// main is modified to have a loop so that user can repeatedly enter input.
// User enters ";" to indicate that current value of expression should be
// output.
int main()
  try {
    int val = 0;
    cout << "Enter a semicolon(;) to end the equation. Enter your equation below" << endl;
    while (true) {
      Token t = ts.get();
      if (t.kind == ';')
	    cout << val << endl;
      else
	    ts.putback(t);
      val = expression();
    }
  }
  catch(runtime_error& e) {
    cerr << e.what() << endl;
    return 1;
  }
  catch(...) {
    cerr << "exception\n";
    return 2;
  }
