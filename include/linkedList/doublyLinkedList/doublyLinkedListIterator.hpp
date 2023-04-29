#pragma once

#include "../ListIterator.hpp"

template <typename T>
class DoublyLinkedListIterator : public ListIterator<T>{
public:
    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> node) : current(node) {}

    virtual T& operator*() const {
        return current->get_data();
    }

    virtual std::shared_ptr<ListNode<T>> operator->() const {
        return current;
    }

    virtual DoublyLinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }
 
    virtual DoublyLinkedListIterator operator++(int) {
        DoublyLinkedListIterator temp(current);
        ++(*this);
        return temp;
    }

    virtual DoublyLinkedListIterator operator--(int) {
        DoublyLinkedListIterator temp(current);
        --(*this);
        return temp;
    }

    virtual bool operator==(const DoublyLinkedListIterator& other) const {
        return current == other.current;
    }

    virtual bool operator!=(const DoublyLinkedListIterator& other) const {
        return *this != other;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> current;
};