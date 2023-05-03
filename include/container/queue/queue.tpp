#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
class Queue : public AbstractQueue<T> {
public:
    Queue() : size(0) {}

    size_t get_size() const override {
        return size;
    }

    T pop() override {
        if (list.get_size() < 1) {
            return NULL;
        }
        T t = list.get_head()->get_data();
        list.remove(list.get_head());
        return t;
    }

    void push(const T& t) override {
        list.insert_back(t);
    }

    bool is_empty() const override {
        return list.is_empty();
    }

private:
    size_t size;
    DoublyLinkedList<T> list;
};