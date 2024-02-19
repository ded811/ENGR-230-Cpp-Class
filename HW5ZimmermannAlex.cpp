#include <iostream>                 // Bulletproofing Calc's
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x = 0;                  // Input Value
    double y = 0;                  // Resulting Calculation Based on X
    cout << "HW5 Bulletproofing Calc's " << endl;                // Declares what calculation it is doing
    cout << "Enter the value of x (999 to quit): ";              // Prompts user for input
    cin >> x;                       // Enters Input
    while (x != 999 ) {             // Check is x is 999 and if it is program closes
        if (x > 1) {                                                    //checks if x is negative
            cout << "Can not take natrual log of a negative number.";   //error for x being negative
        }
        else if(x == 1) {                           // Checks if x is 1
            cout << "Can not divide by zero. ";     // Error given for x being 1
        }
        else{
            y = log(1/(1-x));                               // does the calulation y(x)=ln(1/(1-x))
            cout << "Ln(1/ (1 - " << x << ")) = " << y ;    // outputs the input and output
        }
        cout << "Enter the value of x (999 to quit): ";      // askes for the new value of x, if sutable number program will restart
        cin >> x;                                           // sets new value of x
    }
return 0;
}