#pragma once

#include "doublyLinkedListNode.hpp"
#include <memory>

// DoublyLinkedListIterator class definition
template <typename T>
class DoublyLinkedListIterator {
public:
    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> curr) : curr(curr) {}

    // Overloaded prefix increment operator
    DoublyLinkedListIterator& operator++() {
        curr = curr->get_next();
        return *this;
    }

    // Overloaded postfix increment operator
    DoublyLinkedListIterator operator++(int) {
        DoublyLinkedListIterator<T> temp(curr);
        curr = curr->get_next();
        return temp;
    }

        // Prefix decrement operator
    DoublyLinkedListIterator<T>& operator--() {
        curr = curr->get_prev();
        return *this;
    }

    // Postfix decrement operator
    DoublyLinkedListIterator<T> operator--(int) {
        DoublyLinkedListIterator<T> tmp(*this);
        --(*this);
        return tmp;
    }

    // Dereference operator
    const T& operator*() const {
        return curr->get_data();
    }

    // Equality operator
    bool operator==(const DoublyLinkedListIterator<T>& other) const {
        return curr == other.curr;
    }

    // Inequality operator
    bool operator!=(const DoublyLinkedListIterator<T>& other) const {
        return curr != other.curr;
    }

    // returns the current pointer
    std::shared_ptr<DoublyLinkedListNode<T>> get_pointer() {
        return curr;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> curr; /**< Pointer to the current node */
};