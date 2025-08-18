#include <iostream>
using namespace std;

// Global variables for items
int coffee_v = 0, brownies_v = 0, sandwich_v = 0;

// Menu Class
class menu {
public:
    void menu_method() {
        cout << "\n\n\n\n";
        cout << "\t\t\t\tWelcome to Coffee Land ☕🍰🥪" << endl;
        cout << "\t\t\t\tHere is our menu:\n";
        cout << "\t\t\t\t1. Coffee   - Rs. 250\n";
        cout << "\t\t\t\t2. Brownies - Rs. 200\n";
        cout << "\t\t\t\t3. Sandwich - Rs. 100\n";
        cout << "\t\t\t\t4. Done Ordering\n";

        int choice, qty;
        do {
            cout << "\n\t\t\t\tEnter item number (1-4): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\t\t\t\tEnter quantity of Coffee: ";
                    cin >> qty;
                    coffee_v += qty * 250;
                    break;
                case 2:
                    cout << "\t\t\t\tEnter quantity of Brownies: ";
                    cin >> qty;
                    brownies_v += qty * 200;
                    break;
                case 3:
                    cout << "\t\t\t\tEnter quantity of Sandwich: ";
                    cin >> qty;
                    sandwich_v += qty * 100;
                    break;
                case 4:
                    cout << "\t\t\t\tFinalizing your order...\n";
                    break;
                default:
                    cout << "\t\t\t\tInvalid choice, try again.\n";
            }
        } while (choice != 4);
    }
};

// Billing Class
class billing {
private:
    int bill, total;

public:
    void bill_method() {
        bill = coffee_v + brownies_v + sandwich_v;
        cout << "\n\n\n\n";
        cout << "\t\t\t\tYour Total Bill Is Rs. " << bill << endl;

        int money;
        cout << "\t\t\t\tPlease enter the money you want to pay: ";
        cin >> money;

        while (money < bill) {
            cout << "\n\t\t\t\tInsufficient funds!" << endl;
            cout << "\t\t\t\t1. Add more money" << endl;
            cout << "\t\t\t\t2. Reduce items (restart order)" << endl;
            cout << "\t\t\t\tChoose option: ";
            int option;
            cin >> option;

            if (option == 1) {
                int extra;
                cout << "\t\t\t\tEnter additional money: ";
                cin >> extra;
                money += extra;
            } 
            else if (option == 2) {
                cout << "\n\t\t\t\tRestarting order... Please run the program again." << endl;
                exit(0);
            } 
            else {
                cout << "\t\t\t\tInvalid choice, try again." << endl;
            }
        }

        total = money - bill;
        cout << "\t\t\t\tPayment successful!" << endl;
        cout << "\t\t\t\tYour Returning Amount Is Rs. " << total << endl << endl;
        cout << "\t\t\t\t------Thanks For Visiting Coffee Land------" << endl;
    }
};

// Main
int main() {
    menu m1;
    billing b1;

    m1.menu_method();
    b1.bill_method();

    return 0;
}
