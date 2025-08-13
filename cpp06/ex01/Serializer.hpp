#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
//#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer operator=(const Serializer& other);
    ~Serializer();

public:

    // pointer -> int
    static uintptr_t serialize(Data* ptr);

    // int -> pointer
    static Data* deserialize(uintptr_t raw);

};

#endif