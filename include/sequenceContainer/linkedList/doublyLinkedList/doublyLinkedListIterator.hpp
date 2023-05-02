#pragma once

#include "doublyLinkedListNode.hpp"
#include <memory>

// DoublyLinkedListIterator class definition
template <typename T>
class DoublyLinkedListIterator {
public:
    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> curr) : curr(curr) {}

    // Prefix increment operator
    DoublyLinkedListIterator<T>& operator++() {

        curr = std::dynamic_pointer_cast<DoublyLinkedListNode<T>>(curr->get_next());
        return *this;
    }

    // Postfix increment operator
    DoublyLinkedListIterator<T> operator++(int) {
        DoublyLinkedListIterator<T> tmp(*this);
        ++(*this);
        return tmp;
    }

    // Prefix decrement operator
    DoublyLinkedListIterator<T>& operator--() {
        curr = std::dynamic_pointer_cast<DoublyLinkedListNode<T>>(curr->get_prev());
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

private:
    std::shared_ptr<DoublyLinkedListNode<T>> curr; /**< Pointer to the current node */
};