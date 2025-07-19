
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "CASE 1: successful signature" << std::endl;
    try {
        Bureaucrat alice("Alice", 10);               // grado alto
        std::cout << "Bureaucrat: " << alice.getName() << " created with GRADE: " << alice.getGrade()<<std::endl;  
        Form formA("Alice's Form", 20, 50);         // richiede 20 per firmare

        std::cout << formA << std::endl;
        alice.signForm(formA);                       // dovrebbe riuscire
        std::cout << formA << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "CASE 2: signature failure 2 to low grade" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);                  // grado basso
        std::cout << "Bureaucrat: " << bob.getName() << " created with GRADE: " << bob.getGrade()<<std::endl;  

        Form formB("Bob's Form", 50, 50);          // richiede 50

        std::cout << formB << std::endl;
        bob.signForm(formB);                         // dovrebbe fallire
        std::cout << formB << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "CASE3: invalid Form creation" << std::endl;
    try {
        std::cout << "Creating an InvalidForm with: gradeToSign=0 and gradeToExecute=160 (Both grades: invalid)" << std::endl;
        Form formC("InvalidForm", 0, 160); // Invalid grades → throws on construction
    } catch (std::exception& e) { 
        std::cerr << "Exception during creation: " << e.what() << std::endl;
    }
    return 0;
}
