// Author: Seth Barberee
// Assignment: HW 2 Problem 2
// Purpose: User inputs a sequence of heights in inches and they are repeatedly asked which statistic they would like computed. That chosen statistic is computed and displayed to the user.

#include "std_lib_facilities_4.h"

// Takes a vector of numbers and returns the average of the vector
int average(vector<int> a){
    int avg;
    int sum = 0;
    int count = 0;
    // Count up all the elements and add them together in the loop
    for (int i = 0; i < a.size(); ++i){
        sum = sum + a[i];
        count = count + 1;
    }
    // Divide total by number to find average
    avg = sum/count;
    return avg;
}

// Takes a vector and returns the middle (median) of the vector
int median(vector<int> a){
    int median;
    // Vector is sorted from lowest to highest so take the middle of the vector
    int middle = (a.size() / 2);
    median = a[middle];
    return median;
}

// Takes a vector and returns the minimum or the lowest value in the vector
int minimum(vector<int> a){
    // Vector is sorted from lowest to highest so take the first value
    int min = a[0];
    return min;
}

// Takes a vector and returns the maximum or the highest value in the vector
int maximum(vector<int> a){
    int max;
    // Vector is sorted from lowest to highest so take the last value
    int max_loc = a.size() - 1;
    max = a[max_loc];
    return max;
}

// Takes a vector and returns the most occuring value in the vector
int mode(vector<int> a){
    int most = 0;
    int num_count = 1;
    int max_count = 1;
    // Start at the beginning of the vector and compare the next value to it
    for (int i = 0; i < a.size(); ++i){
        for (int j = i + 1; j < a.size(); ++j){
            if (a[i] == a[j]){
                num_count = num_count + 1;
                // If the number of values is greater than current mode, replace it
                if (num_count >= max_count){
                    max_count = num_count;
                    most = a[i];
                }
            }
        }
    }
    return most;
}

int main(){
    int height;
    int stat;
    cout << "Input the sequence of positive heights in inches then input any number equal or less than 0 to end the sequence" << endl;
    vector<int> heights;
    while(cin){
        cin >> height;
        // We only want positive integers for the heights
        if (height <= 0 || !cin){
            break;
        }
        // Add the height to the vector
        heights.push_back(height);

    }
    // Sorts the vector from smallest to largest
    sort(heights.begin(),heights.end());
    while(cin){
        // Tests if user only entered a 0 or if the heights vector is empty
        if (heights.size() < 1){
            cout << endl;
            cout << "Must have at least one positive height to compute statistics" << endl;
            cout << endl;
            break;
        }
        cout << "What statistic would you like computed?" << endl;
        cout << "Mean (1) , Max (2) , Min (3) , Mode (4) , Median (5)" << endl;
        cout << "Type Quit (6) to quit the program" << endl;
        cin >> stat;
        cout << endl;
        
        // Execute the user's choice
        switch(stat){

        case 1:
            // User choice is average so compute it and output it
            cout << "Average: " << average(heights) << endl;
            cout << endl;
            break;
        case 2:
            // User choice is maxiumum so compute it and output it
            cout << "Max: " << maximum(heights) << endl;
            cout << endl;
            break;
        case 3:
            // User choice is minimum so compute it and output it
            cout << "Min: " << minimum(heights) << endl;
            cout << endl;
            break;
        case 4:
            // User choice is mode so compute it and output it
            cout << "Mode: " << mode(heights) << endl;
            cout << endl;
            break;
        case 5:
            // User choice is median so compute it and output it
            cout << "Median: " << median(heights) << endl;
            cout << endl;
            break;
        case 6:
            // Kill the program
            break;
        default:
            // Any input besides the six given will give an error message and continue prompting
            cout << "Invalid Input!" << endl;
            cout << endl;
        }
        
        // Kill the program
        if (stat == 6){
            // Kill the program
            cout << "Killing program..." << endl;
            cout << endl;
            break;
        }
    }
}
