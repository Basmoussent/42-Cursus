#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (numbers.size() + std::distance(begin, end) > N)
            throw std::runtime_error("Adding range would exceed capacity");
        numbers.insert(numbers.end(), begin, end);
    }
};

#endif