#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }

size_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<size_t>(ptr);
}

Data* Serializer::deserialize(size_t raw) {
    return reinterpret_cast<Data*>(raw);
} 