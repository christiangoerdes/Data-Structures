#pragma once

#include "priorityQueue.tpp"
#include <memory>

template <typename T>
class PriorityQueueIterator {
public:
    PriorityQueueIterator(std::shared_ptr<PriorityQueue<T>> queue, int idx) : queue_(queue), idx_(idx) {}

    /**
     * @brief Overloaded prefix increment operator
     * @return
     */
    PriorityQueueIterator& operator++() {
        idx_++;
        return *this;
    }

    /**
     * @brief Overloaded postfix increment operator
     * @return
     */
    PriorityQueueIterator<T>& operator++(int) {
        PriorityQueueIterator<T> temp(queue_, idx_);
        idx_++;
        return temp;
    }

    /**
     * @brief Prefix decrement operator
     * @return
     */
    PriorityQueueIterator<T>& operator--() {
        idx_--;
        return *this;
    }

    /**
     * @brief Postfix decrement operator
     * @return
     */
    PriorityQueueIterator<T> operator--(int) {
        PriorityQueueIterator<T> temp(queue_, idx_);
        idx_--;
        return temp;
    }

    /**
     * @brief Dereference operator
     * @return
     */
    const T& operator*() const {
        return queue_->heap[idx_];
    }

    /**
     * @brief Equality operator
     * @return
     */
    bool operator==(const PriorityQueueIterator<T>& other) const {
        return queue_ == other.queue_ && idx_ == other.idx_;
    }

    /**
     * @brief Inequality operator
     * @return
     */
    bool operator!=(const PriorityQueueIterator<T>& other) const {
        return queue_ != other.queue_ | idx_ != other.idx_;
    }

private:
    int idx_;
    std::shared_ptr<PriorityQueue<T>> queue_;
};