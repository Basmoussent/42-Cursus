#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    try {
        // Test with vector
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 2); // [0, 2, 4, 6, 8]
        
        std::cout << "Testing vector:" << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Found value 4 at position: " << std::distance(vec.begin(), it) << std::endl;
        
        // Test with list
        std::list<int> lst;
        for (int i = 0; i < 5; ++i)
            lst.push_back(i); // [0, 1, 2, 3, 4]
            
        std::cout << "\nTesting list:" << std::endl;
        std::list<int>::iterator lst_it = easyfind(lst, 3);
        std::cout << "Found value 3 at position: " << std::distance(lst.begin(), lst_it) << std::endl;
        
        // Test with deque
        std::deque<int> deq;
        for (int i = 0; i < 3; ++i)
            deq.push_back(i * 3); // [0, 3, 6]
            
        std::cout << "\nTesting deque:" << std::endl;
        std::deque<int>::iterator deq_it = easyfind(deq, 6);
        std::cout << "Found value 6 at position: " << std::distance(deq.begin(), deq_it) << std::endl;
        
        // Test not found case
        std::cout << "\nTesting value not found:" << std::endl;
        easyfind(vec, 99); // This should throw
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}