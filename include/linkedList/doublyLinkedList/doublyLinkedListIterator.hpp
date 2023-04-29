/**
 * @file DoublyLinkedListIterator.hpp
 * @brief Header file for the DoublyLinkedListIterator class
 */

#pragma once

#include "../ListIterator.hpp"

/**
 * @brief Iterator class for a doubly linked list
 *
 * This class provides an iterator for a doubly linked list.
 * It inherits from the ListIterator class and implements the
 * necessary methods for iterating over the list.
 *
 * @tparam T The type of data stored in the linked list
 */
template <typename T>
class DoublyLinkedListIterator : public ListIterator<T> {
public:

    /**
     * @brief Construct a new Doubly Linked List Iterator object
     *
     * @param node A shared pointer to the current node pointed by the iterator
     */
    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> node) : current(node) {}

    /**
     * @brief Return a reference to the data stored in the current node
     *
     * @return T& A reference to the data stored in the current node
     */
    T& operator*() const {
        return current->get_data();
    }

    /**
     * @brief Return a shared pointer to the current node
     *
     * @return std::shared_ptr<ListNode<T>> A shared pointer to the current node
     */
    std::shared_ptr<ListNode<T>> operator->() const {
        return current;
    }

    /**
     * @brief Move the iterator to the next node and return a reference to the updated iterator
     *
     * @return DoublyLinkedListIterator& A reference to the updated iterator
     */
    DoublyLinkedListIterator& operator++() {
        current = current->get_next();
        return *this;
    }

    /**
     * @brief Move the iterator to the next node and return a copy of the original iterator
     *
     * @return DoublyLinkedListIterator A copy of the original iterator
     */
    DoublyLinkedListIterator operator++(int) {
        DoublyLinkedListIterator temp(current);
        ++(*this);
        return temp;
    }

    /**
     * @brief Move the iterator to the previous node and return a copy of the original iterator
     *
     * @return DoublyLinkedListIterator A copy of the original iterator
     */
    DoublyLinkedListIterator operator--(int) {
        DoublyLinkedListIterator temp(current);
        --(*this);
        return temp;
    }

    /**
     * @brief Check if two iterators point to the same node
     *
     * @param other The other iterator to be compared with
     * @return true If both iterators point to the same node
     * @return false If both iterators point to different nodes
     */
    bool operator==(const DoublyLinkedListIterator& other) const {
        return current == other.current;
    }

    /**
     * @brief Check if two iterators point to different nodes
     *
     * @param other The other iterator to be compared with
     * @return true If both iterators point to different nodes
     * @return false If both iterators point to the same node
     */
    bool operator!=(const DoublyLinkedListIterator& other) const {
        return !(*this == other);
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> current;
};