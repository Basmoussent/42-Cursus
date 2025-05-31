#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>

void testBasicFunctionality() {
    std::cout << "=== Basic Functionality Test ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testLargeNumbers() {
    std::cout << "\n=== Large Numbers Test (10000 elements) ===" << std::endl;
    Span sp = Span(10000);
    std::srand(std::time(NULL));
    
    // Using addRange with a list of random numbers
    std::list<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(std::rand());
    }
    sp.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions() {
    std::cout << "\n=== Exception Tests ===" << std::endl;
    Span sp = Span(1);
    
    try {
        std::cout << "Testing span with no numbers:" << std::endl;
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    sp.addNumber(5);
    
    try {
        std::cout << "Testing adding to full span:" << std::endl;
        sp.addNumber(10);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    testBasicFunctionality();
    testLargeNumbers();
    testExceptions();
    return 0;
}