// Author: Seth Barberee
// Assignment: Homework 4 Problem 1
// Purpose: Output all permutations of a string that the user inputs

#include "std_lib_facilities_4.h"

vector<char> swap_letters(vector<char> &a, int index){
    vector<char> v = a;
    char extra;
    extra = v[(index)];
    v[(index)] = v[(index-1)];
    v[(index-1)] = extra;
    for (unsigned int j = 0; j < v.size(); j++){
        cout << v[j];
    }
    return v;
}

int main(){
    vector<char> letters, letters_loop, test;
    string phrase, phrase_re;
    cout << "Input a phrase: ";
    cin >> phrase;
    cout << endl;
    if (phrase.length() <= 1){
        cout << "The only permutation is itself" << endl;
        cout << phrase << endl;
    }
    for(unsigned int i = 0; i < phrase.size(); i++){
        letters.push_back(phrase[i]);
    }
    letters_loop = letters;
    // Write logic here to do the permutations (add them to vector and print them with the for loop below)
    for (unsigned int j = 0; j < letters.size(); j ++){
        for (int i = (letters.size()-1); i > 0; i--){
            test = swap_letters(letters_loop,i);
            cout << endl;
            letters_loop = test;
            if (test == letters){
                break;
            }
        }
    }
}
