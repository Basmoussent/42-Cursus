#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <climits>
#include <stdlib.h>


class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deque;
    
    // Vector sorting methods
    void mergeInsertSortVec(std::vector<int>& arr);
    void mergeVec(std::vector<int>& arr, int left, int mid, int right);
    void insertSortVec(std::vector<int>& arr, int left, int right);
    
    // Deque sorting methods
    void mergeInsertSortDeque(std::deque<int>& arr);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    void insertSortDeque(std::deque<int>& arr, int left, int right);
    
    // Helper methods
    bool isValidNumber(const std::string& str) const;
    void parseInput(int argc, char **argv);
    void displayResults(const std::vector<int>& vec, const std::deque<int>& deque,
                       double vecTime, double dequeTime) const;

public:
    PmergeMe();
    ~PmergeMe();
    
    void sort(int argc, char **argv);
};

#endif 