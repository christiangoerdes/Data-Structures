#include "../include/singlyLinkedList/singlyLinkedList.hpp"

#include <iostream>

int main() {
    SinglyLinkedList<int> list;
    std::cout << list.get_size() << std::endl;
    return 0;
}