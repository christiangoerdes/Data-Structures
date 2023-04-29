#pragma once
/**
 * @file singlyLinkedList.hpp
 * @brief Header file for a singly linked list implementation
 */

#include "listNode.hpp"
#include "listIterator.hpp"

/**
 * @brief Abstract interface for a singly linked list
 * @tparam T Type of data stored in the list
 */
template <typename T>
class AbstractLinkedList {

public:
    /**
     * @brief Get the size of the list
     * @return The number of nodes in the list
     */
    virtual size_t get_size() const = 0;

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    virtual ListIterator<T> get_front() const = 0;

    /**
     * @brief Insert a new node containing data at the front of the list
     * @param t Data to be stored in the new node
     */
    virtual void insert_front(const T& t) = 0;

    /**
     * @brief Insert a new node containing data after the given prev node
     * @param predecessor Node after which the new node should be inserted
     * @param t Data to be stored in the new node
     */
    virtual void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) = 0;
};