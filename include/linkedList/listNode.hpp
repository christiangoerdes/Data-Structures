#pragma once
#include <memory>

template <typename T>
class ListNode {
public:

    /**
     * @brief Returns the data stored in the node
     * @return Data stored in the node
     */
     virtual const T& get_data() const {
        return data;
    }

    /**
     * @brief Sets the data stored in the node
     * @param newData Data to be stored in the node
     */
    virtual void set_data(const T& newData) {
        data = newData;
    }

protected:
    T data; /**< Data stored in the node */
};
