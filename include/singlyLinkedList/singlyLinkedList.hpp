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
template<class T>
class AbstractSinglyLinkedList {

public:
    /**
     * @brief Get the size of the list
     * @return The number of nodes in the list
     */
    virtual size_t get_size() = 0;

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    virtual std::shared_ptr<ListNode<T>> get_front() = 0;

    /**
     * @brief Insert a new node containing data at the front of the list
     * @param t Data to be stored in the new node
     */
    virtual void insert_front(T t) = 0;

    /**
     * @brief Insert a new node containing data after the given predecessor node
     * @param predecessor Node after which the new node should be inserted
     * @param t Data to be stored in the new node
     */
    virtual void insert_after(std::shared_ptr<ListNode<T>> predecessor, T t) = 0;

    /**
     * @brief Remove the node at the front of the list
     */
    virtual void remove_front() = 0;

    /**
     * @brief Remove the node after the given predecessor node
     * @param predecessor Node after which the next node should be removed
     */
    virtual void remove_after(std::shared_ptr<ListNode<T>> predecessor) = 0;
};

/**
 * @brief Implementation of a singly linked list
 * @tparam T Type of data stored in the list
 */
template<class T>
class SinglyLinkedList : public AbstractSinglyLinkedList<T> {

public:
    /**
     * @brief Get the size of the list
     * @return The number of nodes in the list
     */
    size_t get_size() override;

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    std::shared_ptr<ListNode<T>> get_front() override;

    /**
     * @brief Insert a new node containing data at the front of the list
     * @param t Data to be stored in the new node
     */
    void insert_front(T t) override;

    /**
     * @brief Insert a new node containing data after the given predecessor node
     * @param predecessor Node after which the new node should be inserted
     * @param t Data to be stored in the new node
     */
    void insert_after(std::shared_ptr<ListNode<T>> predecessor, T t) override;

    /**
     * @brief Remove the node at the front of the list
     */
    void remove_front() override;

    /**
     * @brief Remove the node after the given predecessor node
     * @param predecessor Node after which the next node should be removed
     */
    void remove_after(std::shared_ptr<ListNode<T>> predecessor) override;

private:
    std::shared_ptr<ListNode<T>> head; /**< Pointer to the first node in the list */
    size_t size; /**< Number of nodes in the list */

    /**

    @brief Returns the head of the linked list.
    @return The head of the linked list as a shared pointer to a ListNode<T> object.
    */
        std::shared_ptr<ListNode<T>> get_head();
    /**

    @brief Sets the head of the linked list to a new node.
    @param newHead The new head of the linked list as a shared pointer to a ListNode<T> object.
    */
    void set_head(std::shared_ptr<ListNode<T>> newHead);

};
#endif //PROJEKTALPHA_SINGLYLINKEDLIST_HPP