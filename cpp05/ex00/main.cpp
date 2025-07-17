#include "Bureaucrat.hpp"

int main() {
    // Case 1
    try {
        Bureaucrat a("Alice", 2);
        std::cout << "Created: " << a << std::endl;

        a.setGradeUp();    // 2 -> 1
        std::cout << "After promotion: " << a << std::endl;

        a.setGradeUp();    // 1 -> should throw
        std::cout << "After promotion: " << a << std::endl;
    } catch (std::exception& e) {
        std::cerr << "[Exception - Alice] " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Case 2
    try {
        Bureaucrat b("Bob", 151);  // invalid → throws
    } catch (std::exception& e) {
        std::cerr << "[Exception - Bob] " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Case 3
    try {
        Bureaucrat c("Clara", 0);  // invalid → throws
    } catch (std::exception& e) {
        std::cerr << "[Exception - Clara] " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Case 4
    try {
        Bureaucrat d("Dario", 149);
        std::cout << "Created: " << d << std::endl;

        d.setGradeDown(); // 149 → 150
        std::cout << "After demotion: " << d << std::endl;

        try {
            d.setGradeDown(); // 150 → 151 → should throw
            std::cout << "After demotion: " << d << std::endl;
        } catch (std::exception& e) {
            std::cerr << "[Inner Exception - Dario] " << e.what() << std::endl;
        }

        d.setGradeUp(); // 150 → 149
        std::cout << "After promotion: " << d << std::endl;

    } catch (std::exception& e) {
        std::cerr << "[Exception - Dario] " << e.what() << std::endl;
    }

    return 0;
}