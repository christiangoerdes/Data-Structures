#pragma once
#include <memory>

/**
 * @brief A node for a singly linked list.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class SinglyLinkedListNode {
public:
    /**
     * @brief Constructor for SinglyLinkedListNode.
     *
     * @param newData The data to be stored in the node.
     */
    SinglyLinkedListNode(T newData) : data(newData), next(nullptr) {}

    /**
     * @brief Returns the data stored in the node.
     *
     * @return const T& The data stored in the node.
     */
    virtual const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the data stored in the node.
     *
     * @param newData The new data to be stored in the node.
     */
    virtual void set_data(const T& newData) {
        data = newData;
    }

    /**
     * @brief Returns a shared pointer to the next node in the list.
     *
     * @return std::shared_ptr<SinglyLinkedListNode<T>> A shared pointer to the next node in the list.
     */
    virtual std::shared_ptr<SinglyLinkedListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Sets the next node in the list.
     *
     * @param nextNode A shared pointer to the next node in the list.
     */
    virtual void set_next(const std::shared_ptr<SinglyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

private:
    T data; /**< The data stored in the node. */
    std::shared_ptr<SinglyLinkedListNode<T>> next; /**< A shared pointer to the next node in the list. */
};
