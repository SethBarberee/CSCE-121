// Author: Seth Barberee
// Assignment: HW 1 Problem 4
// Purpose: The user inputs a number and the program finds all max numbers from 2 to that number

#include "std_lib_facilities_4.h"

int main(){
    int max; // Max number to find primes
    vector<int> primes; // vector of all the primes
    vector<int> prime_binary; // vector with 1s and 0s of whether the numbers in primes vector are prime or not
    vector<int> prime_multiple; // vector with all the multiples of the current number
    cout << "What is the max number to where we want to find prime numbers? (must be greater than or equal to 2)\n";
    cin >> max;

    if (max == 1){
        cout << "Number must be greater than or equal to 2\n";
        return 1;
    }
    else if (max == 2){
        cout << "2 is the only prime number!\n";
        return 0;
    }
    
    // Make a vector of value from 2 to max
    for (int i = 2; i <= max; ++i){
        primes.push_back(i);
    }
    
    for (int i = 0; i <= (max-2); ++i){
        prime_binary.push_back(1);
    }
    for (int i = 0; i < primes.size(); ++i){
        for (int j = primes[i] * primes[i]; j <= max; j = j + primes[i]){
            prime_multiple.push_back(j);
        }
    }

    for (int i = 0; i < primes.size(); ++i){
        for (int j = 0; j < prime_multiple.size(); ++j){
            if (primes[i] == prime_multiple[j]){
                prime_binary[i] = 0;
            }
        }
    }

    // Output number of prime numbers and what numbers they are
    cout << "Prime numbers between 2 and " << max << " are:\n";
    for (int i = 0; i < primes.size(); ++i){
        if (prime_binary[i] == 1){
            cout << primes[i] << "\n"; 
        }
    }
}
