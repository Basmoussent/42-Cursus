#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        PmergeMe sorter;
        sorter.sort(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
} 