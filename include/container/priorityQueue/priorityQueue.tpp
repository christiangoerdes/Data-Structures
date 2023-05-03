#pragma once

#include "abstractPriorityQueue.hpp"
#include <string>
#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue : public AbstractPriorityQueue<T> {
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
        heapify(heap.size()-1);
        size_++;
    }

    PQueueNodePtr top() const override {
        return root;
    }

    PQueueNodePtr pop() override {

    }


private:
    void heapify_down(int idx) {
        int current_idx = idx;
        int max_child_idx = current_idx;
        if (left_child_idx(current_idx) < size_) {
            max_child_idx = left_child_idx(current_idx);
            if (right_child_idx(current_idx) < size_) {
                if (heap[right_child_idx(current_idx)] < heap[max_child_idx]) {
                    max_child_idx = right_child_idx(current_idx);
                }
            }
        }
        if (heap[max_child_idx] > heap[current_idx]) {
            T temp = heap[max_child_idx];
            heap[max_child_idx] = heap[current_idx];
            heap[current_idx] = temp;
            heapify_down(max_child_idx);
        }
    }
    void restore_heap_from_bottom() {

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
