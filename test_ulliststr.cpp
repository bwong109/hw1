#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main() {

    // Test Case 1: Check if the list is initially empty
    ULListStr list1;
    if (list1.empty()) {
        std::cout << "Test Case 1 Passed" << std::endl;
    } else {
        std::cout << "Test Case 1 Failed" << std::endl;
    }

    if (list1.size() == 0) {
        std::cout << "Test Case 1 Passed" << std::endl;
    } else {
        std::cout << "Test Case 1 Failed" << std::endl;
    }

    // Test Case 2: Push back elements and check size
    list1.push_back("Hi");
    list1.push_back("I'm");
    list1.push_back("Brandon");
    if (!list1.empty()) {
        std::cout << "Test Case 2 Passed" << std::endl;
    } else {
        std::cout << "Test Case 2 Failed" << std::endl;
    }

    if (list1.size() == 3) {
        std::cout << "Test Case 2 Passed" << std::endl;
    } else {
        std::cout << "Test Case 2 Failed" << std::endl;
    }

    // Test Case 3: Check back() and front() after push back
    if (list1.back() == "C") {
        std::cout << "Test Case 3 Passed" << std::endl;
    } else {
        std::cout << "Test Case 3 Failed" << std::endl;
    }

    if (list1.front() == "A") {
        std::cout << "Test Case 3 Passed" << std::endl;
    } else {
        std::cout << "Test Case 3 Failed" << std::endl;
    }

    // Test Case 4: Push front elements and check size
    list1.push_front("X");
    list1.push_front("Y");
    if (list1.size() == 5) {
        std::cout << "Test Case 4 Passed" << std::endl;
    } else {
        std::cout << "Test Case 4 Failed" << std::endl;
    }

    // Test Case 5: Check back() and front() after push front
    if (list1.back() == "C") {
        std::cout << "Test Case 5 Passed" << std::endl;
    } else {
        std::cout << "Test Case 5 Failed" << std::endl;
    }

    if (list1.front() == "Y") {
        std::cout << "Test Case 5 Passed" << std::endl;
    } else {
        std::cout << "Test Case 5 Failed" << std::endl;
    }

    // Test Case 6: Pop back and check size
    list1.pop_back();
    if (list1.size() == 4) {
        std::cout << "Test Case 6 Passed" << std::endl;
    } else {
        std::cout << "Test Case 6 Failed" << std::endl;
    }

    return 0;
}
