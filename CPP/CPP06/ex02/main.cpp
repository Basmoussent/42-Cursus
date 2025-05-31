#include "identify.hpp"
#include <iostream>

int main() {
    // Test with pointer
    std::cout << "Testing with pointer:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        std::cout << "Generated object type: ";
        identify(ptr);
        delete ptr;
    }

    // Test with reference
    std::cout << "\nTesting with reference:" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        std::cout << "Generated object type: ";
        identify(*ptr);
        delete ptr;
    }

    return 0;
} 