#pragma once

#include "listNode.hpp"
#include <iterator>


template <typename T>
class AbstractDoublyLinkedList {

public:

    virtual size_t get_size() const = 0;

    virtual void get_front() const = 0; //TODO add the Iterator

    virtual void get_tail() const = 0; //TODO add the Iterator

    virtual void insert_front(const T& t) = 0;

    virtual void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) = 0;

    virtual void remove(const std::shared_ptr<ListNode<T>>& node) = 0;
};

#include "../../src/doublyLinkedList/doublyLinkedList.tpp"