#pragma once

#include "../container.hpp"
#include "priorityQueueIterator.hpp"
#include <memory>

template<typename T>
class AbstractPriorityQueue : public Container {
    typedef std::shared_ptr<PriorityQueueNode<T>> PQueueNodePtr;
public:
    /**
     * @brief Get the size of the queue
     * @return The number of elements in the queue
     */

    /**
     * @brief Returns an iterator pointing at the element with the highest priority
     * @return An iterator pointing at the max element in the queue
     */
    // virtual PriorityQueueIterator<T> get_front() const = 0;

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