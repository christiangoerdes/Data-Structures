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
    DoublyLinkedListIterator<T> get_end() const override {
        return DoublyLinkedListIterator<T>(tail);
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

    // inserts a new element after a specified iterator
    void insert_after(DoublyLinkedListIterator<T> predecessor, const T& t) override {
        insert_after(predecessor.get_pointer(), t);
    }

    void insert_end(const T& t) override {
        if(size == 0) {
            insert_front(t);
        }else{
            insert_after(tail, t);
        }
    }

    // removes a specified node from the list
    void remove(const std::shared_ptr<DoublyLinkedListNode<T>>& node) override {
        auto predecessor = node->get_prev().lock();
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

    // removes a specified node from the list
    void remove (DoublyLinkedListIterator<T> node) override {
        remove(node.get_pointer());
    }

    // prints the contents of the list to the console
    void print() const {
        std::shared_ptr<DoublyLinkedListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr =curr->get_next();
        }
    }

    // returns a shared pointer to the head of the list
    std::shared_ptr<DoublyLinkedListNode<T>> get_head() const {
        return head;
    }

    // returns whether the list is empty
    bool is_empty() const override {
        return size == 0;
    }

private:
    size_t size;
    std::shared_ptr<DoublyLinkedListNode<T>> head;
    std::shared_ptr<DoublyLinkedListNode<T>> tail;
};
