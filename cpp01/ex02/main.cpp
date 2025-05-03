#include <iostream>
#include <string>

int main()
{

    std::string str = "HI THIS IS BRAIN";

    // create *pointer to str
    std::string* stringPTR = &str;

    // create: "REFerence" to str
    std::string& stringREF = str;

    // addr
    std::cout << "Address of str:        " << &str << std::endl;
    std::cout << "Address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Address held by REF:   " << &stringREF << std::endl;

    // val
    std::cout << "Value of str:          " << str << std::endl;
    std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
    std::cout << "Value referenced by REF: " << stringREF << std::endl;

    return 0;
}
