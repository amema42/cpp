#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cerrno>

class ScalarConverter{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // private: mothods to 'identify type'
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    //static bool isPseudoLiteral(std::string& literal);

    //private: convertions
    static void convertFromChar(char c);
    static void convertFromInt(int val);
    static void convertFromFloat(float val);
    static void convertFromDouble(double val);
    static void handleFromPseudoLiteral(const std::string& literal);

    //print
    static void printChar(double val);
    static void printInt(double val);
    static void printFloat(double val);
    static void printDouble(double val);



public:
    static void convert(const std::string& literal);
    
};

#endif