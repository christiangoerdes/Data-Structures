/**
 * @file abstractSinglyLinkedList.hpp
 * @brief This file contains the AbstractSinglyLinkedList class.
 */

#pragma once

#include "singlyLinkedListNode.hpp"
#include "singlyLinkedListIterator.hpp"
#include "../LinkedList.hpp"

/**
 * @brief An abstract base class for a singly linked list.
 * @tparam T The data type of the elements in the list.
 */
template <typename T>
class AbstractSinglyLinkedList : public AbstractLinkedList<T>{

public:

    /**
     * @brief Returns an iterator to the first element in the list.
     * @return A SinglyLinkedListIterator pointing to the first element in the list.
     */
    virtual SinglyLinkedListIterator<T> get_front() const = 0 ;

    /**
     * @brief Inserts a new element after the given predecessor node.
     * @param predecessor A shared pointer to the predecessor node.
     * @param t The data of the new element to be inserted.
     */
    virtual void insert_after(const std::shared_ptr<SinglyLinkedListNode<T>>& predecessor, const T& t) = 0;
    virtual void insert_after(SinglyLinkedListIterator<T> predecessor, const T& t) = 0;

    /**
     * @brief Removes the first element in the list.
     */
    virtual T remove_front() = 0;

    /**
     * @brief Removes the element after the given predecessor node.
     * @param predecessor A shared pointer to the predecessor node.
     */
    virtual T remove_after(const std::shared_ptr<SinglyLinkedListNode<T>>& predecessor) = 0;

    /**
     * @brief Removes the element after the given iterator.
     * @param predecessor An iterator of the predecessor node.
     */
    virtual T remove_after(SinglyLinkedListIterator<T> predecessor) = 0;
};

#include "singlyLinkedList.tpp"
