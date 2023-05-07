#include <iostream>
#include <chrono>
#include <queue>
#include "../../include/container/priorityQueue/priorityQueue.hpp"

// Function to test the priorityQueue implementation
void testPriorityQueue(int numItems) {
    // Test self-written priorityQueue
    PriorityQueue<int> myPriorityQueue;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        myPriorityQueue.push(i);
    }
    while (!myPriorityQueue.is_empty()) {
        myPriorityQueue.pop();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> myStackTime = end - start;
    std::cout << "PriorityQueue time for " << numItems << " items: " << myStackTime.count() << " seconds" << std::endl;

    // Test C++ standard priorityQueue
    std::priority_queue<int> stdPriorityQueue;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        stdPriorityQueue.push(i);
    }
    while (!stdPriorityQueue.empty()) {
        stdPriorityQueue.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdStackTime = end - start;
    std::cout << "std::priority_queue time for " << numItems << " items: " << stdStackTime.count() << " seconds" << std::endl;
}

int main () {
    testPriorityQueue(10000000);
}