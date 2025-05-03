#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];  // static array, max 8 contacts; 8 CONTACTS
    int nextIndex;        // index to write the next contact
    int totalContacts;    // number of contacts actually added

public:
    PhoneBook();
    ~PhoneBook();

    void addContact(const Contact& c);
    void displayContacts() const;
    bool displayContactDetails(int idx) const;
    int  getTotalContacts() const;
};

#endif