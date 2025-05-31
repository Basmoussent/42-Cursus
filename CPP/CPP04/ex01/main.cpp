#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int arraySize = 100;
    Animal* animals[arraySize];

    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog originalDog;
    Dog copyDog = originalDog;
    Dog assignedDog;
    assignedDog = originalDog;

    std::cout << "\n=== Cleaning up animals ===" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    return 0;
} 