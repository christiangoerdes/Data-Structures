#pragma once
#ifndef PROJEKTALPHA_DOUBLYLINKEDLIST_IPP
#define PROJEKTALPHA_DOUBLYLINKEDLIST_IPP

#include "singlyLinkedListInterface.hpp"

/**
 * @brief Implementation of a singly linked list
 * @tparam T Type of data stored in the list
 */
template <typename T>
class SinglyLinkedList : public AbstractSinglyLinkedList<T> {

public:
    /**
     * @brief Get the size of the list
     * @return The number of nodes in the list
     */
    size_t get_size() const  override;

    /**
     * @brief Get an iterator pointing to the first node in the list
     * @return Iterator to the first node
     */
    void get_front() const override; //TODO add the Iterator

    /**
     * @brief Insert a new node containing data at the front of the list
     * @param t Data to be stored in the new node
     */
    void insert_front(const T& t) override;

    /**
     * @brief Insert a new node containing data after the given predecessor node
     * @param predecessor Node after which the new node should be inserted
     * @param t Data to be stored in the new node
     */
    void insert_after(const std::shared_ptr<ListNode<T>>& predecessor, const T& t) override;

    /**
     * @brief Remove the node at the front of the list
     */
    void remove_front() override;

    /**
     * @brief Remove the node after the given predecessor node
     * @param predecessor Node after which the next node should be removed
     */
    void remove_after(const std::shared_ptr<ListNode<T>>& predecessor) override;

private:
    std::shared_ptr<ListNode<T>> head; /**< Pointer to the first node in the list */
    size_t size; /**< Number of nodes in the list */

    /**
    @brief Returns the head of the linked list.
    @return The head of the linked list as a shared pointer to a ListNode<T> object.
    */
    std::shared_ptr<ListNode<T>> get_head() const;

    /**
    @brief Sets the head of the linked list to a new node.
    @param newHead The new head of the linked list as a shared pointer to a ListNode<T> object.
    */
    void set_head(std::shared_ptr<ListNode<T>> newHead);

};


#endif //PROJEKTALPHA_DOUBLYLINKEDLIST_IPP
