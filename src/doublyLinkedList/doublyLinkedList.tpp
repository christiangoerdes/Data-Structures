#pragma once

template <typename T>
class DoublyLinkedList : public AbstractDoublyLinkedList<T> {
public:

    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    size_t get_size() const override {
        return size;
    }

    void get_front() const override { //TODO add the Iterator

    }

    void get_tail() const override { //TODO add the Iterator

    }

    void insert_front(const T& t) override {
        auto newNode = std::make_shared<ListNode<T>>(t);
        if (size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->set_next(head);
            head->set_prev(newNode);
            head = newNode;
        }
        size++;
    }

    void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) override {
        auto newNode = std::make_shared<ListNode<T>>(t);
        auto successor = predecessor->get_next();
        predecessor->set_next(newNode);
        newNode->set_prev(predecessor);
        if (successor) {
            successor->set_prev(newNode);
            newNode->set_next(successor);
        } else {
            tail = newNode;
        }
        size++;
    }

    void remove(const std::shared_ptr<ListNode<T>>& node) override {
        auto predecessor = node->get_prev();
        auto successor = node->get_next();
        if (predecessor) {
            predecessor->set_next(successor);
        } else {
            head = successor;
        }
        if (successor) {
            successor->set_prev(predecessor);
        } else {
            tail = predecessor;
        }
        size--;
    }

private:
    size_t size; /**< Number of nodes in the list */
    std::shared_ptr<ListNode<T>> head; /**< Pointer to the first node in the list */
    std::shared_ptr<ListNode<T>> tail; /**< Pointer to the last node in the list */
};