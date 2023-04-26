/**
 * @file singlyLinkedList.hpp
 * @brief Header file for a singly linked list implementation
 */

#ifndef PROJEKTALPHA_SINGLYLINKEDLIST_HPP
#define PROJEKTALPHA_SINGLYLINKEDLIST_HPP

#include "listNode.hpp"
#include <iterator>

/**
 * @brief Abstract interface for a singly linked list
 * @tparam T Type of data stored in the list
 */
template <typename T>
class AbstractSinglyLinkedList {

public:
    /**
     * @brief Get the size of the list
     * @return The number of nodes in the list
     */
    virtual size_t get_size() const = 0;

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    virtual void get_front() const = 0; //TODO add the Iterator

    /**
     * @brief Insert a new node containing data at the front of the list
     * @param t Data to be stored in the new node
     */
    virtual void insert_front(const T& t) = 0;

    /**
     * @brief Insert a new node containing data after the given predecessor node
     * @param predecessor Node after which the new node should be inserted
     * @param t Data to be stored in the new node
     */
    virtual void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) = 0;

    /**
     * @brief Remove the node at the front of the list
     */
    virtual void remove_front() = 0;

    /**
     * @brief Remove the node after the given predecessor node
     * @param predecessor Node after which the next node should be removed
     */
    virtual void remove_after(const std::shared_ptr<ListNode<T>>& predecessor) = 0;
};

template <typename T>
class SinglyLinkedList : public AbstractSinglyLinkedList<T> {
public:
    size_t get_size() const override {
        return size;
    }


    void get_front() const override {
        //TODO
    }


    void insert_front(const T &t) override {
        auto newNode = std::make_shared<ListNode<T>>(t);
        newNode->set_next(head);
        head = newNode;
        size++;
    }

    void insert_after(const std::shared_ptr<ListNode<T>> &predecessor, const T &t) override {
        if (!predecessor) {
            throw std::invalid_argument("predecessor is null");
        }
        auto newNode = std::make_shared<ListNode<T>>(t);
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

    void remove_after(const std::shared_ptr<ListNode<T>> &predecessor) override {
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

private:
    std::shared_ptr<ListNode<T>> head; /**< Pointer to the first node in the list */
    size_t size; /**< Number of nodes in the list */
};

#include "../../src/singlyLinkedList/singlyLinkedList.tpp"

#endif //PROJEKTALPHA_SINGLYLINKEDLIST_HPP