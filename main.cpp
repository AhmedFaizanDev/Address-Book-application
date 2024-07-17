// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
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

bool isValidEmail(const string& email) {
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

void addContact(vector<Contact>& contacts) {
    string name, phoneNumber, email;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter email: ";
    getline(cin, email);

    if (name.empty() || phoneNumber.empty() || email.empty() || !isValidEmail(email)) {
        cout << "Invalid input. Please try again." << endl;
    } else {
        contacts.emplace_back(name, phoneNumber, email);
        cout << "Contact added successfully!" << endl;
    }
}

void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void searchContact(const vector<Contact>& contacts) {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    bool found = false;
    for (const auto& contact : contacts) {
        string contactName = contact.getName();
        toLowerCase(contactName);
        if (contactName == name) {
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
