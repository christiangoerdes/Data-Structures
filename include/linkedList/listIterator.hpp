#pragma once // Header guard to avoid multiple inclusion

#include "listNode.hpp" // Include the ListNode header file

template <typename T> // Template declaration for a generic type T
class ListIterator {
public:
    // Constructor that takes a shared pointer to a ListNode object as input
    ListIterator(std::shared_ptr<ListNode<T>> node) : current(node) {}

    // Dereference operator overload that returns a reference to the data stored in the current node
    T& operator*() const {
        return current->get_data();
    }

    // Member access operator overload that returns a shared pointer to the current node
    std::shared_ptr<ListNode<T>> operator->() const {
        return current;
    }

    // Prefix increment operator overload that advances the iterator to the next node and returns a reference to the updated iterator
    ListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    // Postfix increment operator overload that creates a copy of the current iterator, advances the current iterator to the next node and returns the original copy
    ListIterator operator++(int) {
        ListIterator temp(current);
        ++(*this);
        return temp;
    }


    // Postfix decrement operator overload that creates a copy of the current iterator, moves the current iterator to the previous node and returns the original copy
    ListIterator operator--(int) {
        ListIterator temp(current);
        --(*this);
        return temp;
    }

    // Equality operator overload that checks if two iterators point to the same node
    bool operator==(const ListIterator& other) const {
        return current == other.current;
    }

    // Inequality operator overload that checks if two iterators point to different nodes
    bool operator!=(const ListIterator& other) const {
        return !(*this == other);
    }

private:
    std::shared_ptr<ListNode<T>> current; // Shared pointer to the current node
};