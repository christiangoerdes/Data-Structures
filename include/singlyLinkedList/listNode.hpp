#pragma once
#include <memory>

template <typename T>
class ListNode {
public:
    /**
     * @brief Constructor for the ListNode class
     * @param data Data to be stored in the node
     */
    ListNode(T newData)  {
        data = newData;
        next = nullptr;
    }

    /**
     * @brief Returns a shared_ptr to the next node in the list
     * @return Shared_ptr to the next node
     */
    std::shared_ptr<ListNode<T>> get_next() const {
        return next;
    }

    /**
     * @brief Returns the data stored in the node
     * @return Data stored in the node
     */
    const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the next node in the list
     * @param nextNode Shared_ptr to the next node in the list
     */
    void set_next(std::shared_ptr<ListNode<T>> nextNode) {
        next = nextNode;
    }

    /**
     * @brief Sets the data stored in the node
     * @param newData Data to be stored in the node
     */
    void set_data(const T& newData) {
        data = newData;
    }

private:
    T data; /**< Data stored in the node */
    std::shared_ptr<ListNode<T>> next; /**< Shared_ptr to the next node in the list */
};
