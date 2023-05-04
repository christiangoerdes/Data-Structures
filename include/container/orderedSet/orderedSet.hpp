#pragma once

#include "../container.hpp"
#include "orderedSetIterator.hpp"

/**
 * @brief Abstract base class for Ordered Set
 *
 * This class provides an interface for implementing an ordered set.
 * It inherits from the Container class and defines abstract methods
 * for inserting and removing elements from the set, checking whether the
 * set contains any specific elements, or returning an iterator.
 *
 * @tparam T The type of data to be stored in the ordered set
 */
template<typename T>
class AbstractOrderedSet : public Container {

    /**
     * @brief Returns an iterator of the ordered set
     *
     * @return An iterator of the ordered set
     */
    virtual OrderedSetIterator<T> get_first() const = 0;


    /**
     * @brief Inserts a new element into the set
     *
     * @param t Element to be inserted
     */
    virtual void insert(T& t) = 0;

    /**
     * @brief Checks whether the set contains a specific element
     *
     * @param t Element to be looked for
     * @return True iff the set contains the element in question
     */
    virtual bool contains(T& t) const = 0;

    /**
     * @brief Removes an element from the set
     *
     * @param t Element to be removed
     */
    virtual void remove(T& t) = 0;

};