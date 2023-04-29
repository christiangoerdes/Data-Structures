#pragma once
#include <memory>
#include "../listNode.hpp"

template <typename T>
class DoublyLinkedListNode : public ListNode<T> {

public:
    using ListNode<T>::data;

    DoublyLinkedListNode(T newData) {
        data = newData;
        next = nullptr;
        prev = nullptr;
    }

    std::shared_ptr<DoublyLinkedListNode<T>> get_next() const {
        return next;
    }

    void set_next(std::shared_ptr<DoublyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

    std::shared_ptr<DoublyLinkedListNode<T>> get_prev() const {
        return prev;
    }

    void set_prev(std::shared_ptr<DoublyLinkedListNode<T>> prevNode) {
        prev = prevNode;
    }

private:
    std::shared_ptr<DoublyLinkedListNode<T>> next;
    std::shared_ptr<DoublyLinkedListNode<T>> prev;
};