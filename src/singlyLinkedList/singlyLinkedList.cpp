#include "../../include/singlyLinkedList/singlyLinkedList.hpp"

template<class T>
size_t SinglyLinkedList<T>::get_size() {
    return size;
}

template<class T>
std::shared_ptr<ListNode<T>> SinglyLinkedList<T>::get_head() {
    return head;
}

template<class T>
void SinglyLinkedList<T>::set_head(std::shared_ptr<ListNode<T>> newHead) {
    head = newHead;
}

template<class T>
void SinglyLinkedList<T>::get_front() {
    //TODO
}

template<class T>
void SinglyLinkedList<T>::insert_front(T t) {
    auto newNode = std::make_shared<ListNode<T>>(t);
    newNode->set_next(head);
    set_head(newNode);
    size++;
}

template<class T>
void SinglyLinkedList<T>::insert_after(ListNode<T> predecessor, T t) {
    auto newNode = std::make_shared<ListNode<T>>(t);
    newNode->set_next(predecessor.get_next());
    predecessor.set_next(newNode);
    size++;
}

template<class T>
void SinglyLinkedList<T>::remove_front() {
    if (head) {
        set_head(head->get_next());
        size--;
    }
}

template<class T>
void SinglyLinkedList<T>::remove_after(ListNode<T> predecessor) {
    auto nodeToRemove = predecessor.get_next();
    if (nodeToRemove) {
        predecessor.set_next(nodeToRemove->get_next());
        size--;
    }
}