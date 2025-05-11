#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token) const;
    void performOperation(const std::string& op);
    bool isValidToken(const std::string& token) const;

public:
    RPN();
    ~RPN();
    
    int calculate(const std::string& expression);
};

#endif 