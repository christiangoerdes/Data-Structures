#pragma once

#include "../container.hpp"
#include <cstddef>

/**
 * @brief Abstract base class for Unordered Set
 *
 * This class provides an interface for implementing an unordered set.
 * It inherits from the Container class and defines abstract methods
 * for inserting and removing elements from the set, checking whether the
 * set contains any specific elements, or returning an iterator.
 *
 * @tparam T The type of data to be stored in the ordered set
 */
template<typename T>
class AbstractUnorderedSet : public Container {

    /**
     * @brief Inserts a new element into the set
     *
     * @param t Element to be inserted
     */
    virtual void insert(const T& value) = 0;

    /**
     * @brief Checks whether the set contains a specific element
     *
     * @param t Element to be looked for
     * @return True iff the set contains the element in question
     */
    virtual bool contains(const T& value) const = 0;

    /**
     * @brief Removes an element from the set
     *
     * @param t Element to be removed
     */
    virtual void remove(const T& value) = 0;

};

#include "unorderedSet.tpp"
