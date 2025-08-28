#include <iostream>
#include <string>
#include "whatever.hpp"

int main() {
    int v1 = 2, v2 = 2;
    ::swap(v1, v2);
    std::cout << "value 1: " << v1 << ", value 2: " << v2 << "\n";
    std::cout << "min(v1, v2): " << ::min(v1, v2) << "\n";
    std::cout << "max(v1, v2): " << ::max(v1, v2) << "\n";

    std::string x = "string1";
    std::string y = "string1";
    ::swap(x, y);
    std::cout << "string1: " << x << ", string2: " << y << "\n";
    std::cout << "min(x, y): " << ::min(x, y) << "\n";
    std::cout << "max(x, y): " << ::max(x, y) << "\n";
}
