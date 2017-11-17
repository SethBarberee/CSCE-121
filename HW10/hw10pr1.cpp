// Author: Seth Barberee
// Assignment: Homework 10 Problem 1
// Purpose: Make a double linked list

struct Node {
    int val;
    Node* prev;
    Node* next;
    int get_val(){return val;}
    Node(int d, Node* p = 0; Node* n = 0;) : val(d), prev(p), next(n){}
};
ostream& operator<<(ostream& os, Node& a){
    os << a.get_val();
    return os;
}

class List {
    private:
    int size;
    Node* nodes;
    Node* first;
    Node* last;
    
    public:
    List(){size = 0; nodes = nullptr; first = nullptr; last = nullptr;}
    // TODO Copy Constructor
    // TODO Copy Assignment
    // TODO Destructor
    int get_size(){return size;}
    Node* get_nodes{ return nodes;}
    Node* get_last{ return last;}
    Node* insert(Node* a){
        a->next = nullptr;
        a->prev = get_last();
        get_last()->next = a;
        last = a;
        size++; // Increase size on successful insert
    }
    Node* insert_pos(int n){
        if(n <= size){
            for(int i = 0; i < n-1; i++){
                // TODO loop through nodes to needed node
            }
            size++; // Increase size on successful insert
        }
        else{
            return nullptr;
        }
    }
    Node* remove_pos(int n){
        if(n <= size){
            for(int i = 0; i < n-1; i++){
               // TODO loop through nodes to needed node 
            }
            size--; // Decrease size on successful removal
        }
        else{
            return nullptr;
        }
    }
};
ostream& operator<<(ostream& os, List& a){
    // TODO loop through Nodes and cout them
    // os << Node
    os << a.get_size();
    return os;
}
int main(){}
