#include "std_lib_facilities_4.h"

template<class Iter1, class Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    if(f1 == e1){
        return f2;
    }
    else{
        // TODO for loop to copy
    }
}

template<class Iter1, class T>
void add_each(Iter1 f1, Iter1 e1, T add){
    while (f1 != e1){
        *f1 = *f1 + add;
        ++f1;
    }
}
template<class Iter1>
void print(Iter1 f1, Iter1 e1){
    while(f1 != e1){
        cout << *f1 << " ";
        ++f1;
    }
    cout << endl;
}


int main(){
    int array_test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vector_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // copy functions
    int array_me[] = {0,0,0,0,0,0,0,0,0,0};
    copy(array_test, array_test+sizeof(array_test)/sizeof(*array_test), array_me);
    vector<int> vector_me(10);
    copy(vector_test.begin(), vector_test.end(), vector_me.begin());
    list<int> list_me(10);
    copy(list_test.begin(), list_test.end(), list_me.begin());

    // add_each functions
    cout << "2 added to each element in 1st array" << endl;
    add_each(array_test, array_test+sizeof(array_test)/sizeof(*array_test), 2);
    print(array_test, array_test+sizeof(array_test)/sizeof(*array_test));
    cout << "3 added to each element in 1st vector" << endl;
    add_each(vector_test.begin(), vector_test.end(), 3);
    print(vector_test.begin(), vector_test.end());
    cout << "5 added to each element in 1st list" << endl;
    add_each(list_test.begin(), list_test.end(), 5);
    print(list_test.begin(), list_test.end());

    // my_copy functions
    my_copy(array_me, array_me+sizeof(array_me)/sizeof(*array_me), vector_me.begin());
    cout << "2nd array copied into 2nd vector" << endl;
    print(vector_me.begin(), vector_me.end());
    my_copy(list_me.begin(), list_me.end(), array_me);
    cout << "2nd list copied into 2nd array" << endl;
    print(array_me, array_me+sizeof(array_me)/sizeof(*array_me));

    // Find functions
    cout << "In first vector, 3 is located at:" << endl;
    cout << *find(vector_test.begin(), vector_test.end(), 3) << endl;
    print(vector_test.begin(), vector_test.end());
    cout << "In first list, 27 is located at:" << endl;
    cout << *find(list_test.begin(), list_test.end(), 27) << endl;
    print(list_test.begin(), list_test.end());

    return 0;
}
