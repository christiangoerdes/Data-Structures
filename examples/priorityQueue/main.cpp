#include <iostream>
#include "../../include/priorityQueue/abstractPriorityQueue.hpp"
#include "queue"

int main() {

    PriorityQueue<int> meine_queue;

    for (int i = 0; i < 1000000; i++) {
        meine_queue.push(i);
        std::cout << meine_queue.top()->get_data() << std::endl;
    }

    for (int i = 0; i < 2000000; i++){
        meine_queue.pop();
        std::cout << meine_queue.top()->get_data() << std::endl;
    }

    std::priority_queue<int> a;
    for (int i = 0; i < 1000000; i++) {
        a.push(i);
        std::cout << a.top() << std::endl;
    }








}