#include "std_lib_facilities_4.h"
// Author: Seth Barberee
// Assignment: Homework 11 Problem 2
// Purpose: Input a file and use accumulate in three different ways

struct Record {
    int units_sold;
    double unit_price;
};

double total(double v, const Record& r){
    return v + r.unit_price * r.units_sold;
}

int main(){
    vector<Record> Records;

    // TODO add file import

    // Function as an argument to accumulate
    cout << "Accumulate using a function..." << endl; 
    cout << accumulate(Records.begin(), Records.end(), 0.0, total) << endl;
    // Function object as an argument to accumulate
    cout << "Accumulate using a function object..." << endl;
    //accumulate(Records.begin(), Records.end(), );
    // Lamda function as an argument to accumulate
    cout << "Accumulate using a lamda function..." << endl;
    //accumulate(Records.begin(), Records.end(),);
}
