#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[]) {

    ULListStr list;

    // Test push_back and back
    list.push_back("I");
    std::cout << "Size after push_back: " << list.size() << std::endl;
    std::cout << "Back after push_back: " << list.back() << std::endl;

    list.push_back("Hope");
    std::cout << "Size after push_back: " << list.size() << std::endl;
    std::cout << "Back after push_back: " << list.back() << std::endl;

    // Test push_front and front
    list.push_front("This");
    std::cout << "Size after push_front: " << list.size() << std::endl;
    std::cout << "Front after push_front: " << list.front() << std::endl;

    list.push_front("Works");
    std::cout << "Size after push_front: " << list.size() << std::endl;
    std::cout << "Front after push_front: " << list.front() << std::endl;

    // Test pop_back and back
    list.pop_back();
    std::cout << "Size after pop_back: " << list.size() << std::endl;
    std::cout << "Back after pop_back: " << list.back() << std::endl;

    // Test pop_front and front
    list.pop_front();
    std::cout << "Size after pop_front: " << list.size() << std::endl;
    std::cout << "Front after pop_front: " << list.front() << std::endl;

    // Test get/getValAtLoc
    list.push_back("Please");
    list.push_front("Work");
    std::cout << "Value at index 1: " << list.get(1) << std::endl;

    // Clear the list
    list.clear();

    return 0;
}
