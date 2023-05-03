/**
 * @file doublyLinkedList.hpp
 * @brief Header file for the AbstractQueue class
 */

#pragma once

#include "../sequenceContainer.hpp"
#include "../linkedList/doublyLinkedList/doublyLinkedList.hpp"

template <typename T>
class AbstractQueue : public SequenceContainer {
public:

    /*
     * @brief Pops item and returns it
     *
     * @return T An object of the type T
     */
    virtual T pop() const = 0;
};
