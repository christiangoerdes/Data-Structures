#include "../../include/linkedList/singlyLinkedList/singlyLinkedList.hpp"
#include "../../include/linkedList/doublyLinkedList/doublyLinkedList.hpp"

#include <iostream>

int main() {
    // Create a singly linked list of integers
    SinglyLinkedList<int> singlyList;

    // Insert elements at the front of the singly linked list
    singlyList.insert_front(3);
    singlyList.insert_front(2);
    singlyList.insert_front(1);

    // Print the contents of the singly linked list
    std::cout << "Singly linked list:" << std::endl;
    singlyList.print(); // Output: 1, 2, 3

    // Remove an element after the head of the singly linked list
    singlyList.remove_after(singlyList.get_head());

    std::cout << std::endl;

    // Print the contents of the singly linked list again
    std::cout << "Singly linked list after removing an element:" << std::endl;
    singlyList.print(); // Output: 1, 3

    std::cout << "\n" << std::endl;

    // Create a doubly linked list of strings
    DoublyLinkedList<std::string> doublyList;

    // Insert elements at the front of the doubly linked list
    doublyList.insert_front("three");
    doublyList.insert_front("two");
    doublyList.insert_front("one");

    // Insert an element after the head of the doubly linked list
    auto node = doublyList.get_head();
    doublyList.insert_after(node, "four");

    // Print the contents of the doubly linked list
    std::cout << "Doubly linked list:" << std::endl;
    doublyList.print(); // Output: one, two, four, three

    // Remove an element from the doubly linked list
    doublyList.remove(node);

    std::cout << std::endl;

    // Print the contents of the doubly linked list again
    std::cout << "Doubly linked list after removing an element:" << std::endl;
    doublyList.print(); // Output: one, two, three

    return 0;
}