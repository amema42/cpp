#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data d(42, 3.14f, 'A');
    Data* p = &d;

    std::cout << "original pointer:     " << p << std::endl;

    uintptr_t raw = Serializer::serialize(p);
    std::cout << "serialized (uintptr): " << raw << std::endl;

    Data* back = Serializer::deserialize(raw);
    std::cout << "deserialized pointer: " << back << std::endl;

    std::cout << "same pointer? " << std::endl;
    if (back == p)
        std::cout << "yes\n" << std::endl;
    else
        std::cout << "no\n" << std::endl;

    std::cout << "data values -> int: "   << back->getIntNumber()
              << ", float: "               << back->getFloatNumber()
              << ", char: '"               << back->getChar() << "'" << std::endl;

    return 0;
}
