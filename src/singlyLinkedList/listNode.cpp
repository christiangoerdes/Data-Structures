#include "../../include/singlyLinkedList/listNode.hpp"

template<class T>
ListNode<T>::ListNode(T data) : data(data), next(nullptr) {}

template<class T>
std::shared_ptr<ListNode<T>> ListNode<T>::get_next() {
    return next;
}

template<class T>
T ListNode<T>::get_data() {
    return data;
}

template<class T>
void ListNode<T>::set_next(std::shared_ptr<ListNode<T>> nextNode) {
    next = nextNode;
}

template<class T>
void ListNode<T>::set_data(T newData) {
    data = newData;
}