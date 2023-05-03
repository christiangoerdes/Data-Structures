#pragma once
#include <memory>

/**
 * @brief A node for a doubly linked list.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class DoublyLinkedListNode {

public:

    /**
     * @brief Constructor for DoublyLinkedListNode.
     *
     * @param newData The data to be stored in the node.
     */
    DoublyLinkedListNode(T newData) {
        data = newData;
        next = nullptr;
        prev = nullptr;
    }

    /**
     * @brief Returns the data stored in the node.
     *
     * @return const T& The data stored in the node.
     */
    const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the data stored in the node.
     *
     * @param newData The new data to be stored in the node.
     */
    void set_data(const T& newData) {
        data = newData;
    }

    /**
     * @brief Returns a shared pointer to the next node in the list.
     *
     * @return std::shared_ptr<DoublyLinkedListNode<T>> A shared pointer to the next node in the list.
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Sets the next node in the list.
     *
     * @param nextNode A shared pointer to the next node in the list.
     */
    void set_next(const std::shared_ptr<DoublyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

    /**
     * @brief Returns a shared pointer to the previous node in the list.
     *
     * @return std::shared_ptr<DoublyLinkedListNode<T>> A shared pointer to the previous node in the list.
     */
    std::shared_ptr<DoublyLinkedListNode<T>> get_prev() const {
        return prev;
    }

    /**
     * @brief Sets the previous node in the list.
     *
     * @param prevNode A shared pointer to the previous node in the list.
     */
    void set_prev(std::shared_ptr<DoublyLinkedListNode<T>> prevNode) {
        prev = prevNode;
    }

private:
    T data; /**< The data stored in the node. */
    std::shared_ptr<DoublyLinkedListNode<T>> next; /**< A shared pointer to the next node in the list. */
    std::shared_ptr<DoublyLinkedListNode<T>> prev; /**< A shared pointer to the previous node in the list. */
};

