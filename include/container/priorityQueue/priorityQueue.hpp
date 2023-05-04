#pragma once

#include "../Container.hpp"
#include <stdexcept>

/**
 * @brief Abstract base class for PriorityQueue
 *
 * This class provides an interface for implementing a PriorityQueue.
 *
 */
template <typename T>
class AbstractPriorityQueue : public Container {
public:
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