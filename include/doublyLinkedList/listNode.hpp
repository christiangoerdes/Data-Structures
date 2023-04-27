/**
 * @file ListNode.h
 * @brief Definition of the ListNode class template and its member functions
 */

#pragma once
#include <memory>

/**
 * @brief A node in a doubly linked list
 * @tparam T The type of data stored in the node
 */
template <typename T>
class ListNode {
public:

    /**
     * @brief Constructs a new ListNode object
     * @param newData The data to be stored in the node
     */
    ListNode(T newData)  {
        data = newData;
        next = nullptr;
    }

    /**
     * @brief Returns a shared pointer to the next node in the list
     * @return A shared pointer to the next node in the list
     */
    std::shared_ptr<ListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Returns a shared pointer to the previous node in the list
     * @return A shared pointer to the previous node in the list
     */
    std::shared_ptr<ListNode<T>> get_prev() const {
        return predecessor;
    }

    /**
     * @brief Sets the next node in the list
     * @param nextNode A shared pointer to the next node in the list
     */
    void set_next(std::shared_ptr<ListNode<T>> nextNode) {
        next = nextNode;
    }

    /**
     * @brief Sets the previous node in the list
     * @param prevNode A shared pointer to the previous node in the list
     */
    void set_prev(std::shared_ptr<ListNode<T>> prevNode) {
        predecessor = prevNode;
    }

    /**
     * @brief Returns a const reference to the data stored in the node
     * @return A const reference to the data stored in the node
     */
    const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the data stored in the node
     * @param newData The new data to be stored in the node
     */
    void set_data(const T& newData) {
        data = newData;
    }

private:
    T data; /**< The data stored in the node */
    std::shared_ptr<ListNode<T>> next; /**< A shared pointer to the next node in the list */
    std::shared_ptr<ListNode<T>> predecessor; /**< A shared pointer to the previous node in the list */
};