// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include "Contact.h"

using namespace std;

void updateContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to update: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    bool found = false;
    for (auto& contact : contacts) {
        string contactName = contact.getName();
        toLowerCase(contactName);
        if (contactName == name) {
            cout << "Contact found. Enter new details." << endl;
            cout << "Enter new name (leave blank to keep current): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) contact.setName(newName);

            cout << "Enter new phone number (leave blank to keep current): ";
            string newPhoneNumber;
            getline(cin, newPhoneNumber);
            if (!newPhoneNumber.empty()) contact.setPhoneNumber(newPhoneNumber);

            cout << "Enter new email (leave blank to keep current): ";
            string newEmail;
            getline(cin, newEmail);
            if (!newEmail.empty() && isValidEmail(newEmail)) {
                contact.setEmail(newEmail);
            } else if (!newEmail.empty()) {
                cout << "Invalid email. Keeping current email." << endl;
            }

            cout << "Contact updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

int main() {
    vector<Contact> contacts;
    loadContactsFromFile(contacts);

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
                updateContact(contacts);
                break;
            case 5:
                saveContactsToFile(contacts);
                cout << "Contacts saved to file. Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

