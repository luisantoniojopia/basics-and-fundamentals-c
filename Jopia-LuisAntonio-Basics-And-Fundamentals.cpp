#include <iostream>
using namespace std;

// Limit number of elements each array can hold
const int maximumInput = 10;

// Declare functions that will be used
void getInput(int inputArray[], int &size);
void mergeArrays(int inputArray1[], int size1, int inputArray2[], int size2, int mergedArr[], int &mergedSize);
void sortDescending(int inputArray[], int size);
void displayArray(const int inputArray[], int size);

// Get user input for an array with validation
void getInput(int inputArray[], int &size) {
    bool valid = false;
    while (!valid) {
        cout << "\nEnter the number of elements (1 - 10): ";
        cin >> size;

        // Check for invalid input (non-integer, negative, or more than 10)
        if (size >= 1 && size <= maximumInput) {
            valid = true;
        } else {
            cout << "Invalid input. Please enter a number between 1 and 10.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
        }
    }

    cout << "\nEnter the elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> inputArray[i];
    }
}

// Merge two arrays into one array
void mergeArrays(int inputArray1[], int size1, int inputArray2[], int size2, int mergedArr[], int &mergedSize) {
    mergedSize = 0;
    for (int i = 0; i < size1; i++) {
        mergedArr[mergedSize++] = inputArray1[i];
    }
    for (int i = 0; i < size2; i++) {
        mergedArr[mergedSize++] = inputArray2[i];
    }
}

// Sort an array in descending order
void sortDescending(int inputArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (inputArray[i] < inputArray[j]) {
                // Swap using arithmetic operations
                inputArray[i] = inputArray[i] + inputArray[j];
                inputArray[j] = inputArray[i] - inputArray[j];
                inputArray[i] = inputArray[i] - inputArray[j];
            }
        }
    }
}

// Display the elements of an array
void displayArray(const int inputArray[], int size) {
    cout << "\nMerged array in descending order:\n";
    for (int i = 0; i < size; i++) {
        cout << inputArray[i] << " ";
    }
    cout << endl;
}

int main() {
    int array1[maximumInput], array2[maximumInput], mergedArray[2 * maximumInput];
    int sizeOfInput1, sizeOfInput2, mergedMaximumInput = 0;

    getInput(array1, sizeOfInput1);
    getInput(array2, sizeOfInput2);

    mergeArrays(array1, sizeOfInput1, array2, sizeOfInput2, mergedArray, mergedMaximumInput);

    sortDescending(mergedArray, mergedMaximumInput);

    displayArray(mergedArray, mergedMaximumInput);

    return 0;
}