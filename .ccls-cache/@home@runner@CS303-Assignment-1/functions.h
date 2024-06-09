#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function Declarations

void check_integer(int array[], int arraySize, int val);
// PRE: Takes an index, value, and array size
// POST: Checks if the values is in array

int addElement (int array[], int& num_items, int current_capacity, int val);
// PRE: Takes an index, a value, current capacity, and number of items in the array
// POST: Adds the value to the array at the end of the array

int deleteElement(int array[], int& num_items, int index);
// PRE: Takes an index and number of items in array
// POST: Deletes (replaces value with zero) the value from the array depending on the index given

int modifyElement(int array[], int& num_items, int index, int new_val);
// PRE: Takes an index, value, and number of items in array
// POST: Replaces the value in the array at the index with the new value