#pragma once

#include <iostream>

template <typename T>
class DoublyLinkedList : public AbstractDoublyLinkedList<T> {
public:
    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    // returns the size of the list
    size_t get_size() const override {
        return size;
    }

    // returns an iterator to the first element in the list
    DoublyLinkedListIterator<T> get_front() const override {
        return DoublyLinkedListIterator<T>(head);
    }

    // returns an iterator to the last element in the list
    DoublyLinkedListIterator<T> get_tail() const override {
        return DoublyLinkedListIterator<T>(head);
    }

    // inserts a new element at the front of the list
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

    // inserts a new element after a specified node
    void insert_after(std::shared_ptr<DoublyLinkedListNode<T>> predecessor, const T& t) override {
        auto newNode = std::make_shared<DoublyLinkedListNode<T>>(t);
        auto successor = std::dynamic_pointer_cast<DoublyLinkedListNode<T>>(predecessor->get_next());
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

    // removes a specified node from the list
    void remove(const std::shared_ptr<DoublyLinkedListNode<T>>& node) override {
        auto predecessor = node->get_prev();
        auto successor = std::dynamic_pointer_cast<DoublyLinkedListNode<T>>(node->get_next());
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

    // prints the contents of the list to the console
    void print() const {
        std::shared_ptr<DoublyLinkedListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr = std::dynamic_pointer_cast<DoublyLinkedListNode<T>>(curr->get_next());
        }
    }

    // returns a shared pointer to the head of the list
    std::shared_ptr<DoublyLinkedListNode<T>> get_head() const {
        return head;
    }

private:
    size_t size;
    std::shared_ptr<DoublyLinkedListNode<T>> head;
    std::shared_ptr<DoublyLinkedListNode<T>> tail;
};
