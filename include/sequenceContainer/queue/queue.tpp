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

    void push (T& t) override {

    }

    T pop() override {
        return NULL;
    }

private:
    size_t size;
};
