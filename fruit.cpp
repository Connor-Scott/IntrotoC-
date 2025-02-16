//Lab 1 Part 2 

// First function takeOrder takes two args, first being the maximum amount of that fruit Bob has and the 
// second is the name of that fruit. Function attempts to address handling problematic user input, first non-numerical 
// input, second over ordering, and third fractional orders. Recursion is used to gather user input after impossible user entry.
// The main function takes no args and prompts the user for their order. Constants are used to define fruit price 
// and maximum inventory quantity. Calc for totals per fruit and for total are handled in line because they're simple calculations. 
// Order total is formatted so that the fruit quality, cost, and fruit total appear spaced evenly, total is tallied at the bottom. 
// Order invoice is limited to 2 sig figs for cents, though no possible orders can exceed 2 sig figs, and total space used 
// is no more than 35 line spaces. 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

int takeOrder(int max_order, string item) {
    float order; 
    
    cout << "How many " << item << " would you like to buy\? ";
    cin >> order;
    
    if (cin.fail()) { //Conditional to handel non-numerical formating, cin.fail() only seems to work if a string is entered that does not contain any numbers. 
        cin.clear(); 
        cout << "\n\nYou may only order whole fruits. Please specify your quanity of fruits in numerical format...\n\n";
        cin.ignore(); 
        order = takeOrder(max_order, item); //Calling this function again to gather user input after error. 
    } else if (order > max_order) { //Conditional to limit over-ordering from Bob. 
        cout << "Sorry! Bob only has " << max_order << " " << item << " to sell today...\n\n";
        cin.clear(); 
        cin.ignore(); 
        order = takeOrder(max_order, item); //Call function again after displaying warning to user. 
    }
    return floor(order + 0.99999); //To make sure no one orders fractional fruit, as I don't believe Bob would let his customers get away with this, I decided to round a users order up if they try to order part of a fruit. 
}


int main() {
    int oranges, bananas, apples;
    const float ORANGES_PRICE = 0.90;
    const float BANANAS_PRICE = 0.75; 
    const float APPLES_PRICE = 0.65; 

    const int ORANGES_MAX = 100;
    const int BANANAS_MAX = 120;
    const int APPLES_MAX = 80;

    // Setting up formatting for invoice display.  
    const int W = 5;
    cout << fixed << setprecision(2);

    cout << "\n\nWelcome to Bob's Fruits!\n\n"; //Welcome message to user. 

    // Gathering user input with some error handleing from takeOrder() function. 
    oranges = takeOrder(ORANGES_MAX, "oranges");
    bananas = takeOrder(BANANAS_MAX, "bananas");
    apples = takeOrder(APPLES_MAX, "apples");

    cout << setw(W) << fixed << "\n\n\n\t       Bob's Fruits Invoice\n" 
         << "—----------—-----------------------" << endl 
         << setw(W) << oranges << " oranges, $" << ORANGES_PRICE << " each --- $" << oranges * ORANGES_PRICE << endl 
         << setw(W) << bananas << " bananas, $" << BANANAS_PRICE << " each --- $" << bananas * BANANAS_PRICE << endl
         << setw(W) << apples << " apples,  $" << APPLES_PRICE << " each --- $" << apples * APPLES_PRICE << endl
         << "—----------—-----------------------" << endl 
         << setw(W) << "\t\t     TOTAL = $" <<  (oranges * ORANGES_PRICE + bananas * BANANAS_PRICE + apples * APPLES_PRICE) << endl;
    return 0; 
}