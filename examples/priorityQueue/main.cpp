#include <iostream>
#include "../../include/container/priorityQueue/abstractPriorityQueue.hpp"
#include "queue"
#include <stdlib.h>

int main() {

    PriorityQueue<int> meine_queue;

    for (int i = 0; i < 100000; i++) {
        int x = rand()*1453456 % 100000000000;
        // std::cout << "new value to be inserted " << x << std::endl;
        meine_queue.push(x);
        std::cout << meine_queue.top()->get_data() << std::endl;
    }

    for (int i = 0; i < 20000; i++){
        meine_queue.pop();
        std::cout << meine_queue.top()->get_data() << std::endl;
    }

    //std::priority_queue<int> a;
    //for (int i = 0; i < 1000000; i++) {
    //    a.push(i);
    //    std::cout << a.top() << std::endl;
    //}








}