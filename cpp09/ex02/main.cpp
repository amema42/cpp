#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    PMerge sorter;
    if (!sorter.loadArgs(argc, argv)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    sorter.run();
    sorter.show();
    return 0;
}
