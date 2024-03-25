#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Function prototypes
void inputFxn(double& left, double& right);
double fcn(double t);
bool bisect(double& left, double& right);

const double k = 1.25E9; // spring constant in g/s^2
const double c = 1.40E7; // damping coefficient in g/s
const double m = 3000*453.6; // mass of the car in grams
const double x0 = 10*0.0254; // depth of the hole in meters


int main()
{
    double left = 0;    // left bounds
    double right = 0;   // right bounds
    int iter = 0;       // number of iterations

    ofstream outfile("HW7Results.txt");
    if (!outfile) {
        cout << "Error opening File." << endl;
        return 1;
    } 
    inputFxn(left, right);
    outfile << "iter   time(left)   time(right)   position(left)   position(right)" << endl;
    outfile << iter << " " << left << " " << right << " " << fcn(left) << " " << fcn(right) << " " << endl;
    while (right-left > 0.000001 && !bisect(left, right))       //While difference between right and left bounds are larger than our percision we will keep iterating
    {
        iter++;     //adds to our iteration number
        outfile << iter << " " << left << " " << right << " " << fcn(left) << " " << fcn(right) << " " << endl;
    }
    if (bisect(left, right))    //checks to see if the reason we got kicked out was because their was no root, or that their was one
    {
        cout << "No root." << endl;     // says no root
    }
    else   
    {
        cout << "The root is: " << left << endl;     //displays the root
    }
    outfile.close();
    return 0;
}

void inputFxn(double& left, double& right)  //inputFxn function
{
    cout << "HW7 Root Finding" << endl;
    cout << "Please enter the lower limit:";
    cin >> left;
    cout << endl << "Please enter the upper limit:";
    cin >> right;
    return;
}

double fcn(double t)            //fcn function
{
    double n = c / (2 * m);
    double s = sqrt((k / m) - ((c * c) / (4 * m * m)));
    double x = exp(-n * t) * (x0 * cos(s * t) + x0 * (n / s) * sin(s * t));
    return x;
}

bool bisect(double& left, double& right) {      //bisect function
    if (fcn(left)*fcn(right) > 0)
        return 1;
    double mid = (left + right)/2;
    if (fcn(left)*fcn(mid) < 0)
        right = mid;
    else
        left = mid;
    return 0;
 }
