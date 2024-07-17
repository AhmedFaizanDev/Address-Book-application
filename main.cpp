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

void searchContact(const vector<Contact>& contacts) {
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getName() == name) {
            cout << "Contact found:" << endl;
            cout << "Name: " << contact.getName() << endl;
            cout << "Phone Number: " << contact.getPhoneNumber() << endl;
            cout << "Email: " << contact.getEmail() << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void displayAllContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display." << endl;
    } else {
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.getName() << endl;
            cout << "Phone Number: " << contact.getPhoneNumber() << endl;
            cout << "Email: " << contact.getEmail() << endl;
            cout << "-------------------------" << endl;
        }
    }
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
                searchContact(contacts);
                break;
            case 3:
                displayAllContacts(contacts);
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
