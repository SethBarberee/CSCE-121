// Author: Seth Barberee
// Assignment: Homework 10 Problem 1
// Purpose: Make a double linked list

struct Node {
    int val;
    Node* first;
    Node* prev;
    Node* next;
    Node* last;
    int get_val(){return val;}
    Node(int d, Node* f = 0; Node* p = 0; Node* n = 0; Node* l = 0;) : val(d), first(f), prev(p), next(n), last(l) {}
};
ostream& operator<<(ostream& os, Node& a){
    os << a.get_val();
    return os;
}

class List {
    private:
    int size;
    Node* nodes;
    
    public:
    List(){size = 0; nodes = nullptr;}
    // TODO Copy Constructor
    // TODO Copy Assignment
    // TODO Destructor
    Node* get_nodes{ return nodes;}
    Node* insert(){}
    Node* insert_pos(int n){
        if(n <= size){
            for(int i = 0; i < n-1; i++){
                // TODO loop through nodes to needed node
            }
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
        }
        else{
            return nullptr;
        }
    }
};
ostream& operator<<(ostream& os, List& a){
    // TODO loop through Nodes and cout them
    // os << Node
    return os;
}
int main(){}
