#include "../../include/singlyLinkedList/singlyLinkedList.ipp"

template <typename T>
size_t SinglyLinkedList<T>::get_size() const {
    return size;
}

template <typename T>
std::shared_ptr<ListNode<T>> SinglyLinkedList<T>::get_head() const {
    return head;
}

template <typename T>
void SinglyLinkedList<T>::set_head(std::shared_ptr<ListNode<T>> newHead) {
    head = newHead;
}

template <typename T>
void SinglyLinkedList<T>::get_front() const{
    //TODO
}

template <typename T>
void SinglyLinkedList<T>::insert_front(const T& t) {
    auto newNode = std::make_shared<ListNode<T>>(t);
    newNode->set_next(head);
    set_head(newNode);
    size++;
}

template <typename T>
void SinglyLinkedList<T>::insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) {
    if (!predecessor) {
        throw std::invalid_argument("predecessor is null");
    }
    auto newNode = std::make_shared<ListNode<T>>(t);
    newNode->set_next(predecessor->get_next());
    predecessor->set_next(newNode);
    size++;
}

template <typename T>
void SinglyLinkedList<T>::remove_front() {
    if (!head) {
        throw std::runtime_error("list is empty");
    }
    set_head(head->get_next());
    size--;
}

template <typename T>
void SinglyLinkedList<T>::remove_after(const std::shared_ptr<ListNode<T>>& predecessor) {
    if (!predecessor) {
        throw std::invalid_argument("predecessor is null");
    }
    auto nodeToRemove = predecessor->get_next();
    if (!nodeToRemove) {
        throw std::invalid_argument("predecessor has no next node");
    }
    predecessor->set_next(nodeToRemove->get_next());
    size--;
}