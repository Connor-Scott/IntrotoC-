#include <iostream>
#include <iomanip>
using namespace std; 

// The code for the theater ticket sales first defines each of the seats in the theater as char '*'. Then it prompts the user with the all_menu function. Its defined as 
// a seperate function to make it easier to call if there are errors in the menu selection. The display seats function takes the row and aisle of the seat as 
// its argumnets, both set to integer variables. It refrences a 1 dimentional array because seat cost is determined by the seat row. It then indexes that 
// 1D array to locate the seat cost. This function is called by the all_menu function when a user wants to determine their total cost for their movie tickets. 
// The all_menu function takes a char argument which is the theater layout. This is done to ensure that the theater remains updated when its called after the user makes 
// a valid selection of their seat. Menu item 1 checks to see if the user's input is within the range of the theater. Then checks to see if it is available. If either of 
// these conditions are untrue, it informs the user that they've made an invalid selection. These two conditions are checked individually and in this order to enusre 
// that the array is not improperly indexed when checking to see if the seat is avaliable. When the user makes a valid selection the theater is displayed again with 
// the selection they've made. If they want to select another seat then the function will default to promting them for seats as a result of the while loop this section is defined 
// in.  If the user wants to check their total and exit thier total is displayed and then the main fucntion terminates. Their total revenu is calcualted by adding the seat cost based 
// on row to the total revenue float variable if the char in the array is equal to '#'. This condition will also trigger the total number of seats sold to have 1 added to it. 
// The total revenue is always displayed in dollars with two sig figs. 


void display_seats(char seats[10][7]);
double get_seat_price(int, int); 
int all_menu(char); 

void display_seats(char seats[10][7]) {
    cout << "\n* Seat Available\n# Seat Taken\nSeats:  0  1  2  3  4  5  6\n"; 
    for(int r = 0; r < 10; r++) {
        cout << "Row " << r << "   ";
        for(int a = 0; a < 7; a++) {
            cout << seats[r][a] << "  "; 
        };
        cout << endl; 
    };
}

double get_seat_price(int row, int aisle) {
    double row_cost[10] = {7.25, 8.00, 10.90, 10.90, 15.10, 15.10, 12.00, 9.85, 9.85, 7.00}; 
    return row_cost[row];
}


int all_menu(char theater[10][7]) { 
    int choice; 
    cout << "\nMenu\n1) Buy Ticket\n2) Total Sell and Exit\nEnter choice: ";
    cin >> choice; 

    if (choice == 1) {
        int row; 
        int aisle; 
        while (true) {
            cout << "Enter row: "; 
            cin >> row; 
            cout << "Enter aisle: ";
            cin >> aisle; 
            if (row < 0 or row > 9 or aisle < 0 or aisle > 6) {
                cout << "Invalid seat" << endl; 
                continue; 
            } else if (theater[row][aisle] == '#') {
                cout << "Invalid seat" << endl; 
                continue; 
            } else {
                theater[row][aisle] = '#'; 
                display_seats(theater);
                break; 
            }
        }
        all_menu(theater);
    } else if (choice == 2) {
        int tickets_total; 
        float total; 
        tickets_total = 0;
        total = 0.0;
        for(int r = 0; r < 10; r++) {
            for(int a = 0; a < 7; a++) {
                if (theater[r][a] == '#') {
                    total += get_seat_price(r, a); 
                    tickets_total++;
                }
            }
        }
        cout << "Total tickets sold: " << tickets_total << endl; 
        cout << "Total revenue: $" << fixed << setprecision(2) << total << endl; 
    } else {
        cout << "Invalid Menu Selection";
        all_menu(theater); 
    }
    return 0; 
}

int main() { 
    char theater[10][7]; 
    for(int r = 0; r < 10; r++) {
        for(int a = 0; a < 7; a++) {
            theater[r][a] = '*';
        }
    }
    display_seats(theater); 
    all_menu(theater); 
    return 0; 
}