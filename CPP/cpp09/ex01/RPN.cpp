#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidToken(const std::string& token) const {
    if (isOperator(token))
        return true;
    
    if (token.length() != 1)
        return false;
    
    return token[0] >= '0' && token[0] <= '9';
}

void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2)
        throw std::runtime_error("Error: insufficient operands for operation");
    
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();
    
    if (op == "+")
        _stack.push(a + b);
    else if (op == "-")
        _stack.push(a - b);
    else if (op == "*")
        _stack.push(a * b);
    else if (op == "/") {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        _stack.push(a / b);
    }
}

int RPN::calculate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        if (!isValidToken(token))
            throw std::runtime_error("Error: invalid token");
        
        if (isOperator(token)) {
            performOperation(token);
        } else {
            _stack.push(token[0] - '0');
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return _stack.top();
} 