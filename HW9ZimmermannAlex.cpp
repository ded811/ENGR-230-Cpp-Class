#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
int loadArray(ifstream& infile, double resist[], int MAXVALUES); // Function to load array from file
double findMax(double resist[], int numValues); // Function to find maximum value
double findMin(double resist[], int numValues); // Function to find minimum value
double calcMean(double resist[], int numValues); // Function to calculate mean
double geomMean(double resist[], int numValues); // Function to calculate geometric mean
double rmsAvg(double resist[], int numValues); // Function to calculate RMS average
double harmMean(double resist[], int numValues); // Function to calculate harmonic mean
void sortArray(double array[], int limit); // Function to sort array
void inputFxn(double& lower, double& upper); // Function to input lower and upper limits
void outputFormat(ofstream& outfile, double lower, double upper); // Function to format output

const int MAXVALUES = 100; // Max number of values

int main() {
    double resist[MAXVALUES]; // Array to store resistance values
    int numValues = 0; // Variable to store the number of values read
    ifstream infile("HW9resist.txt"); // opens values file
    if (!infile) {
        cout << "Error opening File." << endl; // Display error message if file opening fails
        return 1;
    } else {
        numValues = loadArray(infile, resist, MAXVALUES); // Load values from file into array
    }

    cout << fixed << setprecision(6); // Set precision for mean, geometric mean, rms average, and harmonic mean
    cout << "Alex Zimmermann, Program 9" << endl;
    cout << "Sample Resistance Study" << endl << endl;
    cout << "The maximum value is " << fixed << setprecision(2) << findMax(resist, numValues) << endl; // Set precision for maximum value
    cout << "The minimum value is " << fixed << setprecision(2) << findMin(resist, numValues) << endl; // Set precision for minimum value
    cout << "The mean is "<< fixed << setprecision(6) << calcMean(resist, numValues) << endl; // Calculate and display mean
    cout << "The geometric mean is " << fixed << setprecision(6) << geomMean(resist, numValues) << endl; // Calculate and display geometric mean
    cout << "The rms average is " << fixed << setprecision(6) << rmsAvg(resist, numValues) << endl; // Calculate and display RMS average
    cout << "The harmonic mean is "<< fixed << setprecision(6) << harmMean(resist, numValues) << endl << endl; // Calculate and display harmonic mean

    sortArray(resist, numValues); // Sort the array in ascending order
    cout << "The sorted list of values is:" << endl;
    cout << fixed << setprecision(2); // Set precision for sorted list values
    for (int i = 0; i < numValues; i++) {
        cout << resist[i] << endl; // Display sorted list of values
    }
    return 0;
}

// Function to load array from file
int loadArray(ifstream& infile, double resist[], int MAXVALUES) {
    int i = 0; // Index variable
    // Read values from file into array until MAXVALUES is reached or end of file
    while (i < MAXVALUES && infile >> resist[i]) {
        i++;
    }
    return i; // Return the number of values read
}

// Function to find maximum value
double findMax(double resist[], int numValues) {
    double max = resist[0]; // Initialize max with the first element of array
    // Loop through array to find maximum value
    for(int i = 1; i < numValues; i++) {
        if(resist[i] > max) {
            max = resist[i];
        }
    }
    return max; // Return the maximum value
}

// Function to find minimum value
double findMin(double resist[], int numValues) {
    double min = resist[0]; // Initialize min with the first element of array
    // Loop through array to find minimum value
    for(int i = 1; i < numValues; i++) {
        if(resist[i] < min) {
            min = resist[i];
        }
    }
    return min; // Return the minimum value
}

// Function to calculate mean
double calcMean(double resist[], int numValues) {
    double sum = 0; // Variable to store sum of values
    // Loop through array to calculate sum of values
    for(int i = 0; i < numValues; i++) {
        sum += resist[i];
    }
    return sum / numValues; // Return the mean
}

// Function to calculate geometric mean
double geomMean(double resist[], int numValues) {
    double product = 1.0; // Variable to store product of values
    // Loop through array to calculate product of values
    for(int i = 0; i < numValues; i++) {
        product *= resist[i];
    }
    return pow(product, 1.0 / numValues); // Return the geometric mean
}

// Function to calculate RMS average
double rmsAvg(double resist[], int numValues) {
    double sumSquares = 0.0; // Variable to store sum of squares of values
    // Loop through array to calculate sum of squares of values
    for(int i = 0; i < numValues; i++) {
        sumSquares += pow(resist[i], 2);
    }
    return sqrt(sumSquares / numValues); // Return the RMS average
}

// Function to calculate harmonic mean
double harmMean(double resist[], int numValues) {
    double sumReciprocals = 0.0; // Variable to store sum of reciprocals of values
    // Loop through array to calculate sum of reciprocals of values
    for(int i = 0; i < numValues; i++) {
        sumReciprocals += 1.0 / resist[i];
    }
    return numValues / sumReciprocals; // Return the harmonic mean
}

// Function to sort array in ascending order
void sortArray(double array[], int limit) {
    double temp; // Temporary variable for swapping values
    // Nested loops to compare and swap values to sort the array
    for (int hold = 0; hold < limit - 1; hold++) {
        for (int comp = hold + 1; comp < limit; comp++) {
            if (array[comp] < array[hold]) {
                temp = array[hold];
                array[hold] = array[comp];
                array[comp] = temp;
            }
        }
    }
}
