#pragma once

#include <vector>
#include <functional>
#include "priorityQueue.hpp"

template<typename T>
class PriorityQueue : public AbstractPriorityQueue<T> {

public:

    PriorityQueue() : size_(0), heap(std::vector<T>()) {
        cmp_ = [] (const T& a, const T& b) -> bool {return a < b;};
    }

    PriorityQueue(std::function<bool(const T&, const T&)> cmp) : size_(0), heap(std::vector<T>()), cmp_(cmp) {
        // alternativer Konstruktor mit Weitterreichung einer Compare-Funktion
    }

    size_t get_size() const override {
        return size_;
    }

    bool is_empty() const override {
        return size_ == 0;
    }

    void push(const T& t) override {
        heap.push_back(t);
        size_++;
        heapify_up(heap.size()-1);
    }

    const T& top() const override {
        if (size_ == 0) {
            throw std::out_of_range( "Tried to access empty PriorityQueue." );
        }
        else {
            return heap[0];
        }
    }

    const T pop() override {
        if (size_ == 0) {
            throw std::out_of_range( "Tried to access empty PriorityQueue" );
        }
        else {
            T save = heap[0];
            heap[0] = heap[size_-1];;
            size_--;
            heap.pop_back();
            heapify_down(0);
            return save;
        }
    }

private:

    /**
     * @brief Restores the heap property by going downwards from idx
     * @param idx Index of the start node
     */
    void heapify_down(int idx) {
        int max_child_idx = idx;
        if (left_child_idx(idx) < size_) {
            max_child_idx = left_child_idx(idx);
            if (right_child_idx(idx) < size_) {

                if (cmp_(heap[max_child_idx], heap[right_child_idx(idx)])) {
                    max_child_idx = right_child_idx(idx);
                }
            }
        }
        if (cmp_(heap[idx], heap[max_child_idx])) {
            T temp = heap[max_child_idx];
            heap[max_child_idx] = heap[idx];
            heap[idx] = temp;
            heapify_down(max_child_idx);
        }
    }

    /**
     * @brief Restores the heap property by going upwards from idx
     * @param idx Index of the start node
     */
    void heapify_up(int idx) {
        if (idx > 0) {
            int parent = parent_idx(idx);
            if (cmp_(heap[parent], heap[idx])) {
                T temp = heap[parent];
                heap[parent] = heap[idx];
                heap[idx] = temp;
                heapify_up(parent);
            }
        }
    }

    /**
     * @brief Returns the index of the left child of idx
     * @param idx Current index
     * @return Index of the left child
     */
    int left_child_idx(int idx) {
        return 2*idx+1;
    }

    /**
     * @brief Returns the index of the right child of idx
     * @param idx Current index
     * @return Index of the right child
     */
    int right_child_idx(int idx) {
        return 2*idx+2;
    }

    /**
     * @brief Returns the index of the parent of idx
     * @param idx Current index
     * @return Index of the parent
     */
    int parent_idx(int idx) {
        return (idx-1)/2;
    }

    size_t size_;
    std::vector<T> heap;
    std::function<bool(const T&, const T&)> cmp_;
};
