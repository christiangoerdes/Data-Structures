#include "../../include/singlyLinkedList/listNode.hpp"

template <typename T>
ListNode<T>::ListNode(T data) : data(data), next(nullptr) {}

template <typename T>
std::shared_ptr<ListNode<T>> ListNode<T>::get_next() const{
    return next;
}

template <typename T>
const T& ListNode<T>::get_data() const{
    return data;
}

template <typename T>
void ListNode<T>::set_next(std::shared_ptr<ListNode<T>> nextNode) {
    next = nextNode;
}

template <typename T>
void ListNode<T>::set_data(const T& newData) {
    data = newData;
}