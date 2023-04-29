#pragma once
#include <memory>
#include "../listNode.hpp"

template <typename T>
class SinglyLinkedListNode : ListNode<T> {

public:
    using ListNode<T>::data;

    SinglyLinkedListNode(T newData) {
        data = newData;
        next = nullptr;
    }

    const T& get_data() const {
        return data;
    }

    void set_data(const T& newData) {
        data = newData;
    }

    std::shared_ptr<SinglyLinkedListNode<T>> get_next() const {
        return next;
    }

    virtual void set_next(std::shared_ptr<SinglyLinkedListNode<T>> nextNode) {
        next = nextNode;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> next;
};
