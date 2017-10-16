// Author: Seth Barberee
// Assignment: HW 1 Problem 2
// Purpose: The programs asks questions in order to guess the user's number

#include "std_lib_facilities_4.h"

int main() {
   int guess;
   int upper_limit;
   int lower_limit;
   char answer;

   cout << "Welcome to the number guessing game!\n";
   cout << "Pick a number between 1 and 100\n";
   cout << "Is the number you are thinking of less than 50 but not eqaul to 50? (Y/N)\n";
   cin >> answer;

   if (answer == 'Y'){
        // Between 1 and 50
        lower_limit = 1;
        upper_limit = 50;
        guess = 25;
   }
   else if (answer == 'N'){
        // Between 50 and 100
        lower_limit = 50;
        upper_limit = 100;
        guess = 75;
   }
   else {
        cout << "Invalid input!\n";
   }

   for (int i = 1; i <= 6; i++){
        guess = (upper_limit + lower_limit) / 2;
        cout << "Is the number you are thinking of less than " << guess << " or equal to " << guess << "? (Y/N)\n";
        cin >> answer;

        if (answer == 'Y'){
            // Shrink range for guessing to lower_limit to last guessed number 
            upper_limit = guess;
        }
        else if (answer == 'N'){
            // Shrink range for guessing to last guessed number to upper_limit
            lower_limit = guess;
        }
        else {
            cout << "Invalid input\n";
            break;
            return 1;
        }

        // Easy enough range to go on ahead on solve
        if ((upper_limit - lower_limit) <= 2){
            // If remainder is one, then there's only two numbers left to guess
            if ((upper_limit - lower_limit) == 1){
                // Two choices so ask the user
                cout << "Is the number you are thinking of " << lower_limit <<"? (Y/N)\n";
                cin >> answer;
                if (answer == 'Y'){
                    // This is the user's number so guess it
                    guess = lower_limit;
                    break;
                }
                else{
                    // Since the other one isn't correct, this is the user's number
                    guess = upper_limit;
                    break;
                }
            }
            else {
                cout << "Is your number " << upper_limit << "? (Y/N)\n";
                cin >> answer;
                if (answer == 'Y'){
                    guess = upper_limit;
                    break;
                }
                else {
                    guess = (upper_limit + lower_limit) / 2;
                    break;
                }
            }
        }
   }
    // Output the number that the computer is guessing
    cout << "Your number is " << guess << "!\n";

}
