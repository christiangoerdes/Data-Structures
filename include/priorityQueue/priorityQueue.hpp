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
     * @brief Get an iterator pointing to the element with the highest priority
     * @return Iterator to the element with highest priority
     */
    virtual void get_first_element() const = 0;

    /**
     * @brief Insert a new element with priority p
     * @param t Data to be stored in the new element
     */
    virtual void add(const T& t, const size_t p) = 0;

    /**
     * @brief Get element with the highest priority
     */
    virtual void get_highest() const = 0;

    /**
     * @brief Remove element with the highest priority
     */
    virtual void remove_highest() = 0;
};