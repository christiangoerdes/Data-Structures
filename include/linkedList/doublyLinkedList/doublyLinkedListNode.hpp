#pragma once
#include <memory>
#include "../singlyLinkedList/singlyLinkedListNode.hpp"

/**
 * @brief A node for a doubly linked list.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class DoublyLinkedListNode : public SinglyLinkedListNode<T>{

public:

    /**
     * @brief Constructor for DoublyLinkedListNode.
     *
     * @param newData The data to be stored in the node.
     */
    DoublyLinkedListNode(T newData) : SinglyLinkedListNode<T>(newData){
        prev = nullptr;
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
    std::shared_ptr<DoublyLinkedListNode<T>> prev; /**< A shared pointer to the previous node in the list. */
};

