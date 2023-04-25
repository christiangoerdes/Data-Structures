#ifndef PROJEKTALPHA_SINGLYLINKEDLIST_HPP
#define PROJEKTALPHA_SINGLYLINKEDLIST_HPP

#include "listNode.hpp"
#include <iterator>

template<class T>

class AbstractSinglyLinkedList {

public:
    virtual size_t get_size() = 0;
    virtual void get_front() = 0;    //TODO make get_front() return an Iterator
    virtual void insert_front(T t) = 0;
    virtual void insert_after(ListNode<T> predecessor, T t) = 0;
    virtual void remove_front() = 0;
    virtual void remove_after(ListNode<T> predecessor) = 0;
};

template<class T>

class SinglyLinkedList : public AbstractSinglyLinkedList<T> {

};

#endif //PROJEKTALPHA_SINGLYLINKEDLIST_HPP