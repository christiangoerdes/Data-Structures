/**
 * @file doublyLinkedList.hpp
 * @brief Header file for the AbstractStack class
 */

#pragma once

#include "../Container.hpp"
#include "../linkedList/doublyLinkedList/doublyLinkedList.hpp"
#include <cstddef>

/**
 * @brief Abstract base class for Stack
 *
 * This class provides an interface for implementing a Stack.
 *
 */
template <typename T>
class AbstractStack : public Container {
public:

    /**
     * @brief Pops item and returns it
     *
     * @return T An object of the type T
     */
    virtual T pop() = 0;

    /**
     * @brief Pushes new item of type T
     *
     * @param t Item of type T to insert
     */
    virtual void push(const T& t) = 0;
};

#include "stack.tpp"
