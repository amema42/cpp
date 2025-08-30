#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _operandStack;
    
    bool isOperator(const std::string& token) const;
    bool isValidNumber(const std::string& token) const;
    int performOperation(int a, int b, char op) const;
    void processToken(const std::string& token);
    void clearStack();
    
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    
    int calculate(const std::string& expression);
};

#endif