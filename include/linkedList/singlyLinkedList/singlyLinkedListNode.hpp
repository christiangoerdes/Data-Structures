/**
 * @file singlyLinkedListNode.cpp
 * @brief Implementation of SinglyLinkedListNode class template.
 */

#pragma once
#include <memory>

/**
 * @brief A node of a singly linked list that stores an element of type T.
 *
 * This class template inherits from ListNode<T>, and adds a next pointer.
 *
 * @tparam T The type of the element stored in the node.
 */
template <typename T>
class SinglyLinkedListNode {
public:
    SinglyLinkedListNode(T newData) : data(newData), next(nullptr) {}

    virtual const T& get_data() const {
        return data;
    }

    virtual void set_data(const T& newData) {
        data = newData;
    }

    virtual std::shared_ptr<SinglyLinkedListNode<T>>& get_next() const {
        return next;
    }

    virtual void set_next(const std::shared_ptr<SinglyLinkedListNode<T>>& nextNode) {
        next = nextNode;
    }

private:
    T data;
    std::shared_ptr<SinglyLinkedListNode<T>> next;
};
