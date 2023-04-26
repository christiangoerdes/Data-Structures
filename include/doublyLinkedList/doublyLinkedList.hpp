/**
 * @file abstractDoublyLinkedList.hpp
 * @brief Definition of the AbstractDoublyLinkedList class template and its member functions
 */

#pragma once

#include "listNode.hpp"
#include "listIterator.hpp"
#include <iterator>

/**
 * @brief An abstract base class for doubly linked lists
 * @tparam T The type of data stored in the nodes of the list
 */
template <typename T>
class AbstractDoublyLinkedList {

public:

    /**
     * @brief Returns the size of the list
     * @return The size of the list
     */
    virtual size_t get_size() const = 0;

    /**
     * @brief Returns an iterator to the first element in the list
     * @return An iterator to the first element in the list
     */
    virtual ListIterator<T> get_front() const = 0;

    /**
     * @brief Returns an iterator to the last element in the list
     * @return An iterator to the last element in the list
     */
    virtual ListIterator<T> get_tail() const = 0;

    /**
     * @brief Inserts a new node with the given data at the beginning of the list
     * @param t The data to be inserted
     */
    virtual void insert_front(const T& t) = 0;

    /**
     * @brief Inserts a new node with the given data after the specified node
     * @param predecessor A shared pointer to the node after which the new node should be inserted
     * @param t The data to be inserted
     */
    virtual void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) = 0;

    /**
     * @brief Removes the specified node from the list
     * @param node A shared pointer to the node to be removed
     */
    virtual void remove(const std::shared_ptr<ListNode<T>>& node) = 0;
};

#include "../../src/doublyLinkedList/doublyLinkedList.tpp"