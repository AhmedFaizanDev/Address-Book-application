#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Simple Address Book" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Display All Contacts" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Add Contact selected" << endl;
                break;
            case 2:
                cout << "Search Contact selected" << endl;
                break;
            case 3:
                cout << "Display All Contacts selected" << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
