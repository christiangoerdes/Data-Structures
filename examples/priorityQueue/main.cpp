#include <iostream>
#include <string>
#include "../../include/container/priorityQueue/priorityQueue.hpp"

int main() {

    PriorityQueue<int> meine_queue;

    for (int i = 0; i < 10000; i++) {
        meine_queue.push(i);
        std::cout << meine_queue.top() << std::endl;
    }

    for (int i = 0; i < 1000; i++) {
        meine_queue.pop();
        std::cout << meine_queue.top() << std::endl;
    }

    PriorityQueue<std::string> string_queue;

    for (int i = 0; i < 10000; i++) {
        string_queue.push(std::to_string(i));
        std::cout << string_queue.top() << std::endl;
    }

}