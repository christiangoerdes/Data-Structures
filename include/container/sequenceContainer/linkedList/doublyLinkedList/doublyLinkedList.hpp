/**
 * @file doublyLinkedList.hpp
 * @brief Header file for the AbstractDoublyLinkedList class
 */

#pragma once

#include "doublyLinkedListNode.hpp"
#include "doublyLinkedListIterator.hpp"
#include "../LinkedList.hpp"

/**
 * @brief Abstract base class for doubly linked list
 *
 * This class provides an interface for implementing a doubly linked list.
 * It inherits from the AbstractLinkedList class and defines abstract methods
 * for getting the front and tail nodes of the list, inserting a node after
 * a given node, and removing a given node.
 *
 * @tparam T The type of data to be stored in the linked list
 */
template <typename T>
class AbstractDoublyLinkedList : public AbstractLinkedList<T>{

public:

    /**
     * @brief Get the iterator to the front node of the linked list
     *
     * @return DoublyLinkedListIterator<T> An iterator pointing to the front node
     */
    virtual DoublyLinkedListIterator<T> get_front() const = 0;

    /**
     * @brief Insert a new node with the given data after the given predecessor node
     *
     * @param predecessor A shared pointer to the predecessor node
     * @param t The data to be stored in the new node
     */
    virtual void insert_after(std::shared_ptr<DoublyLinkedListNode<T>> predecessor, const T& t) = 0;

    /**
     * @brief Get the iterator to the tail node of the linked list
     *
     * @return DoublyLinkedListIterator<T> An iterator pointing to the tail node
     */
    virtual DoublyLinkedListIterator<T> get_end() const = 0;

    /**
     * @brief Remove the given node from the linked list
     *
     * @param node A shared pointer to the node to be removed
     */
    virtual void remove(const std::shared_ptr<DoublyLinkedListNode<T>>& node) = 0;
};

#include "doublyLinkedList.tpp"