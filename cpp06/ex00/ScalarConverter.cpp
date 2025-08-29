#include "ScalarConverter.hpp"
#include <iomanip> // std::setprecision

ScalarConverter::ScalarConverter() { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() { }

bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string& literal){
    if (literal.empty())
        return false;
    
    size_t flag = 0;
    if (literal[0] == '+' || literal[0] == '-')
        flag = 1;
    if (flag >= literal.length())
        return false;
    
    for (size_t i = flag; i < literal.length(); i++){
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

// 25.5f
bool ScalarConverter::isFloat(const std::string& literal)
{
    // cannot use .back() in c++98
    if (literal.empty() || literal[literal.size() - 1] != 'f')
        return false;
    
    // Controlla casi speciali
    std::string floatPart = literal.substr(0, literal.length() - 1);
    if (floatPart == "-inf" || floatPart == "+inf" || floatPart == "inf" || floatPart == "nan")
        return true;

    size_t flag = 0;
    if (floatPart[0] == '+' || floatPart[0] == '-')
        flag = 1;
    
    if (flag >= floatPart.length())
        return false;
    
    size_t dotCount = 0;
    //size_t dotPos = std::string::npos;
    
    for (size_t i = flag; i < floatPart.length(); i++) {
        if (floatPart[i] == '.') {
            dotCount++;
            //dotPos = i;
        }
        else if (!std::isdigit(floatPart[i]))
            return false;
    }

    //return dotCount == 1 && dotPos > flag && dotPos < floatPart.length() - 1;
    // "0.f" is valid - floatPart = "0." -> dotPos = 1 -> length() = 2 
    //->  1 != 2-1 -> 1 != 1 -> false 
    return (dotCount == 1); 
}

bool ScalarConverter::isDouble(const std::string& literal){
    if (literal.empty())
        return false;
    
    //special cases:
    if (literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan")
        return true;
    
    size_t dotPos = literal.find('.');
    if (dotPos == std::string::npos)
        return false;
    
    size_t flag = 0;
    if (literal[0] == '+' || literal[0] == '-')
        flag = 1;

    // check: digits before dot
    if (dotPos <= flag)
        return false;
    
    // check: digits after dot
    if (dotPos >= literal.length() - 1)
        return false;

    for (size_t i = flag; i < dotPos; i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }

    for (size_t i = dotPos + 1; i < literal.length(); i++) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

void ScalarConverter::convertFromChar(char c){
    double value = static_cast<double>(c);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
void ScalarConverter::convertFromInt(int val){
    double doubleValue = static_cast<double>(val);
    printChar(doubleValue);
    printInt(doubleValue);
    printFloat(doubleValue);
    printDouble(doubleValue);
}
void ScalarConverter::convertFromFloat(float val){
    double doubleValue = static_cast<double>(val);
    printChar(doubleValue);
    printInt(doubleValue);
    printFloat(doubleValue);
    printDouble(doubleValue);
}
void ScalarConverter::convertFromDouble(double val){
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}


// print

void ScalarConverter::printChar(double val)
{
    if (std::isnan(val) || std::isinf(val))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (val < 0 || val > 127)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (val < 32 || val == 127)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double val)
{
    if (std::isnan(val) || std::isinf(val)){
        std::cout << "int: impossible" << std::endl;
    }
    else if (val < INT_MIN || val > INT_MAX){
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    }
}

void ScalarConverter::printFloat(double val)
{
    if (std::isnan(val)) {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(val)) {
        std::cout << "float: " << (val > 0 ? "+inff" : "-inff") << std::endl;
    }
    else {
        float f = static_cast<float>(val);
        std::cout << "float: " 
                  << std::fixed << std::setprecision(1) << f << "f" 
                  << std::endl;
    }
}

void ScalarConverter::printDouble(double val)
{
    if (std::isnan(val)) {
        std::cout << "double: nan" << std::endl;
    }
    else if (std::isinf(val)) {
        std::cout << "double: " << (val > 0 ? "+inf" : "-inf") << std::endl;
    }
    else {
        std::cout << "double: " 
                  << std::fixed << std::setprecision(1) << val 
                  << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    // Casi speciali per double
    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
    {
        double value;
        if (literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "inf")
            value = std::numeric_limits<double>::infinity();
        else // -inf
            value = -std::numeric_limits<double>::infinity();
        convertFromDouble(value);
        return;
    }
    
    // Casi speciali per float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
    {
        float value;
        if (literal == "nanf")
            value = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff" || literal == "inff")
            value = std::numeric_limits<float>::infinity();
        else // -inff
            value = -std::numeric_limits<float>::infinity();
        convertFromFloat(value);
        return;
    }
    
    if (isChar(literal))
    {
        char c = literal[1];
        convertFromChar(c);
    }
    else if (isInt(literal))
    {
        errno = 0;  // reset errno before strtol
        long long_value = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || long_value < INT_MIN || long_value > INT_MAX)
        {
            // if it's an overflow && (but) could be a valid double -> try converting it as a double
            double double_value = std::strtod(literal.c_str(), NULL);
            if (errno != ERANGE && !std::isnan(double_value) && !std::isinf(double_value))
            {
                convertFromDouble(double_value);
            }
            else
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
        }
        else
        {
            convertFromInt(static_cast<int>(long_value));
        }
    }
    else if (isFloat(literal))
    {
        std::string without_f = literal.substr(0, literal.length() - 1);
        float float_value = std::strtof(without_f.c_str(), NULL);
        convertFromFloat(float_value);
    }
    else if (isDouble(literal))
    {
        double double_value = std::strtod(literal.c_str(), NULL);
        convertFromDouble(double_value);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}