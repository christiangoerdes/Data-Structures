#pragma once

#include "singlyLinkedListNode.hpp"
#include "singlyLinkedListIterator.hpp"
#include "../LinkedList.hpp"

template <typename T>
class AbstractSinglyLinkedList : public AbstractLinkedList<T>{

public:

    virtual SinglyLinkedListIterator<T> get_front() const = 0 ;

    virtual void insert_after(const std::shared_ptr<SinglyLinkedListNode<T>>& predecessor, const T& t) = 0;

    virtual void remove_front() = 0;

    virtual void remove_after(const std::shared_ptr<SinglyLinkedListNode<T>>& predecessor) = 0;
};

#include "../../../src/linkedList/singlyLinkedList/singlyLinkedList.tpp"