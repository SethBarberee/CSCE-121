#include "std_lib_facilities_4.h"
// Author: Seth Barberee
// Assignment: Homework 11 Problem 3
// Purpose: Create a map container and repeatedly do operations on it

int main(){
    map<string,int> my_map;
    string s;

    int choice;
    bool looping = true;
    while (looping){
        cout << "1) Insert a pair into the map" << endl;
        cout << "2) Output all pairs in the map" << endl;
        cout << "3) Erase a pair from the map" << endl;
        cout << "4) Find pair in map given a name" << endl;
        cout << "5) Output sum of all values in map" << endl;
        cout << "6) Quit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1: {
                    cout << "Inserting a pair..." << endl;
                    cout << "String: ";
                    cin >> s;
                    ++my_map[s];
                    break;
                }
        case 2: {
                    cout << "Printing all pairs..." << endl;
                    for(const auto& p : my_map){
                        cout << p.first << ": " << p.second << endl;
                    }
                    break;
                }
        case 3: {
                    cout << "Erasing a pair..." << endl;
                    break;
                }
        case 4: {   cout << "Checking if a name is in the map..." << endl;
                    cout << "Name: ";
                    cin >> s;
                    // Couldn't I just use find??
                    for(const auto& p : my_map){
                        if(s == p.first){
                            cout << "Found!" << endl;
                            break;
                        }
                    }
                    break;
                }
        case 5: {
                    int sum = 0;
                    cout << "Outputting the sum..." << endl;
                    for(const auto& p : my_map){
                        sum = sum + p.second;
                    }
                    cout << sum << endl;
                    break;
                }
        case 6: {
                    looping = false;
                    cout << "Exiting program..." << endl;
                    break;
                }
        default: break;
        }
        cout << endl;
    }
    return 0;
}
