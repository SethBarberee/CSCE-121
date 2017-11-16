// Name: Seth Barberee
// Assignment: Homework 10 Problem 1
// Purpose: Make a double linked list

#include "std_lib_facilities_4.h"

class List {
    private:
    int val;
    List* first;
    List* last;

    public:
    int get_val(){return val;}
    List(List* f = 0, List* l = 0): first(f), last(l){};
    List* insert(List* p, List* n){
        n->first = p->first;
        p->last = n; // point to the newest last element
        n->last = nullptr; // it's the last element
        return n;
    };
    List* insert_pos(List* p, List* n, int r){
        // TODO need to figure out size of list
        // since code can be different depending on where
        // we are inserting
        //
        // Assume it's in the middle
        n->first = p->first;
        n->last = p->last;
        return n;
    };
    List* remove_pos(List* p, int n){};
};

ostream& operator<<(ostream& os, List& a){
    // TODO add stuff to output
    
    return os;
}

int main(){
    List* test_list;
    cout << *test_list << endl;;
}
