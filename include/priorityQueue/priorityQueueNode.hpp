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
    PriorityQueueNode(T data, Nodeptr parent);

    /**
     * @brief Creates a new left child storing data
     * @param data The data to be stored in the new left child
     */
    void set_left_child(const T& data);

    /**
     * @brief Creates a new right child storing data
     * @param data The data to be stored in the new right child
     */
    void set_right_child(const T& data);

    /**
     * @brief Sets the left child node
     * @param new_left_child A shared pointer to the new left child node
     */
    void set_left_child(Nodeptr new_left_child);

    /**
     * @brief Sets the right child node
     * @param new_right_child A shared pointer to the new right child node
     */
    void set_right_child(Nodeptr new_right_child);

    /**
     * @brief Returns a const reference to the left child node
     * @return A const reference to the left child node
     */
    const Nodeptr get_left_child() const;

    /**
     * @brief Returns a const reference to the right child node
     * @return A const reference to the right child node
     */
    const Nodeptr get_right_child() const;

    /**
     * @brief Returns a const reference to the data stored in the node
     * @return A const reference to the data stored in the node
     */
    const T& get_data() const;

private:
    T data_; /**< The data stored in the node */
    Nodeptr left_child; /**< A shared pointer to the left child of the node */
    Nodeptr right_child; /**< A shared pointer to the right child of the node */
};

#include <src/priorityQueue/priorityQueueNode.tpp>