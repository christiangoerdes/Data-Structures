#pragma once // Header guard to avoid multiple inclusion

#include "../listIterator.hpp"

template <typename T> // Template declaration for a generic type T
class SinglyLinkedListIterator : public ListIterator<T>{
public:
    SinglyLinkedListIterator(std::shared_ptr<SinglyLinkedListNode<T>> node) : current(node) {}

    std::shared_ptr<SinglyLinkedListNode<T>> operator->() const {
        return current;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> current; // Shared pointer to the current node
};