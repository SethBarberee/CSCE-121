#include "std_lib_facilities_4.h"
// Author: Seth Barberee
// Assignment: Homework 11 Problem 2
// Purpose: Input a file and use accumulate in three different ways

struct Record {
    int units_sold;
    double unit_price;
    Record(int units_sold, double unit_price);
};

// TODO work on this!!
template<class T> struct total_func{
    T total;
    Record a;
    total_func(T& v, const Record& r) : total(v), a(r) {}
    bool operator()(double v, const Record& r) const {
        return v + r.unit_price * r.units_sold;
    }
};

Record :: Record(int unit, double price) : units_sold(unit), unit_price(price){}

double total(double v, const Record& r){
    return v + r.unit_price * r.units_sold;
}

int main(){
    vector<Record> Records;
    int units;
    double price;

    // TODO add file import
    ifstream ist {"data.txt"};

    if(!ist) error("Can't open input file!");
    while(!ist.eof()){
        ist >> units >> price;
        Record newRecord = Record(units, price);
        Records.push_back(newRecord);
    }

    // Function as an argument to accumulate
    cout << "Accumulate using a function..." << endl; 
    cout << accumulate(Records.begin(), Records.end(), 0.0, total) << endl;
    // Function object as an argument to accumulate
    // I.E. multiplies<double>()
    cout << "Accumulate using a function object..." << endl;
    //accumulate(Records.begin(), Records.end(), total_func());
    // Lamda function as an argument to accumulate
    cout << "Accumulate using a lamda function..." << endl;
    cout << accumulate(Records.begin(), Records.end(),0.0,[](double v, const Record& r){return v + r.unit_price*r.units_sold;}) << endl;
}
