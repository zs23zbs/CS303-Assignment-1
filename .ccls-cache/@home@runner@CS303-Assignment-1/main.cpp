#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"
#include <iomanip>

using namespace std;

int main() {

    ifstream input_file; // declare stream variable 

    input_file.open("A1input.txt"); // open the input file 

    if (!input_file.is_open()){ // verify the input file 
        cout << "There is an error in opening the input file." << endl;
        return 1; // Exit the program if the file cannot be opened
    } else {
        cout << "The input file is open." << endl << endl;
    }

    // Using vector to READ the input file 
    vector<int> int_data;

    // Other variables
    int val;

    // Read the input file and store into vector 
    while (input_file >> val) {
        int_data.push_back(val);
    }

    // Close the input file
    input_file.close();

    // Create variables for array 
    int capacity = 30; // Set a higher capacity to allow for elements to be inserted into array
    int arraySize = int_data.size(); // Set array size with size of vector 
    int array[arraySize];

    // Copy data from the vector into the array
    for (int i = 0; i < arraySize; i++) {
        array[i] = int_data[i];
    }

    // Menu for user input
    char choice = 0; 

    while (choice != 'Q') {
        cout << "\t\tMENU:" << endl;
        cout << "A) Print current array." << endl;
        cout << "B) Search for element in array." << endl;
        cout << "C) Add a element to the array." << endl;
        cout << "D) Delete element from array." << endl;
        cout << "E) Replace element in array." << endl;
        cout << "Q) Quit program." << endl << endl;

        cout << "Please select among the options: ";
        cin >> choice; 

        cout << endl; // Format spacing

        choice = toupper(choice); // Change user inputs to uppercase for if-else branches 

        if (choice == 'A') {
            cout << "\n\t" << "Index" << setw(12) << "Value" << endl;
            for (int i = 0; i < arraySize; i++) { // Iterate through the array 
                // Print all elements in the array
                cout << setw(7) << i << setw(13) << array[i] << endl;
            }

            cout << endl; // Format spacing 
        }
        else if (choice == 'B') {
            // Variables to check integer is in array 
            int search_val = 0;

            cout << "Please enter an value to search for in array: ";
            cin >> search_val;

            // Search for the integer in the array
            check_integer(array, arraySize, search_val);

            cout << endl << endl; // Format spacing 
        }
        else if (choice == 'C') {
            try {
                int new_val = 0;
                cout << "Please enter an value to add to the end of an array: ";
                cin >> new_val;

                addElement(array, arraySize, capacity, new_val);

                cout << endl << endl; // Format spacing 
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            // Show array with new value(s) inserted 
            cout << "\n\t" << "Index" << setw(12) << "Value" << endl;
            for (int i = 0; i < arraySize; i++) { // Iterate through the array 
                // Print all elements in the array
                cout << setw(7) << i << setw(13) << array[i] << endl;
            }

            cout << endl; // Format spacing 
        }
        else if (choice =='D') {
            try {
                int del_val = 0;
                cout << "Please enter an index to delete the value of in array: ";
                cin >> del_val;

                deleteElement(array, arraySize, del_val);

                 cout << endl << endl; // Format spacing 
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            // Show array with "deleted" value(s) 
            cout << "\n\t" << "Index" << setw(12) << "Value" << endl;
            for (int i = 0; i < arraySize; i++) { // Iterate through the array 
                // Print all elements in the array
                cout << setw(7) << i << setw(13) << array[i] << endl;
            }
        }
        else if (choice == 'E') {
            try {
                int user_index = 0;
                int user_val = 0; 
                cout << "Please enter an index integer: ";
                cin >> user_index;

                cout << "\nPlease enter a new value to replace the old value: ";
                cin >> user_val;

                modifyElement(array, arraySize, user_index, user_val);

                cout << endl << endl; // Format spacing 
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }

            // Show array with "deleted" value(s) 
            cout << "\n\t" << "Index" << setw(12) << "Value" << endl;
            for (int i = 0; i < arraySize; i++) { // Iterate through the array 
                // Print all elements in the array
                cout << setw(7) << i << setw(13) << array[i] << endl;
            }
        }
        else if (choice == 'Q'){
            break; // Exit out of the if-else statements to end the program 
        }
    }

    cout << "\nEnd of Program. Have a good day :)" << endl;
    return 0;
}