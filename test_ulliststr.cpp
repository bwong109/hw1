#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[]) {
    // Test case for pushing front elements
    ULListStr list;
    for (int i = 0; i < 20; i++){
        list.push_front("L");
    }
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "Array Size: " << ARRSIZE << std::endl;

    // Print elements
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list.get(i);
        if (i < list.size()) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
    std::cout << "it got to here at least!" << std::endl;

    return 0;
}
