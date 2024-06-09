#include "functions.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void check_integer(int array[], int arraySize, int val) {

    bool found = false; // Indicate whether the value is found, true or false

    for (int i = 0; i < arraySize; i++) { // iterate through the array 

        if (val == array[i]) { // check if user integer is in array 
            cout << "\nThe value " << val << " is in the array." << endl << endl;
            cout << "The index of the value is " << i << "." << endl;
            found = true;
            break; // Exit the loop if the value is found
        }
    }
    if (!found) { // if val is not found in array, warn user
        cout << "The value " << val << " is not in the array." << endl;
    }
}

int addElement(int array[], int& num_items, int current_capacity, int val) {

    // Make sure that there is space for a new item in array 
    if (num_items == current_capacity) {
        throw overflow_error("Capacity of array is full");
    }

    // Insert the new item at the specified index
    array[num_items] = val;
    num_items++;

    // Return the index where the new item was inserted
    return num_items;
}

int deleteElement(int array[], int& num_items, int index) {

    // validate the index
    if (index < 0 || index >= num_items) {
        throw out_of_range("Index to delete from array is out of range");
    }
    else if (num_items == 0) {
        throw underflow_error("Array is empty");
    }

    // Replace the value at the index to zero
    array[index] = 0;

    // Decrement the number of items in the array
    num_items--;

    // Return the index where the item was deleted
    return num_items;
}

int modifyElement(int array[], int& num_items, int index, int new_val) {

    // Check if the index is valid
    if (index < 0 || index >= num_items) {
        throw out_of_range("Index to replace in array is out of range");
    }
    else if (num_items == 0) {
        throw underflow_error("Array is empty");
    }

    // Return the old value to the user 
    cout << "\nThe old value at index " << index << " is " << array[index] << endl << endl;

    // Replace the value at the specified index
    for (int i = 0; i < num_items; i++) {
        array[index] = new_val;
    }

    // Returnt the new value to the user
    cout << "The new value at index " << index << " is " << array[index] << endl;


    return num_items;
}