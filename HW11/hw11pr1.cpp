#include "std_lib_facilities_4.h"

template<class Iter1, class Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    if(f1 == e1){
        return *f2;
    }
    else{
        // TODO for loop to copy
    }
}

template<class Iter1, class T>
void add_each(Iter1 f1, Iter1 e1, T add){
    while (f1 != e1){
        f1 = f1 + add;
        ++f1;
    }
}

int main(){
    int array_test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vector_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int array_me[] = copy(array_test.begin(), array_test.end(), array_me.begin());
    vector<int> vector_me = copy(vector_test.begin(), vector_test.end(), vector_me.begin());
    list<int> list_me =  copy(list_test.begin(), list_test.begin(), list_me.begin());

    add_each(array_test.begin(), array_test.end(), 2);
    add_each(vector_test.begin(), vector_test.end(), 3);
    add_each(list_test.begin(), list_test.end(), 5);

    my_copy(array_me.begin(), array_me.end(), vector_me.begin());
    my_copy(list_me.begin(), list_me.end(), array_me.begin());

    find(vector_test.begin(), vector_test.end(), 3);
    find(list_test.begin(), list_test.end(), 27);

    return 0;
}
