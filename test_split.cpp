/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

// Function to print out list
void printList(Node* list)
{
    while (list)
    {
        std::cout << list->value << " ";
        list = list->next;
    }
}

// Function to delete a linked list
void deleteList(Node*& list)
{
    while (list)
    {
        Node* temp = list;
        list = list->next;
        delete temp;
    }
}

int main(int argc, char* argv[])
{
    // Test Case 1: Empty List
    Node* emptyList = nullptr;
    Node* evens1 = nullptr;
    Node* odds1 = nullptr;
    split(emptyList, odds1, evens1);
    std::cout << "Test Case 1: Odds: ";
    printList(odds1);
    std::cout << "Evens: ";
    printList(evens1);
    std::cout << "\n" << std::endl;
    deleteList(odds1);
    deleteList(evens1);

    // Test Case 2: List with only odd
    Node* oddList = new Node(1, new Node(3, new Node(5, nullptr)));
    Node* evens2 = nullptr;
    Node* odds2 = nullptr;
    split(oddList, odds2, evens2);
    std::cout << "Test Case 2: Odds: ";
    printList(odds2);
    std::cout << "Evens: ";
    printList(evens2);
    std::cout << "\n" << std::endl;
    deleteList(odds2);
    deleteList(evens2);

    // Test Case 3: List with only even
    Node* evenList = new Node(2, new Node(4, new Node(6, nullptr)));
    Node* evens3 = nullptr;
    Node* odds3 = nullptr;
    split(evenList, odds3, evens3);
    std::cout << "Test Case 3: Odds: ";
    printList(odds3);
    std::cout << "Evens: ";
    printList(evens3);
    std::cout << "\n" << std::endl;
    deleteList(odds3);
    deleteList(evens3);

    // Test Case 4: List with both even and odd
    Node* bothList = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))));
    Node* evens4 = nullptr;
    Node* odds4 = nullptr;
    split(bothList, odds4, evens4);
    std::cout << "Test Case 4: Odds: ";
    printList(odds4);
    std::cout << "Evens: ";
    printList(evens4);
    std::cout << "\n" << std::endl;
    deleteList(odds4);
    deleteList(evens4);

    // Test Case 5: Test case with only one number
    Node* oneList = new Node(100, nullptr);
    Node* evens5 = nullptr;
    Node* odds5 = nullptr;
    split(oneList, odds5, evens5);
    std::cout << "Test Case 5: Odds: ";
    printList(odds5);
    std::cout << "Evens: ";
    printList(evens5);
    std::cout << "\n" << std::endl;
    deleteList(odds5);
    deleteList(evens5);

    // Clean-up
    delete emptyList;
    delete oddList;
    delete evenList;
    delete bothList;
    delete oneList;

    return 0;
}
