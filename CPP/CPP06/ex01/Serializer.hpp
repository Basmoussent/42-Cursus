#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stddef.h>
#include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();
public:
    static size_t serialize(Data* ptr);
    static Data* deserialize(size_t raw);
};

#endif 