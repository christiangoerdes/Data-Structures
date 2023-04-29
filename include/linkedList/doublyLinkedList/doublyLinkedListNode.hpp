/**
 * @file doublyLinkedListNode.hpp
 * @brief Implementation of a node for a doubly linked list
 * @author [Insert your name here]
 */

#pragma once
#include <memory>
#include "../listNode.hpp"

/**
 * @brief A class representing a node for a doubly linked list
 *
 * @tparam T The type of data stored in the node
 */
template <typename T>
class DoublyLinkedListNode : public ListNode<T> {

public:
    /**
     * @brief Construct a new Doubly Linked List Node object with the given data
     *
     * @param newData The data to be stored in the node
     */
    DoublyLinkedListNode(T newData) {
        data = newData;
        next = nullptr;
        prev = nullptr;
    }

    /**
     * @brief Get the data stored in the node
     *
     * @return const T& The data stored in the node
     */
    virtual const T& get_data() const {
        return data;
    }

    /**
     * @brief Set the data stored in the node
     *
     * @param newData The new data to be stored in the node
     */
    virtual void set_data(const T& newData) {
        data = newData;
    }

    /**
     * @brief Get a shared pointer to the next node in the list
     *
     * @return std::shared_ptr<DoublyLinkedListNode<T>> A shared pointer to the next node in the list
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Set the next node in the list
     *
     * @param nextNode A shared pointer to the next node in the list
     */
    void set_next(std::shared_ptr<DoublyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

    /**
     * @brief Get a shared pointer to the previous node in the list
     *
     * @return std::shared_ptr<DoublyLinkedListNode<T>> A shared pointer to the previous node in the list
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_prev() const {
        return prev;
    }

    /**
     * @brief Set the previous node in the list
     *
     * @param prevNode A shared pointer to the previous node in the list
     */
    void set_prev(std::shared_ptr<DoublyLinkedListNode<T>> prevNode) {
        prev = prevNode;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> next; /**< A shared pointer to the next node in the list */
    std::shared_ptr<DoublyLinkedListNode<T>> prev; /**< A shared pointer to the previous node in the list */
};