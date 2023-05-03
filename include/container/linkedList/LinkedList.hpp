/**
 * @file abstractLinkedList.hpp
 * @brief A class representing the abstract base class for linked list data structures
 */

#pragma once

#include "../container.hpp"

/**
 * @brief A class representing the abstract base class for linked list data structures
 *
 * This class defines the interface that must be implemented by any derived linked list classes.
 *
 * @tparam T The type of the elements stored in the linked list
 */
template <typename T>
class AbstractLinkedList : public Container {

public:

    /**
     * @brief Inserts a new element at the front of the linked list
     *
     * @param t The new element to insert
     */
    virtual void insert_front(const T& t) = 0;
};