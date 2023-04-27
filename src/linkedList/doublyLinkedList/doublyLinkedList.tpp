#pragma once

#include <iostream>

template <typename T>
class DoublyLinkedList : public AbstractDoublyLinkedList<T> {
public:

    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    size_t get_size() const override {
        return size;
    }


    ListIterator<T> get_front() const override {
        return ListIterator<T>(head);
    }

    ListIterator<T> get_tail() const override {
        return ListIterator<T>(head);
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

    void print() const {
        std::shared_ptr<ListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr = curr -> get_next();
        }
    }

    std::shared_ptr<ListNode<T>> get_head() const {
        return head;
    }


private:
    size_t size; /**< Number of nodes in the list */
    std::shared_ptr<ListNode<T>> head; /**< Pointer to the first node in the list */
    std::shared_ptr<ListNode<T>> tail; /**< Pointer to the last node in the list */
};