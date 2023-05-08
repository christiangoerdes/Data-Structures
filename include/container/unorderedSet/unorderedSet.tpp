#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
class UnorderedSet : public AbstractUnorderedSet<T> {
public:
    UnorderedSet() : size(0) {} // Constructor initializing size to zero

    size_t get_size() const override { // Implementation of get_size() function of abstract class
        return size;
    }

    bool is_empty() const override {
        return size == 0;
    }

private:
    size_t size;
    std::vector<std::list<T>> buckets;
};
