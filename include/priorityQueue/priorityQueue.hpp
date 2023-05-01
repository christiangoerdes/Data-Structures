#pragma once

#include <memory>

template<typename T>
class AbstractPriorityQueue {

public:
    /**
     * @brief Get the size of the queue
     * @return The number of elements in the queue
     */
    virtual size_t size() const = 0;

    /**
     * @brief Returns an iterator pointing at the element with the highest priority
     * @return An iterator pointing at the max element in the queue
     */
    virtual PriorityQueueIterator<T> get_front() const = 0;

    /**
     * @brief Insert a new element with priority p
     * @param t Data to be stored in the new element
     */
    virtual void push(const T& t, const size_t p) = 0;

    /**
     * @brief Get element with the highest priority
     */
    virtual void top() const = 0;

    /**
     * @brief Remove element with the highest priority
     */
    virtual void pop() = 0;
};