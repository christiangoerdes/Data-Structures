#pragma once

#include "iostream"
#include "singlyLinkedListNode.hpp"
template <typename T>
class SinglyLinkedListIterator {
public:
    // Constructor: initializes curr to the given node
    SinglyLinkedListIterator(std::shared_ptr<SinglyLinkedListNode<T>> curr) : curr(curr) {}

    // Dereference operator: returns the data in the current node
    const T& operator*() const {
        return curr->get_data();
    }


    // Arrow operator: returns a pointer to the data in the current node
    T* operator->() const {
        return &curr->get_data();
    }

    // Prefix increment operator: moves to the next node in the list and returns the iterator
    SinglyLinkedListIterator<T>& operator++() {
        curr = curr->get_next();
        return *this;
    }

    // Postfix increment operator: moves to the next node in the list and returns a copy of the previous iterator
    SinglyLinkedListIterator<T> operator++(int) {
        SinglyLinkedListIterator<T> old(*this);
        curr = curr->get_next();
        return old;
    }

    // Equality operator: returns true if the iterators point to the same node
    bool operator==(const SinglyLinkedListIterator<T>& other) const {
        return curr == other.curr;
    }

    // Inequality operator: returns true if the iterators point to different nodes
    bool operator!=(const SinglyLinkedListIterator<T>& other) const {
        return curr != other.curr;
    }

    // returns the current pointer
    SinglyLinkedListNode<T> get_pointer() {
        return curr;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> curr; /**< Pointer to the current node in the list */
};