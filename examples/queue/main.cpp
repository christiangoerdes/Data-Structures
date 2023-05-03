#include "../../include/Container/queue/queue.hpp"

int main() {
    Queue<int> my_queue; // Create a queue of integers

    // Enqueue some elements onto the queue
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    // Dequeue elements from the queue and print them
    while (!my_queue.is_empty()) {
        std::cout << my_queue.pop() << std::endl;
    }
}
