#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "Wrong Cat";
    //std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    //std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    //std::cout << "WrongCat assignment operator" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    //std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
} 