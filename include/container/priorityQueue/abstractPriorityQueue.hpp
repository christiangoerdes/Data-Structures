#pragma once

#include "../container.hpp"
#include "priorityQueueIterator.hpp"
#include "priorityQueue.tpp"
#include <memory>

template<typename T>
class AbstractPriorityQueue : public Container {
public:

    /**
     * @brief Returns an iterator pointing at the element with the highest priority
     * @return An iterator pointing at the max element in the queue
     */
    virtual PriorityQueueIterator<T> get_front() const = 0;

    /**
     * @brief Returns an iterator pointing at the last element in the priority queue
     * @return An iterator pointing at the last element in the priority queue
     */
    virtual PriorityQueueIterator<T> get_back() const = 0;

    /**
     * @brief Insert a new element into the queue
     * @param t Data to be stored in the new element
     */
    virtual void push(const T& t) = 0;

    /**
     * @brief Get element with the highest priority
     */
    virtual const T& top() const = 0;

    /**
     * @brief Remove element with the highest priority
     */
    virtual const T& pop() = 0;
};

#include "priorityQueue.tpp"