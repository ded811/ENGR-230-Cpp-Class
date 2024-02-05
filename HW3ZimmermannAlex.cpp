// Alex Zimmermann       Calculate the time a falling object takes to reach specified height

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const double g = 9.81;      // Acceleration due to gravity meters squared
    double h = 0;               // final height
    double hi = 0;              // initial height
    double vi = 0;              // initial velocity
    double t = 0;               // time in seconds
    cout << "HW3 Armageddon" << endl;
    cout << "Please enter the initial height in meters: ";
    cin >> hi;                  // sets the initial height
    cout << endl << "Please enter the initial velocity in meters/second: ";
    cin >> vi;                  // sets the initial velocity
    cout << "Please enter the final height in meters: ";
    cin >> h;                  // sets the final height
    t = (-vi + sqrt(vi * vi - 2 * g * (h - hi))) / g;       //calculates t
    cout << "An objcet starting at a height of " << hi << " meters and a velocity of "
         << vi <<"m/s will reach height of" << "meters in " <<t<< "seconds." <<endl;
    return 0;
}