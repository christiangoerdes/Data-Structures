#include <iostream>
#include <chrono>
#include <list>
#include "../../include/container/linkedList/doublyLinkedList/doublyLinkedList.hpp"

void testList(int numItems) {
    // Test self-written list
    DoublyLinkedList<int> myList;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        myList.insert_front(i);
    }
    while (!myList.is_empty()) {
        myList.remove(myList.get_end());
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> myListTime = end - start;
    std::cout << "MyList time for " << numItems << " items: " << myListTime.count() << " seconds" << std::endl;

    // Test C++ standard list
    std::list<int> stdList;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        stdList.push_front(i);
    }
    while (!stdList.empty()) {
        stdList.pop_back();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdListTime = end - start;
    std::cout << "std::list time for " << numItems << " items: " << stdListTime.count() << " seconds" << std::endl;
}

int main() {
    testList(100000);
    return 0;
}