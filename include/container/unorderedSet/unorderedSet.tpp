#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <iostream>
#include <memory>

template <typename T>
class UnorderedSet : public AbstractUnorderedSet<T> {
public:
    explicit UnorderedSet(size_t capacity = 100) : size(0), capacity(capacity) {
        table.resize(capacity);
    }

    [[nodiscard]] size_t get_size() const override { // Implementation of get_size() function of abstract class
        return size;
    }

    [[nodiscard]] bool is_empty() const override {
        return size == 0;
    }

    void insert(const T& value) {
        size_t index = hash(value);
        for (const auto& v : table[index]) {
            if (*v == value) {
                return;
            }
        }
        table[index].push_back(std::make_shared<T>(value));
        size++;
        balance();
    }

    bool contains(const T& value) const {
        size_t index = hash(value);
        for (const auto& v : table[index]) {
            if (*v == value) {
                return true;
            }
        }
        return false;
    }

    void remove(const T& value) {
        size_t index = hash(value);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (**it == value) {
                table[index].erase(it);
                size--;
                balance();
                return;
            }
        }
    }

private:
    size_t capacity; // num of buckets
    size_t size; // num of elements
    std::vector<std::list<std::shared_ptr<T>>> table;

    size_t hash(const T& value) const {
        return std::hash<T>()(value) % capacity;
    }
    void balance() {
        double loadFactor = static_cast<double>(size) / capacity;
        if (loadFactor > 0.75) { // if load factor is too high, resize to double the capacity
            size_t newCapacity = capacity * 2;
            auto newTable = std::vector<std::list<std::shared_ptr<T>>>(newCapacity);
            for (size_t i = 0; i < capacity; i++) {
                for (const auto& value : table[i]) {
                    size_t index = hash(*value);
                    newTable[index].push_back(value);
                }
            }
            capacity = newCapacity;
            table = newTable;
        }
        else if (loadFactor < 0.25 && capacity > 100) { // if load factor is too low, resize to half the capacity (with a minimum capacity of 100)
            size_t newCapacity = capacity / 2;
            newCapacity = newCapacity < 100 ? 100 : newCapacity;
            auto newTable = std::vector<std::list<std::shared_ptr<T>>>(newCapacity);
            for (size_t i = 0; i < capacity; i++) {
                for (const auto& value : table[i]) {
                    size_t index = hash(*value);
                    newTable[index].push_back(value);
                }
            }
            capacity = newCapacity;
            table = newTable;
        }
    }
};
