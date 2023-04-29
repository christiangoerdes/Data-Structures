/**
 * @file singlyLinkedListNode.cpp
 * @brief Implementation of SinglyLinkedListNode class template.
 */

#pragma once
#include <memory>
#include "../listNode.hpp"

/**
 * @brief A node of a singly linked list that stores an element of type T.
 *
 * This class template inherits from ListNode<T>, and adds a next pointer.
 *
 * @tparam T The type of the element stored in the node.
 */
template <typename T>
class SinglyLinkedListNode : ListNode<T> {

public:
    using ListNode<T>::data;

    /**
     * @brief Constructs a SinglyLinkedListNode object with the given data.
     *
     * @param newData The data to store in the node.
     */
    SinglyLinkedListNode(T newData) {
        data = newData;
        next = nullptr;
    }

    /**
     * @brief Returns a const reference to the data stored in the node.
     *
     * @return A const reference to the data stored in the node.
     */
    const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the data stored in the node to the given value.
     *
     * @param newData The new value to store in the node.
     */
    void set_data(const T& newData) {
        data = newData;
    }

    /**
     * @brief Returns a shared pointer to the next node in the list.
     *
     * @return A shared pointer to the next node in the list.
     */
    std::shared_ptr<SinglyLinkedListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Sets the next node in the list to the given node.
     *
     * @param nextNode A shared pointer to the next node in the list.
     */
    virtual void set_next(std::shared_ptr<SinglyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> next;
};
