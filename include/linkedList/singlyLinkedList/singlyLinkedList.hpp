#pragma once
/**
 * @file singlyLinkedList.hpp
 * @brief Header file for a singly linked list implementation
 */

#include "listNode.hpp"
#include "../LinkedList.hpp"

/**
 * @brief Abstract interface for a singly linked list
 * @tparam T Type of data stored in the list
 */
template <typename T>
class AbstractSinglyLinkedList : public AbstractLinkedList<T>{

public:

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    virtual ListIterator<T> get_front() const = 0 ; //TODO add the Iterator

    /**
     * @brief Remove the node at the front of the list
     */
    virtual void remove_front() = 0;

    /**
     * @brief Remove the node after the given predecessor node
     * @param predecessor Node after which the next node should be removed
     */
    virtual void remove_after(const std::shared_ptr<ListNode<T>>& predecessor) = 0;
};

#include "../../../src/linkedList/singlyLinkedList/singlyLinkedList.tpp"