#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created!\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copied!\n";
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) { /* Assign operator: brain1 = brain2 */
    std::cout << "Brain assigned!\n";
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed!\n";
}

void Brain::setIdea(int index, const std::string& idea) { /*SET (index, idea)*/
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const { /*GET*/
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}