#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Animal, Dog, and Cat ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nTesting getType():" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << meta->getType() << std::endl;

    std::cout << "\nTesting makeSound():" << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Testing WrongAnimal and WrongCat ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << "\nTesting WrongCat makeSound():" << std::endl;
    wrong_cat->makeSound();
    wrong_meta->makeSound();

    delete wrong_meta;
    delete wrong_cat;

    std::cout << "\n=== Testing copy constructors and assignments ===" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    return 0;
} 