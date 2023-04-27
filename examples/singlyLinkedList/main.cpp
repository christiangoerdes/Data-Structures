#include "../../include/singlyLinkedList/singlyLinkedList.hpp"

#include <iostream>

int main() {
    SinglyLinkedList<std::string> list;
    list.insert_front("1");
    list.insert_front("2");
    list.insert_after(list.get_head(), "3");
    list.print();
    std::cout << std::endl;
    list.remove_after(list.get_head());
    list.print();
    return 0;
}