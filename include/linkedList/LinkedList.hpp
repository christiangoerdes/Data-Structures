/**
 * @file abstractLinkedList.hpp
 * @brief A class representing the abstract base class for linked list data structures
 */

#pragma once

#include "listNode.hpp"
#include "listIterator.hpp"

/**
 * @brief A class representing the abstract base class for linked list data structures
 *
 * This class defines the interface that must be implemented by any derived linked list classes.
 *
 * @tparam T The type of the elements stored in the linked list
 */
template <typename T>
class AbstractLinkedList {

public:

    /**
     * @brief Returns the number of elements in the linked list
     *
     * @return The number of elements in the linked list
     */
    virtual size_t get_size() const = 0;

    /**
     * @brief Inserts a new element at the front of the linked list
     *
     * @param t The new element to insert
     */
    virtual void insert_front(const T& t) = 0;
};