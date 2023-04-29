/**
 * @file listNode.cpp
 * @brief Implementation of the ListNode class
 */

#pragma once
#include <memory>

/**
 * @class ListNode
 * @brief Abstract base class for linked list nodes
 * @tparam T Type of data stored in the node
 */
template <typename T>
class ListNode {
public:
    /**
     * @brief Get the data stored in the node
     * @return A const reference to the data
     */
    virtual const T& get_data() const {
        return data;
    }

    /**
     * @brief Set the data stored in the node
     * @param newData The new data to store in the node
     */
    virtual void set_data(const T& newData) {
        data = newData;
    }

protected:
    T data; ///< Data stored in the node
};
