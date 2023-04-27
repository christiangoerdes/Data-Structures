#pragma once

#include <iostream>

template <typename T>
class DoublyLinkedList : public AbstractDoublyLinkedList<T> {
public:

    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    size_t get_size() const override {
        return size;
    }


    DoublyLinkedListIterator<T> get_front() const override {
        return DoublyLinkedListIterator<T>(head);
    }

    DoublyLinkedListIterator<T> get_tail() const override {
        return DoublyLinkedListIterator<T>(head);
    }


    void insert_front(const T& t) override {
        auto newNode = std::make_shared<DoublyLinkedListNode<T>>(t);
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

    void insert_after(const std::shared_ptr<DoublyLinkedListNode<T>>& predecessor, const T& t) override {
        auto newNode = std::make_shared<DoublyLinkedListNode<T>>(t);
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

    void remove(const std::shared_ptr<DoublyLinkedListNode<T>>& node) override {
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
        std::shared_ptr<DoublyLinkedListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr = curr -> get_next();
        }
    }

    std::shared_ptr<DoublyLinkedListNode<T>> get_head() const {
        return head;
    }


private:
    size_t size; /**< Number of nodes in the list */
    std::shared_ptr<DoublyLinkedListNode<T>> head; /**< Pointer to the first node in the list */
    std::shared_ptr<DoublyLinkedListNode<T>> tail; /**< Pointer to the last node in the list */
};