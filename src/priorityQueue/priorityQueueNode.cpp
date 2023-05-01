#include "priorityQueueNode.hpp"

#pragma once

#include <memory>


template<typename T>
PriorityQueueNode::PriorityQueueNode(T data, Nodeptr parent) {
    data_ = data;
    parent_ = parent;
    next = nullptr;
}

/**
 * @brief Creates a new left child storing data
 * @param data The data to be stored in the new left child
 */
void set_left_child(const T& data) {
    left_child = std::make_shared<PriorityQueueNode<T>>(data, Nodeptr(this))
}

/**
 * @brief Creates a new right child storing data
 * @param data The data to be stored in the new right child
 */
void set_right_child(const T& data) {
    right_child = std::make_shared<PriorityQueueNode<T>>(data, Nodeptr(this))
}

/**
 * @brief Sets the left child node
 * @param new_left_child A shared pointer to the new left child node
 */
void set_left_child(Nodeptr new_left_child) {
    left_child = new_left_child;
}

/**
 * @brief Sets the right child node
 * @param new_right_child A shared pointer to the new right child node
 */
void set_right_child(Nodeptr new_right_child) {
    right_child = new_left_child;
}

/**
 * @brief Returns a const reference to the left child node
 * @return A const reference to the left child node
 */
const Nodeptr get_left_child() const {
    return left_child;
}

/**
 * @brief Returns a const reference to the right child node
 * @return A const reference to the right child node
 */
const Nodeptr get_right_child() const {
    return right_child;
}

/**
 * @brief Returns a const reference to the parent node
 * @return A const reference to the parent node
 */
const Nodeptr get_parent() const {
    return parent_;
}

void set_parent(const Nodeptr new_parent) {
    parent_ = new_parent;
}

/**
 * @brief Returns a const reference to the data stored in the node
 * @return A const reference to the data stored in the node
 */
const T& get_data() const {
    return data_;
}

