#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.number = 42;
    data.text = "Hello, world!";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data: number = " << data.number << ", text = '" << data.text << "'" << std::endl;

    size_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data address: " << ptr << std::endl;
    std::cout << "Deserialized Data: number = " << ptr->number << ", text = '" << ptr->text << "'" << std::endl;

    if (ptr == &data)
        std::cout << "Success: Pointers are equal." << std::endl;
    else
        std::cout << "Error: Pointers are NOT equal!" << std::endl;

    return 0;
} 