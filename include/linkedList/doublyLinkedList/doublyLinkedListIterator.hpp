/*
#pragma once
#include "doublyLinkedListNode.hpp"


template <typename T>
class DoublyLinkedListIterator {
public:

    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> node) : current(node) {}


    T& operator*() const {
        return current->get_data();
    }


    std::shared_ptr<DoublyLinkedListNode<T>> operator->() const {
        return current;
    }


    DoublyLinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }


    DoublyLinkedListIterator operator++(int) {
        DoublyLinkedListIterator temp(current);
        ++(*this);
        return temp;
    }

    DoublyLinkedListIterator operator--(int) {
        DoublyLinkedListIterator temp(current);
        --(*this);
        return temp;
    }


    bool operator==(const DoublyLinkedListIterator& other) const {
        return current == other.current;
    }


    bool operator!=(const DoublyLinkedListIterator& other) const {
        return !(*this == other);
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> current;
};
 */