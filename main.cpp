// Contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;

public:
    // Constructor
    Contact(string name, string phoneNumber, string email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    // Getters
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }

    // Setters
    void setName(const string& name) { this->name = name; }
    void setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }
    void setEmail(const string& email) { this->email = email; }
};

#endif
