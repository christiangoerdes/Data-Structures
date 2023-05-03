#pragma once

#include <memory>

template<typename T>
class PriorityQueueNode {
    typedef std::shared_ptr<PriorityQueueNode<T>> PQueueNodePtr;

public:

    /**
     * @brief Constructs a new PriorityQueueNode object
     * @param data The data to be stored in the node
     */
    PriorityQueueNode(T data, PQueueNodePtr parent) {
        data_ = data;
        parent_ = parent;
    }

    /**
     * @brief Sets the left child node
     * @param new_left_child A shared pointer to the new left child node
     */
    void set_left_child(PQueueNodePtr new_left_child) {
        left_child = new_left_child;
    }

    /**
     * @brief Sets the right child node
     * @param new_right_child A shared pointer to the new right child node
     */
    void set_right_child(PQueueNodePtr new_right_child) {
        right_child = new_right_child;
    }

    /**
     * @brief Returns a reference to the left child node
     * @return A reference to the left child node
     */
    const PQueueNodePtr get_left_child() const {
        return left_child;
    }

    /**
     * @brief Returns a reference to the right child node
     * @return A reference to the right child node
     */
    const PQueueNodePtr get_right_child() const {
        return right_child;
    }

    /**
     * @brief Returns a reference to the parent node
     * @return A reference to the parent node
     */
    const PQueueNodePtr get_parent() const {
        return parent_;
    }

    /**
     * @brief Sets a new parent node
     */
    void set_parent(const PQueueNodePtr new_parent) {
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
    std::string toBinary(int n);
    void swap(PQueueNodePtr x, PQueueNodePtr y);
    T data_; /**< The data stored in the node */
    PQueueNodePtr parent_; /**<The parent node */
    PQueueNodePtr left_child; /**< A shared pointer to the left child of the node */
    PQueueNodePtr right_child; /**< A shared pointer to the right child of the node */
};