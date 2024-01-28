// Alex Zimmermann       Carbon Dating using % Carbon

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const double lambda = 0.00012097; 
    double percCarbon = 0;
    double t = 0;
    cout << "HW2 Carbon Dating Program" << endl;
    cout << "Please enter the % of Carbon 14 remaining: ";
    cin >> percCarbon;
    cout << endl;
    t = -(log(percCarbon / 100.0)) / lambda;;
    cout << "A sample of Carbon 14 that contains " << percCarbon << "% of its original amount is " << fixed << setprecision(0) << t << " years old." << endl;
    return 0;
}