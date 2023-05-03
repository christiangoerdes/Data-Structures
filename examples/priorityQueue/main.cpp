#include <iostream>
#include "../../include/container/priorityQueue/abstractPriorityQueue.hpp"
#include "queue"
#include <stdlib.h>

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


}