#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (numbers.size() >= N)
        throw std::runtime_error("Span is full");
    numbers.push_back(num);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() <= 1)
        throw std::runtime_error("Not enough numbers to find span");

    std::vector<int>::const_iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator max = std::max_element(numbers.begin(), numbers.end());
    return static_cast<unsigned int>(*max - *min);
}