#pragma once

#include "doublyLinkedListNode.hpp"
#include "../singlyLinkedList/singlyLinkedListIterator.hpp"

template <typename T>
class DoublyLinkedListIterator : SinglyLinkedListIterator<T>{
public:

    DoublyLinkedListIterator(std::shared_ptr<DoublyLinkedListNode<T>> node) : SinglyLinkedListIterator<T>(node){
        current = node;
    }

    DoublyLinkedListIterator& operator--() {
        current = current->get_prev();
        return *this;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> current;
};