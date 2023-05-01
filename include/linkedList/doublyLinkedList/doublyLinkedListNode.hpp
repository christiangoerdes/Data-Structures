/**
 * @file doublyLinkedListNode.hpp
 * @brief Implementation of a node for a doubly linked list
 * @author [Insert your name here]
 */

#pragma once
#include <memory>
#include "../singlyLinkedList/singlyLinkedListNode.hpp"

/**
 * @brief A class representing a node for a doubly linked list
 *
 * @tparam T The type of data stored in the node
 */
template <typename T>
class DoublyLinkedListNode : public SinglyLinkedListNode<T>{

public:

    DoublyLinkedListNode(T newData) : SinglyLinkedListNode<T>(newData){
        prev = nullptr;
    }

    std::shared_ptr<DoublyLinkedListNode<T>> get_prev() const {
        return prev;
    }

    void set_prev(std::shared_ptr<DoublyLinkedListNode<T>> prevNode) {
        prev = prevNode;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> prev;
};