#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    try {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
        
        Array<int> numbers(5);
        std::cout << "Number array size: " << numbers.size() << std::endl;
        
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 2;
        }
        
        std::cout << "Numbers array contents: ";
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
        
        Array<int> copy(numbers);
        std::cout << "Copy array contents: ";
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        numbers[0] = 100;
        std::cout << "Original array after modification: " << numbers[0] << std::endl;
        std::cout << "Copy array unchanged: " << copy[0] << std::endl;
        
        Array<int> assigned = numbers;
        std::cout << "Assigned array contents: ";
        for (unsigned int i = 0; i < assigned.size(); i++) {
            std::cout << assigned[i] << " ";
        }
        std::cout << std::endl;
        
        try {
            numbers[numbers.size()] = 0;
        }
        catch (std::exception& e) {
            std::cout << "Exception caught: Out of bounds access" << std::endl;
        }
        
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "42";
        strings[2] = "World";
        
        std::cout << "String array contents: ";
        for (unsigned int i = 0; i < strings.size(); i++) {
            std::cout << strings[i] << " ";
        }
        std::cout << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception caught" << std::endl;
    }
    
    return 0;
}