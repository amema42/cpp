#include "Data.hpp"

Data::Data() : _intNumber(0), _floatNumber(0.0f), _c('c'){}

Data::Data(int intNumber, float floatNumber, char c) : _intNumber(intNumber), _floatNumber(floatNumber), _c(c) {}

Data::~Data(){}

int Data::getIntNumber() const{
    return _intNumber;
}
float Data::getFloatNumber() const{
    return _floatNumber;
}
char Data::getChar() const{
    return _c;
}