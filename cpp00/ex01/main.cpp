#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static bool promptNonEmpty(const std::string& prompt, std::string& out) {
    std::cout << prompt;
    if (!std::getline(std::cin, out) || out.empty()) {
        std::cout << "Field cannot be empty. Aborting.\n";
        return false;
    }
    return true;
}

int main() {
    PhoneBook pb;
    std::string cmd;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd)) break;

        if (cmd == "ADD") {
            Contact c;
            std::string tmp;
            if (!promptNonEmpty("First Name: ", tmp))    continue;
            c.setFirstName(tmp);
            if (!promptNonEmpty("Last Name: ", tmp))     continue;
            c.setLastName(tmp);
            if (!promptNonEmpty("Nickname: ", tmp))      continue;
            c.setNickname(tmp);
            if (!promptNonEmpty("Phone Number: ", tmp))  continue;
            c.setPhoneNumber(tmp);
            if (!promptNonEmpty("Darkest Secret: ", tmp))continue;
            c.setDarkestSecret(tmp);

            pb.addContact(c);
        }
        else if (cmd == "SEARCH") {
            if (pb.getTotalContacts() == 0) {
                std::cout << "PhoneBook is empty.\n";
                continue;
            }
            pb.displayContacts();
            std::cout << "Enter index: ";
            std::string idxs; std::getline(std::cin, idxs);
            int idx = -1;
            try { idx = std::stoi(idxs); }
            catch (...) { std::cout << "Invalid index.\n"; continue; }
            pb.displayContactDetails(idx);
        }
        else if (cmd == "EXIT") {
            break;
        }
    }
    return 0;
}
