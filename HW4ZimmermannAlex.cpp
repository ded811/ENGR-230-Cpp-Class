#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const double PI = acos(-1.0);   // Numerical representation of PI
    double n1 = 0;                  // Index of refraction 1
    double n2 = 0;                  // Index of refraction 2
    double theta1 = 0;              // Entrance Angle in degrees
    double theta2 = 0;              // Exit Angle in degrees
    cout << "HW4 Snell's Law" << endl;
    cout << "Please enter the entrance angle in degrees: ";
    cin >> theta1;              // sets the entrance angle in degrees
    cout << endl << "Please enter the index of refraction of the first material: ";
    cin >> n1;                  // sets the index of refraction for the first material
    cout << "Please enter the index of refraction of the second material: ";
    cin >> n2;                  // sets the index of refraction for the second material
    if (n1 / n2 * sin(theta1 * PI / 180.0) <= 1) {              // If N1 divided by N2 times sin(theta1) is less than one, do the math, if not all light is reflected.
        theta2 = (180.0 / PI) * asin((n1 / n2) * sin(theta1 * PI / 180.0));         // Find Theta 2
        cout << "Light entering the material interface from ";
        if (n1 > n2) {                        // If n1 is bigger than n2 say "glass to water, if not say water to glass"
            cout << "glass to water";
        }
        else {
            cout << "water to glass";
        }
        cout << " with an entrance angle of " << theta1
             << " degrees will exit with an angle of " << theta2
             << " degrees." << endl;
    }
    else {
        cout << "All light is reflected." << endl;
    }
    return 0;
}