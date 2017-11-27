// Author: Seth Barberee
// Assignment: Homework 10 Problem 1
// Purpose: Make a double linked list

#include "std_lib_facilities_4.h"

struct Node {
    int val;
    Node* prev;
    Node* next;
    int get_val() const {return val;}
    Node(int d, Node* p = 0, Node* n = 0) : val(d), prev(p), next(n){};
};
ostream& operator<<(ostream& os, const Node& a){
    return os << a.get_val();
}

class List {
    private:
    int size;
    Node* first;
    Node* last;
    
    public:
    List(){size = 0; first = nullptr; last = nullptr;};
    // Copy Constructor
    List(List *a){
        a->first = this->first;
        a->last = this->last;
        a->size = this->size;
    }
    // Copy Assignment
    List& operator=(List *a){
        this->first = a->first;
        this->last = a->last;
        this->size = a->size;
    }
    // Destructor
    ~List(){
        cout << "Deleting list..." << endl;
        Node* current = this->get_first();
        for(int i = 0; i < this->get_size(); i++){
            cout << "Deleting node..." << endl;
            delete[] current->prev;
            cout << "Deleted node previous pointer..." << endl;
            current = current->next;
            if (current->next == nullptr){
                cout << "Deleted all nodes..." << endl;  
                break;
            }
            delete[] current->prev->next;
            cout << "Deleted node next pointer" << endl;
            cout << "Finished deleting node.." << endl;
        }
        delete[] current;
        cout << "Deleting first pointer..." << endl;
        delete[] first;
        cout << "Deleting last pointer..." << endl;
        delete[] last;
        cout << "Done!" << endl;
    }
    int get_size() {return size;}
    Node* get_first(){return first; }
    Node* get_last(){ return last;}
    // Insert at end of List
    Node* insert(Node* a){
        if(size > 0){ // check if it's not empty
            a->next = nullptr;
            a->prev = get_last();
            this->get_last()->next = a;
            last = a;
            size++; // Increase size on successful insert
            return a;
        }
        else{
            // List was empty but now, we're adding it's first node
            a->next = nullptr;
            a->prev = nullptr;
            first = a;
            last = a;
            size++; // Increase size on successful insert
            return a;
        }
    }
    // Insert before given position
    Node* insert_pos(Node* a, int n){
        if(n <= size){
            Node* current = this->get_first();
            for(int i = 1; i < n; i++){
                current = current->next;
            }
            current->prev->next = a;
            a->next = current;
            a->prev = current->prev;
            size++; // Increase size on successful insert
            return a;
        }
        else{
            return nullptr;
        }
    }
    // Remove node at given position
    Node* remove_pos(int n){
        if(n <= size){
            Node* current = this->get_first();
            for(int i = 1; i < n; i++){
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            size--; // Decrease size on successful removal
            return current;
        }
        else{
            return nullptr;
        }
    }
};
ostream& operator<<(ostream& os, List* a){
    Node* current = a->get_first();
    for(int i = 1; i <= a->get_size(); i++){
        os << "Position " << i << ": " << *current << endl;
        current = current->next;
    }
    return os;
}
int main(){
    List* demo = new List();
    cout << "Blank list created" << endl;
    demo->insert(new Node(10));
    demo->insert(new Node(12));
    cout << "Added two nodes" << endl;
    cout << "Insertion of 2 at position 2" << endl;
    demo->insert_pos(new Node(2),2);
    cout << demo << endl;
    cout << "Removal of 2 at position 2" << endl;
    demo->remove_pos(2);
    cout << demo << endl;
    List* demo2 = demo;
    cout << "Copy constructor of demo to demo2" << endl;
    cout << demo2 << endl;
    List* demo3 = new List();
    demo3->insert(new Node(10));
    cout << "demo3 created with one element" << endl;
    cout << demo3 << endl;
    cout << "Copy assignment of demo to demo3" << endl;
    demo3 = demo;
    cout << demo3 << endl;
    cout << "Explicit call of destructor on demo3";
    demo3->~List(); // explicit call to destructor
}
