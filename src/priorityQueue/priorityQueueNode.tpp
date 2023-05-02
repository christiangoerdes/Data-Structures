#pragma once

#include <memory>
#include <priorityQueue/priorityQueueNode.hpp>

template<typename T>
class PriorityQueueNode {
    typedef std::shared_ptr<PriorityQueueNode<T>> Nodeptr;

public:
    PriorityQueueNode(T data, Nodeptr parent) {
        data_ = data;
        parent_ = parent;
        next = nullptr;
    }

    void set_left_child(const T& data) {
        left_child = std::make_shared<PriorityQueueNode<T>>(data, Nodeptr(this))
    }

    void set_right_child(const T& data) {
        right_child = std::make_shared<PriorityQueueNode<T>>(data, Nodeptr(this))
    }

    void set_left_child(Nodeptr new_left_child) {
        left_child = new_left_child;
    }

    void set_right_child(Nodeptr new_right_child) {
        right_child = new_left_child;
    }

    const Nodeptr get_left_child() const {
        return left_child;
    }

    const Nodeptr get_right_child() const {
        return right_child;
    }

    const Nodeptr get_parent() const {
        return parent_;
    }

    void set_parent(const Nodeptr new_parent) {
        parent_ = new_parent;
    }

    const T& get_data() const {
        return data_;
    }

};