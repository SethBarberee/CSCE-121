// Author: Seth Barberee
// Assignment: HW1 Problem 3
// Purpose: Given the story from the book, find the squares to give the man at least 1000, 1000000, and 1000000000 grains of rice, respectively

#include "std_lib_facilities_4.h"

int main() {
    int square; // Which square we are currently on
    int current_rice = 1;
    int previous_rice = 0;
    // Keep track of when we get to each of the checkpoints for the first time
    bool checkpoint_1000 = false;
    bool checkpoint_1000000 = false;
    bool checkpoint_1000000000 = false;

    for (square = 2; square <= 64; square ++){
        previous_rice = current_rice + previous_rice;
        current_rice = previous_rice * 2;

        if (current_rice >= 1000 && checkpoint_1000 == false){
            // When we get at least 1000 grains and it's the first time
            checkpoint_1000 = true;
            cout << "Square: " << square << "  Rice: " << current_rice << "\n";
        }

        if(current_rice >= 1000000 && checkpoint_1000000 == false){
            // When we get at least 1000000 grains and it's the first time
            checkpoint_1000000 = true;
            cout << "Sqaure: " << square << " Rice: " << current_rice << "\n";
        }
        if(current_rice >= 1000000000 && checkpoint_1000000000 == false){
            // When we get at least 1000000000 grains and it's the first time
            checkpoint_1000000000 = true;
            cout << "Square: " << square << " Rice: " << current_rice << "\n";
        }
    }
}
