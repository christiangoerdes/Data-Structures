#include "../../include/container/linkedList/singlyLinkedList/singlyLinkedList.hpp"
#include "../../include/container/linkedList/doublyLinkedList/doublyLinkedList.hpp"

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
    for (SinglyLinkedListIterator<int> it = singlyList.get_front(); it != SinglyLinkedListIterator<int>(nullptr); ++it) {
        std::cout << *it << ", ";
    }

    std::cout << "\n" << std::endl;

    // Create a doubly linked list of strings
    DoublyLinkedList<std::string> doublyList;

    // Insert elements at the front of the doubly linked list
    doublyList.insert_front("three");
    doublyList.insert_front("two");
    doublyList.insert_front("one");

    // Insert an element after the head of the doubly linked list
    auto node = doublyList.get_head()->get_next()->get_prev().lock();
    doublyList.insert_after(node, "four");

    // Print the contents of the doubly linked list
    std::cout << "Doubly linked list:" << std::endl;
    doublyList.print(); // Output: one, two, four, three

    // Remove an element from the doubly linked list
    doublyList.remove(node);

    std::cout << std::endl;

    // Print the contents of the doubly linked list again
    std::cout << "Doubly linked list after removing an element:" << std::endl;
    for (DoublyLinkedListIterator<std::string> it = doublyList.get_front(); it != DoublyLinkedListIterator<std::string>(nullptr); ++it) {
        std::cout << *it << " ";
    }
    std::cout << *doublyList.get_end() << std::endl;

// Output: 1, 2, 3,


    return 0;
}