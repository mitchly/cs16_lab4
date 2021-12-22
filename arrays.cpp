/*
/ Skeleton file for arrays.cpp for CS16, 2021, UCSB
/ Copyright © 2021 by Zachary Sisco. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);

    print_array(array, size);
    int max = maxArray(array, size);
    int min = minArray(array, size);
    int sum = sumArray(array, size);
    evensArray(array, size);
    primesArray(array,size);
    AllSearches(array, size);

    return 0;
}

// PUT MISSING FUNCTION DEFINITIONS HERE

void print_array(int arr[], int asize){
    for(int i = 0; i < (asize - 1); i++){
        cout << arr[i] << ", ";
    }
    cout << arr[asize - 1] << endl;
    return;
}

int maxArray(int arr[], int asize){
    int maximum = arr[0];
    for(int i = 0; i < asize; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }
    cout << "Max = " << maximum << endl;
    return 0;
}

int minArray(int arr[], int asize){
    int minimum = arr[0];
    for(int i = 0; i < asize; i++){
        if (arr[i] < minimum){
            minimum = arr[i];
        }
    }
    cout << "Min = " << minimum << endl;
    return 0;
}

int sumArray(int arr[], int asize){
    int sum = 0;
    for(int i = 0; i < asize; i++){
        sum += arr[i];
    }
    cout << "Sum = " << sum << endl;
    return 0;
}

void evensArray(int arr[], int asize){
    cout << "Evens: ";
    for(int i = 0; i < asize; i++){
        if(arr[i] % 2 == 0){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
    return;
}

void primesArray(int arr[], int asize){
    cout << "Primes: ";
    for(int i = 0; i < asize; i++){
        bool prime = true;
        if(arr[i] <= 1){
            continue;
        }
        for(int j = 2; j * j <= arr[i]; j++){
            if(arr[i] % j == 0){
                prime = false;
                break;
            }
        }
        if(prime == true){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
    return;
}

int SeqSearch(int arr[], int array_size, int target){
    for(int i = 0; i < array_size; i++){
        if(arr[i] == target){
            cout << " Found at index: " << i << endl;
            return 0;
        }
    }
    cout << " Not Found!" << endl;
    return -1;
}

void AllSearches(int arr[], int array_size){
    cout << "Searches:" << endl;
    for(int i = 0; i < NSEARCHES; i++){
        cout << "Looking for " << SEARCHES[i] << ".";
        SeqSearch(arr, array_size, SEARCHES[i]);
    }
    return;
}