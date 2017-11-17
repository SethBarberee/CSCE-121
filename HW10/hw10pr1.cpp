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
    Node* current_node;
    Node* first;
    Node* last;
    
    public:
    List(){size = 0; current_node = nullptr; first = nullptr; last = nullptr;};
    // TODO Copy Constructor
    // TODO Copy Assignment
    // TODO Destructor
    int get_size() const {return size;}
    Node* get_current_node(){ return current_node;}
    Node* get_last(){ return last;}
    Node* insert(Node* a){
        if(size > 0){ // check if it's not empty
            a->next = nullptr;
            a->prev = get_last();
            this->get_last()->next = a;
            last = a;
            current_node = a;
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
            current_node = a;
            return a;
        }
    }
    Node* insert_pos(Node*a, int n){
        if(n <= size){
            for(int i = 1; i < n; i++){
                this->current_node = this->current_node->next;
            }
            this->current_node->next->prev = a;
            this->current_node->next = a;
            size++; // Increase size on successful insert
            current_node = a;
            return a;
        }
        else{
            return nullptr;
        }
    }
    Node* remove_pos(int n){
        if(n <= size){
            for(int i = 1; i < n; i++){
                this->current_node = this->current_node->next; 
            }
            this->current_node->prev->next = this->current_node->next;
            this->current_node->next->prev = this->current_node->prev;
            size--; // Decrease size on successful removal
            return this->current_node;
        }
        else{
            return nullptr;
        }
    }
};
ostream& operator<<(ostream& os, const List& a){
    // TODO loop through Nodes and cout them
    // os << Node
    return os << a.get_size();
}
int main(){
    List* demo = new List();
}
