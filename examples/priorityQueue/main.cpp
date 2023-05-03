#include <iostream>
#include "../../include/container/priorityQueue/abstractPriorityQueue.hpp"
#include "queue"
#include <stdlib.h>

int main() {

    PriorityQueue<int> meine_queue;


    std::priority_queue<int> a;
    for (int i = 0; i < 10000; i++) {
        a.push(i);
        std::cout << a.top() << std::endl;
    }

    for (int i = 0; i < 2000; i++){
        meine_queue.pop();
        std::cout << meine_queue.top()->get_data() << std::endl;
    }


}