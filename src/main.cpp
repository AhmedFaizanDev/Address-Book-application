#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Contact class definition
class Contact 
{
private:
    string name;
    string phoneNumber;
    string email;

public:
    // Constructor
    Contact(const string& name, const string& phoneNumber, const string& email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    
    void setName(const string& newName) { name = newName; }
    void setPhoneNumber(const string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const string& newEmail) { email = newEmail; }
};

//Functions
void displayMenu();
void toLowerCase(string& str);
void addContact(vector<Contact>& contacts);
void searchContact(const vector<Contact>& contacts);
void displayAllContacts(const vector<Contact>& contacts);
void updateContact(vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);
void saveContactsToFile(const vector<Contact>& contacts);
void loadContactsFromFile(vector<Contact>& contacts);
void sortContacts(vector<Contact>& contacts);
void countContacts(const vector<Contact>& contacts);

//Function to display menu 
void displayMenu() 
{
    cout << "\n===== Address Book Menu =====" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Display All Contacts" << endl;
    cout << "4. Update Contact" << endl;
    cout << "5. Delete Contact" << endl;
    cout << "6. Save Contacts to File" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

//Function to convert string to lowercase
void toLowerCase(string& str) 
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

//Function to add a new contact
void addContact(vector<Contact>& contacts) 
{
    string name, phoneNumber, email;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
    cout << "Enter email: ";
    getline(cin, email);

    contacts.emplace_back(name, phoneNumber, email);
    cout << "Contact added successfully!" << endl;
}

//Function to search for a contact by name
void searchContact(const vector<Contact>& contacts) 
{
    string name;
    cout << "Enter the name of the contact to search: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    bool found = false;
    for (const auto& contact : contacts) {
        string contactName = contact.getName();
        toLowerCase(contactName);
        if (contactName.find(name) != string::npos) 
        {
            cout << "Contact found:" << endl;
            cout << "Name: " << contact.getName() << endl;
            cout << "Phone Number: " << contact.getPhoneNumber() << endl;
            cout << "Email: " << contact.getEmail() << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact not found." << endl;
    }
}

//Function to display all contacts
void displayAllContacts(const vector<Contact>& contacts) 
{
    if (contacts.empty()) 
    {
        cout << "No contacts found." << endl;
        return;
    }

    cout << "\n===== All Contacts =====" << endl;
    for (const auto& contact : contacts) 
    {
        cout << "Name: " << contact.getName() << endl;
        cout << "Phone Number: " << contact.getPhoneNumber() << endl;
        cout << "Email: " << contact.getEmail() << endl;
        cout << "--------------------------" << endl;
    }
}

//Function to update existing contact
void updateContact(vector<Contact>& contacts) 
{
    string name;
    cout << "Enter the name of the contact to update: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    bool found = false;
    for (auto& contact : contacts) 
    {
        string contactName = contact.getName();
        toLowerCase(contactName);
        if (contactName == name) 
        {
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
            if (!newEmail.empty()) contact.setEmail(newEmail);

            cout << "Contact updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Contact not found." << endl;
    }
}

//Function to delete a contact
void deleteContact(vector<Contact>& contacts) 
{
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();
    getline(cin, name);
    toLowerCase(name);

    auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        string contactName = contact.getName();
        toLowerCase(contactName);
        return contactName == name;
    });

    if (it != contacts.end()) 
    {
        contacts.erase(it);
        cout << "Contact deleted successfully!" << endl;
    } else 
    {
        cout << "Contact not found." << endl;
    }
}

//Function to save contacts to a file
void saveContactsToFile(const vector<Contact>& contacts) 
{
    ofstream outFile("contacts.txt");
    for (const auto& contact : contacts) {
        outFile << contact.getName() << endl;
        outFile << contact.getPhoneNumber() << endl;
        outFile << contact.getEmail() << endl;
    }
    outFile.close();
    cout << "Contacts saved to file 'contacts.txt'." << endl;
}

//Function to load contacts from a file
void loadContactsFromFile(vector<Contact>& contacts) 
{
    ifstream inFile("contacts.txt");
    if (!inFile.is_open()) 
    {
        cout << "No contacts found." << endl;
        return;
    }

    string name, phoneNumber, email;
    while (getline(inFile, name) && getline(inFile, phoneNumber) && getline(inFile, email)) 
    {
        contacts.emplace_back(name, phoneNumber, email);
    }
    inFile.close();
    cout << "Contacts loaded from file 'contacts.txt'." << endl;
}

//Function to sort contacts alphabetically by name
void sortContacts(vector<Contact>& contacts) {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.getName() < b.getName();
    });
    cout << "Contacts sorted by name." << endl;
}

//Function to count total number of contacts
void countContacts(const vector<Contact>& contacts) 
{
    int count = contacts.size();
    cout << "Total contacts: " << count << endl;
}


int main() 
{
    vector<Contact> contacts;
    loadContactsFromFile(contacts); // Load contacts from file on startup

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
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);

}
