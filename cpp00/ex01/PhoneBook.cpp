#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

// Constructor / Destructor
PhoneBook::PhoneBook(): nextIndex(0), totalContacts(0) {}
PhoneBook::~PhoneBook() {}

// Adds (or overwrites) a contact
void PhoneBook::addContact(const Contact& c) {
    contacts[nextIndex] = c;
    nextIndex = (nextIndex + 1) % 8;
    if (totalContacts < 8)
        ++totalContacts;
}

// Returns the number of saved contacts
int PhoneBook::getTotalContacts() const {
    return totalContacts;
}

// Utility function to "format" (width=10, right-aligned, truncates with '.')
static std::string formatField(const std::string& str) {
    if (str.length() <= 10)
        return std::string(10 - str.length(), ' ') + str;
    return str.substr(0,9) + ".";
}

// Displays the contact table
void PhoneBook::displayContacts() const {
    std::cout
        << std::setw(10) << "Index" << '|'
        << std::setw(10) << "First Name" << '|'
        << std::setw(10) << "Last Name"  << '|'
        << std::setw(10) << "Nickname"   << '\n';

    for (int i = 0; i < totalContacts; ++i) {
        std::cout
            << std::setw(10) << i        << '|'
            << formatField(contacts[i].getFirstName())   << '|'
            << formatField(contacts[i].getLastName())    << '|'
            << formatField(contacts[i].getNickname())    << '\n';
    }
}

// Displays details of a single contact; returns false if invalid index
bool PhoneBook::displayContactDetails(int idx) const {
    if (idx < 0 || idx >= totalContacts) {
        std::cout << "Invalid index.\n";
        return false;
    }
    const Contact& c = contacts[idx];
    std::cout
        << "First Name: "    << c.getFirstName()    << '\n'
        << "Last Name: "     << c.getLastName()     << '\n'
        << "Nickname: "      << c.getNickname()     << '\n'
        << "Phone Number: "  << c.getPhoneNumber()  << '\n'
        << "Darkest Secret: "<< c.getDarkestSecret()<< '\n';
    return true;
}
