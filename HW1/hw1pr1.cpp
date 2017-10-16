// Author: Seth Barberee
// Assignment: HW1 Problem 1
// Purpose: Simple calculator that can do basic math given an operator and two numbers

#include "std_lib_facilities_4.h"

int main() {
    string operation;
    double first_number = 0;
    double second_number = 0;

    while (true){
        cout << "\n";
        cout << "Input the operand (*,+, -, /) followed by two numbers\n";
        cout << "Input a Q followed by two numbers and press Enter to kill program\n";
        cin >> operation >> first_number >> second_number;

        if (operation == "*"){
            // Multiply the two numbers
            cout << "The result is " << (first_number*second_number);
            cout << "\n";
        }
        else if (operation == "/"){
            // Divide the two numbers
            cout << "The result is " << (first_number/second_number);
            cout << "\n";
        }
        else if (operation ==  "+"){
            // Add the two numbers
            cout << "The result is " << (first_number+second_number);
            cout << "\n";
        }
        else if (operation ==  "-"){
            // Divide the two numbers
            cout << "The result is " << (first_number-second_number);
            cout << "\n";
        }
        else if (operation == "Q"){
            // Quit the program
            cout << "Killing program...\n";
            return 0;
        }
        else {
            // Anything else that isn't an operator or Q
            cout << "Invalid operator!\n";
            cout << "Please input a valid operator (+, -, *, /) to continue or type Q to kill program\n";
            cout << "\n";
        }
    }
}
