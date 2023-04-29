/**
 * @file singlyLinkedListIterator.cpp
 * @brief Implementation of the SinglyLinkedListIterator class.
 */

#pragma once

#include "../listIterator.hpp"

template <typename T>
/**
 * @class SinglyLinkedListIterator
 * @brief Iterator for a singly linked list.
 */
class SinglyLinkedListIterator : public ListIterator<T> {
public:
    /**
     * @brief Constructor for the SinglyLinkedListIterator class.
     * @param node Pointer to the node to iterate from.
     */
    SinglyLinkedListIterator(std::shared_ptr<SinglyLinkedListNode<T>> node) : current(node) {}

    /**
     * @brief Overloaded dereference operator.
     * @return Reference to the data of the current node.
     */
    T& operator*() const {
        return current->get_data();
    }

    /**
     * @brief Overloaded member access operator.
     * @return Pointer to the current node.
     */
    std::shared_ptr<ListNode<T>> operator->() const {
        return current;
    }

    /**
     * @brief Overloaded pre-increment operator.
     * @return Reference to the updated iterator.
     */
    SinglyLinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    /**
     * @brief Overloaded post-increment operator.
     * @return Copy of the old iterator.
     */
    SinglyLinkedListIterator operator++(int) {
        SinglyLinkedListIterator temp(current);
        ++(*this);
        return temp;
    }

    /**
     * @brief Overloaded post-decrement operator.
     * @return Copy of the old iterator.
     */
    SinglyLinkedListIterator operator--(int) {
        SinglyLinkedListIterator temp(current);
        --(*this);
        return temp;
    }

    /**
     * @brief Overloaded equality operator.
     * @param other The iterator to compare to.
     * @return True if the iterators point to the same node, false otherwise.
     */
    bool operator==(const SinglyLinkedListIterator& other) const {
        return current == other.current;
    }

    /**
     * @brief Overloaded inequality operator.
     * @param other The iterator to compare to.
     * @return True if the iterators do not point to the same node, false otherwise.
     */
    bool operator!=(const SinglyLinkedListIterator& other) const {
        return *this != other;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> current;
};
