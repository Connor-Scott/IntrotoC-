// Lab 1 Part 1 - Volume of a Retengular Prism 

// Code prompts user for a length, width, and height of their Rectangular Prism, 
// preforms the volume calculation and returns the result. Volume calc is performed 
// in line because the calc is simple and result is never re-used by program. 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 


int main() {
    float l, w, h;
    cout << fixed << setprecision(3);

    cout << "\n\nPlease enter the side lengths of your retengular prism.\n\n";

    cout << "Enter value for side a: ";
    cin >> l;

    cout << "Enter value for side b: ";
    cin >> w;

    cout << "Enter value for side c: ";
    cin >> h; 

    if (cin.fail()) { //Conditional to handel non-numerical formating
        cin.clear(); 
        cout << "\n\nPlease only enter the length of each side in a numerical format.\n\n";
        cin.ignore(); 
        main();
        return 0; 
    } 

    cout << "Retangular Prism Volume:  " << (l*w*h) << endl; 
    return 0; 
}