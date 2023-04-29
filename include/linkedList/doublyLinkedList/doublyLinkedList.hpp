#pragma once

#include "doublyLinkedListNode.hpp"
#include "doublyLinkedListIterator.hpp"
#include "../linkedList.hpp"

template <typename T>
class AbstractDoublyLinkedList : public AbstractLinkedList<T>{

public:

    virtual DoublyLinkedListIterator<T> get_front() const = 0;

    virtual void insert_after(const std::shared_ptr<DoublyLinkedListNode<T>>& predecessor, const T& t) = 0;

    virtual DoublyLinkedListIterator<T> get_tail() const = 0;

    virtual void remove(const std::shared_ptr<DoublyLinkedListNode<T>>& node) = 0;
};

#include "../../../src/linkedList/doublyLinkedList/doublyLinkedList.tpp"