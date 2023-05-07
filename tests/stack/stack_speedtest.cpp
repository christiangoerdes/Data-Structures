#include <iostream>
#include <chrono>
#include <stack>
#include "../../include/container/stack/stack.hpp"


// Function to test the stack implementation
void testStack(int numItems) {
    // Test self-written stack
    Stack<int> myStack;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        myStack.push(i);
    }
    while (!myStack.is_empty()) {
        myStack.pop();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> myStackTime = end - start;
    std::cout << "MyStack time for " << numItems << " items: " << myStackTime.count() << " seconds" << std::endl;

    // Test C++ standard stack
    std::stack<int> stdStack;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numItems; i++) {
        stdStack.push(i);
    }
    while (!stdStack.empty()) {
        stdStack.pop();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> stdStackTime = end - start;
    std::cout << "std::stack time for " << numItems << " items: " << stdStackTime.count() << " seconds" << std::endl;
}

int main () {

    testStack(1000000);

}
