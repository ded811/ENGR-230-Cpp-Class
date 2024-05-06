#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function prototypes
int loadArray(ifstream& infile, double x[], double y[], int MAXVALUES);
void linearFit(double x[], double y[], int n, double& m, double& b, double& r2);
double calcMean(double resist[], int numValues);
void outputFxn(int n, double avgT, double avgR, double m, double b, double r2);

const int MAXVALUES = 100; // Max number of values

int main() {
    double x[MAXVALUES];
    double y[MAXVALUES];
    int n = 0;  // Number of data points
    double m = 0;   // Slope of best fit line
    double b = 0;   // y-intercept of best fit line
    double r2 = 0;  // Coefficient of determination
    double avgT = 0;    
    double avgR = 0;    
    ifstream infile("HW10resist.txt");
    if (!infile) {
        cout << "Error opening File." << endl; // Display error message if file opening fails
        return 1;
    } else {
        n = loadArray(infile, x, y, MAXVALUES);
    }
    linearFit(x, y, n, m, b, r2);
    avgT = calcMean(x, n);
    avgR = calcMean(y, n);
    outputFxn(n, avgT, avgR, m, b, r2);
    infile.close(); // Close file
    return 0;
}

int loadArray(ifstream& infile, double x[], double y[], int MAXVALUES) {
    int i = 0;
    char junk[MAXVALUES];
    infile.getline(junk, MAXVALUES);
    while (i < MAXVALUES && infile >> x[i] >> y[i]) {
        i++;
    }
    return i;
}

void outputFxn(int n, double avgT, double avgR, double m, double b, double r2) {
    cout << "Alex Zimmermann ENGR230 Least Squares" << endl;
    cout << "Analyzing data in file HW10resist.txt" << endl << endl;
    cout << "Number of data points = " << n << endl;
    cout << "Mean value of Temperature (deg. F) " << avgT << endl;
    cout << "Mean value of Resistance  (Ohms) " << avgR << endl;
    cout << "The equation of the best fit line is: y=" << m << "x+" << b << endl;
    cout << "The R-squared value is: " << r2 << endl;
    return;
}

void linearFit(double x[], double y[], int n, double& m, double& b, double& r2) {
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;
    double sumY2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }
    m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY * sumX2 - sumX * sumXY) / (n * sumX2 - sumX * sumX);
    r2 = pow((n * sumXY - sumX * sumY) / (sqrt(n * sumX2 - sumX * sumX) * sqrt(n * sumY2 - sumY * sumY)), 2);
    return;
}

double calcMean(double resist[], int numValues) {
    double sum = 0; // Variable to store sum of values
    // Loop through array to calculate sum of values
    for (int i = 0; i < numValues; i++) {
        sum += resist[i];
    }
    return sum / numValues; // Return the mean
}
