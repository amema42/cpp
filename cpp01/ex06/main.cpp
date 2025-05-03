#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <LEVEL>\n";
        return 1;
    }

    std::string level = argv[1];
    Harl harl;

    // map log level to index
    int idx = -1;
    if (level == "DEBUG")   idx = 0;
    else if (level == "INFO")    idx = 1;
    else if (level == "WARNING") idx = 2;
    else if (level == "ERROR")   idx = 3;

    switch (idx) {
        case 0:
            harl.complain("DEBUG");
            // fallthrough
        case 1:
            harl.complain("INFO");
            // fallthrough
        case 2:
            harl.complain("WARNING");
            // fallthrough
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }

    return 0;
}