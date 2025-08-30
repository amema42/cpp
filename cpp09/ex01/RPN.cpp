#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _operandStack(other._operandStack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _operandStack = other._operandStack;
    }
    return *this;
}

void RPN::clearStack() {
    while (!_operandStack.empty()) {
        _operandStack.pop();
    }
}

bool RPN::isOperator(const std::string& token) const {
    return (token.length() == 1 && 
            (token[0] == '+' || 
             token[0] == '-' || 
             token[0] == '*' || 
             token[0] == '/'));
}

bool RPN::isValidNumber(const std::string& token) const {
    if (token.length() != 1)
        return false;
    
    char c = token[0];
    return (c >= '0' && c <= '9');
}

int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

void RPN::processToken(const std::string& token) {
    // push valid single-digit numbers
    if (isValidNumber(token)) {
        int num = token[0] - '0';  // char -> int
        _operandStack.push(num);
        return;
    }
    
    if (isOperator(token)) {
        if (_operandStack.size() < 2) {
            throw std::runtime_error("Error: insufficient operands");
        }
        
        // pop in correct order: b=top, a=second
        int b = _operandStack.top();
        _operandStack.pop();
        int a = _operandStack.top();
        _operandStack.pop();
        
        int result = performOperation(a, b, token[0]);
        _operandStack.push(result);
        return;
    }
    
    throw std::runtime_error("Error");
}

// calculate RPN expression
int RPN::calculate(const std::string& expression) {
    clearStack();
    
    if (expression.empty()) {
        throw std::runtime_error("Error: empty expression");
    }
    
    // tokenize input stream
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        try {
            processToken(token);
        } catch (const std::exception& e) {
            clearStack();
            throw;
        }
    }
    
    if (_operandStack.size() != 1) {
        clearStack();
        throw std::runtime_error("Error: invalid expression");
    }
    
    int result = _operandStack.top();
    _operandStack.pop();
    return result;
}