// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <fstream>
#include "Contact.h"

using namespace std;


bool compareByName(const Contact& a, const Contact& b) {
    return a.getName() < b.getName();
}

void sortContacts(vector<Contact>& contacts) {
    sort(contacts.begin(), contacts.end(), compareByName);
    cout << "Contacts sorted by name." << endl;
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
            case 7:
                sortContacts(contacts);
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
