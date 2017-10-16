// From Stroustrup, PPP (And modified by Seth Barberee to work with negatives)
// No negatives numbers worked (would error with primary expected)

#include "std_lib_facilities_4.h"

// Possible Tokens are (, ), +, -, *, /, ;, and floating point numbers.
// Data member kind stores the token itself for all but the numbers.
// Numbers are represented with kind '#' and the value stored in
// data member val (other tokens don't use val).
// ; means output the current value.
struct Token {
  char kind;
  double value;
  Token(char ch) : kind(ch), value(0) {}
  Token(char ch, double val) : kind(ch), value(val) {}
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
  // numbers (by reading from cin into a double).
  Token get() {
    if (full) { full = false; return buffer;}
    char ch;
    cin >> ch;
    switch(ch) {
    case '(': case ')': case '+': case '-':
    case '*': case '/': case ';':      // new token ;
      return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {
      cin.putback(ch);  // put digit back into the input stream
      double val;
      cin >> val;       // let C++ do the work of reading a floating-point num
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
double expression(); 

// function primary tries to extract a primary from the input, i.e.,
// something of the form "( expression )" or a number.
double primary() {
  Token t = ts.get();
  switch (t.kind) {
  case '(' : {
    double d = expression();
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return d; }
  case '#' : return t.value;
  case '-' : return - primary();
  case '+' : return primary();
  default  : error ("primary expected");
  }
}

// Function term tries to extract a term from the input, i.e.,
// something that is a sequence of primaries separated by *'s or /'s.
double term() {
    double val = primary();
    Token t = ts.get();
    switch (t.kind) {
    case '*' :
      val *= term();
      break;
    case '/' : {
      double d = primary();
      if (d==0) error("divide by zero");
      val /= term();
      break; }
    default :
      ts.putback(t);
      return val;
  }
}

// Function expression tries to extract an expression from the input, i.e.,
// something that is a sequence of terms separated by +'s or -'s.
// CORRECTED to put token back in default case.
double expression() {
    double val = term();
    Token t = ts.get();
    switch (t.kind) {
    case '+' : val += expression(); break;
    case '-' : val -= expression(); break;
    default : ts.putback(t); return val; }
}

// main is modified to have a loop so that user can repeatedly enter input.
// User enters ";" to indicate that current value of expression should be
// output.
int main()
  try {
    double val = 0;
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
