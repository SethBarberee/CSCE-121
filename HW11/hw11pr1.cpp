#include "std_lib_facilities_4.h"
int main(){
    int array_test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vector_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list_test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int array_me[10];
    vector<int> vector_me(10);
    list<int> list_me(10);

    copy(array_test.begin(), array_test.end(), array_me.begin());
    copy(vector_test.begin(), vector_test.end(), vector_me.begin());
    copy(list_test.begin(), list_test.begin(), list_me.begin());

    return 0;
}
