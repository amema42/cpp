#include "PmergeMe.hpp"
#include <iostream>

void debug_jacobsthal(size_t m) {
    PMerge p;
    std::vector<size_t> order = p.buildJacobsthalOrder(m);
    std::cout << "buildJacobsthalOrder(" << m << ") = [";
    for (size_t i = 0; i < order.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << order[i];
    }
    std::cout << "]" << std::endl;
}

int main() {
    for (size_t i = 2; i <= 10; ++i) {
        debug_jacobsthal(i);
    }
    return 0;
}
