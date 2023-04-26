#pragma once
#include <memory>

template <typename T>
class ListNode {
public:

    ListNode(T newData)  {
        data = newData;
        next = nullptr;
    }

    std::shared_ptr<ListNode<T>> get_next() const {
        return next;
    }

    std::shared_ptr<ListNode<T>> get_prev() const {
        return predecessor;
    }

    void set_next(std::shared_ptr<ListNode<T>> nextNode) {
        next = nextNode;
    }

    void set_prev(std::shared_ptr<ListNode<T>> prevNode) {
        predecessor = prevNode;
    }

    const T& get_data() const {
        return data;
    }

    void set_data(const T& newData) {
        data = newData;
    }

private:
    T data;
    std::shared_ptr<ListNode<T>> next;
    std::shared_ptr<ListNode<T>> predecessor;
};

