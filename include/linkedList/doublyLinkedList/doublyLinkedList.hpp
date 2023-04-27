/**
 * @file abstractDoublyLinkedList.hpp
 * @brief Definition of the AbstractDoublyLinkedList class template and its member functions
 */

#pragma once

#include "doublyLinkedListNode.hpp"
#include "doublyLinkedListIterator.hpp"
#include "../linkedList.hpp"

/**
 * @brief An abstract base class for doubly linked lists
 * @tparam T The type of data stored in the nodes of the list
 */
template <typename T>
class AbstractDoublyLinkedList : public AbstractLinkedList<T>{

public:

    /**
     * @brief Returns an iterator to the last element in the list
     * @return An iterator to the last element in the list
     */
    virtual DoublyLinkedListIterator<T> get_tail() const = 0;

    /**
     * @brief Removes the specified node from the list
     * @param node A shared pointer to the node to be removed
     */
    virtual void remove(const std::shared_ptr<SinglyLinkedListNode<T>>& node) = 0;
};

#include "../../../src/linkedList/doublyLinkedList/doublyLinkedList.tpp"