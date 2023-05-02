#pragma once

#include <memory>

template<typename T>
class PriorityQueueNode {
    typedef std::shared_ptr<PriorityQueueNode<T>> Nodeptr;

public:

    /**
     * @brief Constructs a new PriorityQueueNode object
     * @param data The data to be stored in the node
     */
    PriorityQueueNode(T data) {
        data_ = data;
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
        right_child = new_right_child;
    }

    /**
     * @brief Returns a reference to the left child node
     * @return A reference to the left child node
     */
    const Nodeptr get_left_child() const {
        return left_child;
    }

    /**
     * @brief Returns a reference to the right child node
     * @return A reference to the right child node
     */
    const Nodeptr get_right_child() const {
        return right_child;
    }

    /**
     * @brief Returns a reference to the parent node
     * @return A reference to the parent node
     */
    const Nodeptr get_parent() const {
        return parent_;
    }

    /**
     * @brief Sets a new parent node
     */
    void set_parent(const Nodeptr new_parent) {
        parent_ = new_parent;
    }

    /**
     * @brief Returns a reference to the data stored in the node
     * @return A reference to the data stored in the node
     */
    const T& get_data() const {
        return data_;
    }

private:
    T data_; /**< The data stored in the node */
    Nodeptr parent_; /**<The parent node */
    Nodeptr left_child; /**< A shared pointer to the left child of the node */
    Nodeptr right_child; /**< A shared pointer to the right child of the node */
};