#pragma once

#include <iostream>

// SinglyLinkedList class definition that inherits from AbstractSinglyLinkedList
template <typename T>
class SinglyLinkedList : public AbstractSinglyLinkedList<T> {
public:
    // Constructor: initializes size to zero and head to null
    SinglyLinkedList() : size(0), head(nullptr) {}

    // Returns the number of nodes in the list
    size_t get_size() const override {
        return size;
    }

    // Returns an iterator to the first node in the list
    SinglyLinkedListIterator<T> get_front() const override {
        return SinglyLinkedListIterator<T>(head);
    }

    // Inserts a new node with data t at the front of the list
    void insert_front(const T &t) override {
        auto newNode = std::make_shared<SinglyLinkedListNode<T>>(t);
        newNode->set_next(head);
        head = newNode;
        size++;
    }

    // Inserts a new node with data t after the given predecessor node
    void insert_after(const std::shared_ptr<SinglyLinkedListNode<T>> &predecessor, const T &t) override {
        if (!predecessor) {
            throw std::invalid_argument("prev is null");
        }
        auto newNode = std::make_shared<SinglyLinkedListNode<T>>(t);
        newNode->set_next(predecessor->get_next());
        predecessor->set_next(newNode);
        size++;
    }

    void insert_after(SinglyLinkedListIterator<T> predecessor, const T& t) override {
        insert_after(predecessor.get_pointer(), t);
    }

    // Removes the first node in the list
    T remove_front() override {
        if (!head) {
            throw std::runtime_error("list is empty");
        }
        auto tmp = head;
        head = head->get_next();
        size--;
        return tmp->get_data();
    }

    // Removes the node after the given predecessor node
    T remove_after(const std::shared_ptr<SinglyLinkedListNode<T>> &predecessor) override {
        if (!predecessor) {
            throw std::invalid_argument("prev is null");
        }
        auto nodeToRemove = predecessor->get_next();
        if (!nodeToRemove) {
            throw std::invalid_argument("prev has no next node");
        }
        predecessor->set_next(nodeToRemove->get_next());
        size--;
        return nodeToRemove->get_data();
    }

    // Removes the node after the given Iterator
    T remove_after(SinglyLinkedListIterator<T> predecessor) override {
        return remove_after(predecessor.get_pointer());
    }

    // Prints the data in all nodes of the list
    void print() const {
        std::shared_ptr<SinglyLinkedListNode<T>> curr = head;
        while(curr != nullptr) {
            std::cout << curr -> get_data() << ", ";
            curr = curr -> get_next();
        }
    }

    // Returns a shared pointer to the head of the list
    std::shared_ptr<SinglyLinkedListNode<T>> get_head() const {
        return head;
    }

    // returns whether the list is empty
    bool is_empty() const override {
        return size == 0;
    }

private:
    std::shared_ptr<SinglyLinkedListNode<T>> head; /**< Pointer to the first node in the list */
    size_t size; /**< Number of nodes in the list */
};
