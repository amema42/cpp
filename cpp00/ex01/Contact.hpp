#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();

    // Setters: assign values to private members
    void setFirstName(const std::string& fn);
    void setLastName(const std::string& ln);
    void setNickname(const std::string& nn);
    void setPhoneNumber(const std::string& pn);
    void setDarkestSecret(const std::string& ds);

    // Getters: return the values of private members
    std::string getFirstName()    const;
    std::string getLastName()     const;
    std::string getNickname()     const;
    std::string getPhoneNumber()  const;
    std::string getDarkestSecret()const;
};

#endif
