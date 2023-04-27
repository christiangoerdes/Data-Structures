/**
 * @file DoublyLinkedListNode.h
 * @brief Definition of the DoublyLinkedListNode class template and its member functions
 */

#pragma once
#include <memory>
#include "../listNode.hpp"

/**
 * @brief A node in a doubly linked list
 * @tparam T The type of data stored in the node
 */
template <typename T>
class DoublyLinkedListNode : public ListNode<T> {
public:

    /**
     * @brief Returns a shared pointer to the previous node in the list
     * @return A shared pointer to the previous node in the list
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_prev() const {
        return predecessor;
    }

    /**
     * @brief Returns a shared_ptr to the next node in the list
     * @return Shared_ptr to the next node
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Sets the previous node in the list
     * @param prevNode A shared pointer to the previous node in the list
     */
    void set_prev(std::shared_ptr<DoublyLinkedListNode<T>> prevNode) {
        predecessor = prevNode;
    }


private:
    std::shared_ptr<DoublyLinkedListNode<T>> next; /**< Shared_ptr to the next node in the list */
    std::shared_ptr<DoublyLinkedListNode<T>> predecessor; /**< A shared pointer to the previous node in the list */
};