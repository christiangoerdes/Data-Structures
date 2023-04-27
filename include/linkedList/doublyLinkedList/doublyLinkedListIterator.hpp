#pragma once // Header guard to avoid multiple inclusion

#include "doublyLinkedListNode.hpp" // Include the SinglyLinkedListNode header file
#include "../listIterator.hpp"

template <typename T> // Template declaration for a generic type T
class DoublyLinkedListIterator : public ListIterator<T>{
public:

    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> node) : current(node) {}

    // Prefix decrement operator overload that moves the iterator to the previous node and returns a reference to the updated iterator
    DoublyLinkedListIterator& operator--() {
        current = current->get_prev();
        return *this;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> current; // Shared pointer to the current nod
};