#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void testVector() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);

    try {
        // first 20
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it
                  << " at index " << (it - v.begin()) << std::endl; // random access OKay
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        easyfind(v, 99); // not found ?
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    const std::vector<int> cv(1, 42);
    try {
        std::vector<int>::const_iterator it2 = easyfind(cv, 42);
        std::cout << "Found in const vector: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Const vector: " << e.what() << std::endl;
    }
}

static void testList() {
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(1);
    lst.push_back(9);

    try {
        std::list<int>::iterator it = easyfind(lst, 1);
        std::cout << "Found in list: " << *it << std::endl;
        // NOTE: can't print the index on list
        
    } catch (const std::exception& e) {
        std::cout << "List: " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    testList();
    return 0;
}
