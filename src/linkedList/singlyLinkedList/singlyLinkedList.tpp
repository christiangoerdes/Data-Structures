#pragma once

#include <iostream>

template <typename T>
class SinglyLinkedList : public AbstractSinglyLinkedList<T> {
public:

    SinglyLinkedList() : size(0), head(nullptr) {}

    size_t get_size() const override {
        return size;
    }


    SinglyLinkedListIterator<T> get_front() const override {
        return SinglyLinkedListIterator<T>(head);
    }


    void insert_front(const T &t) override {
        auto newNode = std::make_shared<SinglyLinkedListNode<T>>(t);
        newNode->set_next(head);
        head = newNode;
        size++;
    }

    void insert_after(const std::shared_ptr<SinglyLinkedListNode<T>> &predecessor, const T &t) override {
        if (!predecessor) {
            throw std::invalid_argument("prev is null");
        }
        auto newNode = std::make_shared<SinglyLinkedListNode<T>>(t);
        newNode->set_next(predecessor->get_next());
        predecessor->set_next(newNode);
        size++;
    }

    void remove_front() override {
        if (!head) {
            throw std::runtime_error("list is empty");
        }
        head = head->get_next();
        size--;
    }

    void remove_after(const std::shared_ptr<SinglyLinkedListNode<T>> &predecessor) override {
        if (!predecessor) {
            throw std::invalid_argument("prev is null");
        }
        auto nodeToRemove = predecessor->get_next();
        if (!nodeToRemove) {
            throw std::invalid_argument("prev has no next node");
        }
        predecessor->set_next(nodeToRemove->get_next());
        size--;
    }

    void print() const {
        std::shared_ptr<SinglyLinkedListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr = curr -> get_next();
        }
    }

    std::shared_ptr<SinglyLinkedListNode<T>> get_head() const {
        return head;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> head; /**< Pointer to the first node in the list */
    size_t size; /**< Number of nodes in the list */
};
