#pragma once

#include "listNode.hpp"

template <typename T>
class ListIterator {
public:
    ListIterator(std::shared_ptr<ListNode<T>> node) : current(node) {}

    T& operator*() const {
        return current->get_data();
    }

    std::shared_ptr<ListNode<T>> operator->() const {
        return current;
    }

    ListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    ListIterator operator++(int) {
        ListIterator temp(current);
        ++(*this);
        return temp;
    }

    ListIterator& operator--() {
        current = current->get_prev();
        return *this;
    }

    ListIterator operator--(int) {
        ListIterator temp(current);
        --(*this);
        return temp;
    }

    bool operator==(const ListIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const ListIterator& other) const {
        return !(*this == other);
    }

private:
    std::shared_ptr<ListNode<T>> current;
};