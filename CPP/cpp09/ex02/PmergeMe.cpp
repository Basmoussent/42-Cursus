#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) const {
    if (str.empty() || (str[0] == '-' && str.length() == 1))
        return false;
    
    size_t i = 0;
    if (str[0] == '-')
        i = 1;
    
    for (; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    
    long num = std::atol(str.c_str());
    return num >= 0 && num <= INT_MAX;
}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!isValidNumber(argv[i]))
            throw std::runtime_error("Error: invalid input");
        
        int num = std::atoi(argv[i]);
        _vec.push_back(num);
        _deque.push_back(num);
    }
}

void PmergeMe::insertSortVec(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVec(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertSortVec(std::vector<int>& arr) {
    int n = arr.size();    
    for (int size = 1; size < n; size = size * 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            mergeVec(arr, left, mid, right);
        }
    }
}

void PmergeMe::insertSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::deque<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    int n = arr.size();
    
    for (int size = 1; size < n; size = size * 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            mergeDeque(arr, left, mid, right);
        }
    }
}

void PmergeMe::displayResults(const std::vector<int>& vec, const std::deque<int>& deque,
                            double vecTime, double dequeTime) const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i];
        if (i < _vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << vecTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << deque.size() 
              << " elements with std::deque : " << std::fixed 
              << std::setprecision(5) << dequeTime << " us" << std::endl;
}

void PmergeMe::sort(int argc, char **argv) {
    if (argc < 2)
        throw std::runtime_error("Error: no input provided");
    
    parseInput(argc, argv);
    
    std::vector<int> vecCopy = _vec;
    clock_t start = clock();
    mergeInsertSortVec(vecCopy);
    clock_t end = clock();
    double vecTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::deque<int> dequeCopy = _deque;
    start = clock();
    mergeInsertSortDeque(dequeCopy);
    end = clock();
    double dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
    displayResults(vecCopy, dequeCopy, vecTime, dequeTime);
}