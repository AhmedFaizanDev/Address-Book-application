// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include "Contact.h"

using namespace std;


void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    auto it = remove_if(contacts.begin(), contacts.end(), [&name](const Contact& contact) {
        string contactName = contact.getName();
        toLowerCase(contactName);
        return contactName == name;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        cout << "Contact deleted successfully!" << endl;
    } else {
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
                deleteContact(contacts);
                break;
            case 6:
                saveContactsToFile(contacts);
                cout << "Contacts saved to file. Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
