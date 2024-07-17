#pragma once

#include <string>
using namespace std;

class Contact 
{
private:
    string name;
    string phoneNumber;
    string email;

public:
    Contact(const string& name, const string& phoneNumber, const string& email)
        : name(name), phoneNumber(phoneNumber), email(email) {}

    string getName() const 
    {
        return name;
    }

    string getPhoneNumber() const 
    {
        return phoneNumber;
    }

    string getEmail() const 
    {
        return email;
    }
};
