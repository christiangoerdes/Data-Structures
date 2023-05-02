#pragma once

#include "singlyLinkedListNode.hpp"
template <typename T>

class SinglyLinkedListIterator {
public:

    SinglyLinkedListIterator(std::shared_ptr<SinglyLinkedListNode<T>> node) : current(node) {}

    T& operator*() const {
        return current->get_data();
    }

    std::shared_ptr<SinglyLinkedListNode<T>> operator->() const {
        return current;
    }

    SinglyLinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    bool operator==(const SinglyLinkedListIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const SinglyLinkedListIterator& other) const {
        return *this != other;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> current;
};