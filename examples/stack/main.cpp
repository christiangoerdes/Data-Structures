#include "../../include/Container/stack/stack.hpp"

int main() {
    Stack<int> my_stack; // Create a stack of integers

    // Push some elements onto the stack
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);

    // Pop elements from the stack and print them
    while (!my_stack.is_empty()) {
        std::cout << my_stack.pop() << std::endl;
    }
}