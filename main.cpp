// main.cpp
#include <iostream>
#include <vector>
#include "Contact.h"

using namespace std;

void displayMenu() {
    cout << "Simple Address Book" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Display All Contacts" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

void addContact(vector<Contact>& contacts) {
    string name, phoneNumber, email;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cout << "Enter email: ";
    cin >> email;
    contacts.emplace_back(name, phoneNumber, email);
    cout << "Contact added successfully!" << endl;
}

int main() {
    vector<Contact> contacts;
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
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
