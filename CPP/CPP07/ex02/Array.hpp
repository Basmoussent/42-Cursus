#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template<typename T>

class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}
    
    Array(unsigned int n) : _size(n) {
        _array = new T[n]();
    }
    
    Array(const Array& other) : _size(other._size) {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    
    ~Array() {
        delete[] _array;
    }
    
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return *this;
    }
    
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }
    
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }
    
    unsigned int size() const {
        return _size;
    }
};

#endif