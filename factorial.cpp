#include "std_lib_facilities_4.h"
int number;
int input;
int factorial = 1;
int main(){
    cout << "Factorial of number: ";
    cin >> input;
    number = input;
    while (number > 1){
        factorial = factorial * number;
        number = number - 1;
    }
    cout << "The factorial of " << input << " is " << factorial << endl;
}
