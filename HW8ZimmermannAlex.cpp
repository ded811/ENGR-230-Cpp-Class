#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Function prototypes
void inputFxn(double& lower, double& upper);    // Function to input lower and upper limits
void outputFormat(ofstream& outfile, double lower, double upper);   // Function to format output
double integrate(double xl, double xr, int n);   // Function to perform numerical integration
double sinc(double x);   // Function to calculate the sinc function

int main()
{
    double lower = 0;   // Lower limit of integration
    double upper = 0;   // Upper limit of integration
    int n = 10;         // Initial number of intervals

    ofstream outfile("HW8Results.txt");    // Output file stream to save results
    if (!outfile) {
        cout << "Error opening File." << endl;   // Display error message if file opening fails
        return 1;
    } 

    inputFxn(lower, upper);     // Input lower and upper limits from user
    outputFormat(outfile, lower, upper);   // Format output file with integration details

    // Perform numerical integration using trapezoidal rule with increasing number of intervals
    while (n <= 160)
    {
        outfile << n << " " << integrate(lower, upper, n) << endl;    // Write results to output file
        n = n * 2;    // Double the number of intervals
    }

    cout << "The area is: " << integrate(lower, upper, n) << endl;    // Display final integration result
    cout << "Detailed results can be found in HW8Results.txt" << endl;   // Inform user about result file

    outfile.close();    // Close the output file
    return 0;
}

// Function to input lower and upper limits from user
void inputFxn(double& lower, double& upper)
{
    cout << "Please enter lower limit:" << endl;
    cin >> lower;
    cout << "Please enter the upper limit:"; 
    cin >> upper;
}

// Function to format output file with integration details
void outputFormat(ofstream& outfile, double lower, double upper)
{
    outfile << "Alex Zimmermann Numerical Integration" << endl;
    outfile << "Integration of y = sin(x)/x from x = " << lower << " to x = " << upper << endl;
    outfile << "Trapezoidal Rule Area" << endl;   // Corrected typo: "Traps Area" to "Trapezoidal Rule Area"
}

// Function to calculate the sinc function
double sinc(double x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return sin(x) / x;
    }
}

// Function to perform numerical integration using trapezoidal rule
double integrate(double xl, double xr, int n)
{
    double sum = 0;     // Initialize sum for numerical integration
    double area = 0;    // Initialize area for final result
    double wn = (xr - xl) / n;    // Width of each interval
    double xi = 0;      // Initialize the value of x_i for each interval
    for (int i = 1; i < n; i++)
    {
        xi = xl + i * wn;    // Calculate the value of x_i
        sum = sum + sinc(xi);    // Accumulate sum by evaluating sinc function at x_i
    }
    area = 0.5 * wn * (sinc(xl) + sinc(xr) + 2 * sum);    // Calculate final area using trapezoidal rule
    return area;
}
