#pragma once

#include "abstractPriorityQueue.hpp"
#include <string>
#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue : public AbstractPriorityQueue<T> {
    friend PriorityQueueIterator<T>;
public:
    PriorityQueue() : size_(0), heap(std::vector<T>()) {
        // nothing to do here
    }

    size_t get_size() const override {
        return size_;
    }

    bool is_empty() const override {
        return size_ == 0;
    }

    //PriorityQueueIterator<T> get_front() const override {
    // noch implementieren
    //}

    void push(const T& t) override {
        heap.push_back(t);
        size_++;
        heapify_up(heap.size()-1);
    }

    const T& top() const override {
        if (size_ == 0) {
            // Exception werfen
        }
        else {
            return heap[0];
        }
    }

    const T& pop() override {
        if (size_ == 0) {
            // Exception werfen
        }
        else {
            T save = heap[size_-1];
            heap[0] = save;
            size_--;
            heap.pop_back();
            heapify_down(0);
            return save;
        }
    }

private:
    void heapify_down(int idx) {
        int max_child_idx = idx;
        if (left_child_idx(idx) < size_) {
            max_child_idx = left_child_idx(idx);
            if (right_child_idx(idx) < size_) {
                if (heap[right_child_idx(idx)] > heap[max_child_idx]) {
                    max_child_idx = right_child_idx(idx);
                }
            }
        }
        if (heap[max_child_idx] > heap[idx]) {
            T temp = heap[max_child_idx];
            heap[max_child_idx] = heap[idx];
            heap[idx] = temp;
            heapify_down(max_child_idx);
        }
    }
    void heapify_up(int idx) {
        if (idx > 0) {
            int parent = parent_idx(idx);
            if (heap[parent] < heap[idx]) {
                T temp = heap[parent];
                heap[parent] = heap[idx];
                heap[idx] = temp;
                heapify_up(parent);
            }
        }
    }
    int left_child_idx(int idx) {
        return 2*idx+1;
    }
    int right_child_idx(int idx) {
        return 2*idx+2;
    }
    int parent_idx(int idx) {
        return (idx-1)/2;
    }
    size_t size_;
    std::vector<T> heap;
};
