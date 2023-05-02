#pragma once

#include "abstractPriorityQueue.hpp"

template<typename T>
class PriorityQueue : public AbstractPriorityQueue<T> {
    typedef std::shared_ptr<PriorityQueueNode<T>> PQueueNodePtr;
public:
    PriorityQueue() :
            root(nullptr)
    {
        // nothing to do here
    }

    size_t size() const override {
        return size_;
    }

    //PriorityQueueIterator<T> get_front() const override {
        // noch implementieren
    //}

    void push(const T& t) override {
        PQueueNodePtr new_node = std::make_shared<PriorityQueueNode<T>>(t);

        // es wird zwar bestimmt, wo man sich potenziell hinbewegen kann, jedoch ist dann ja die heap-eigenschaft nicht gegeben!
        // also kann man einfach

        SinglyLinkedList<int> bit_list;

        for (int dec = size_ + 1; dec > 1; dec /= 2) { // finding the leftmost free spot at the bottom of the heap
            bit_list.insert_front(dec % 2);
        }

        PQueueNodePtr current_node = root;
        for (auto x = bit_list.get_front(); x != nullptr; x++) { // do I really need to write "front" here? Gotta ask Chris
            bit_list.remove_front();
            if (bit_list.get_size() == 0) { // the node can now be inserted at the correct position
                if (*x == 0) {
                    current_node->set_left_child(new_node);
                }
                else {
                    current_node->set_right_child(new_node);
                }
            }
            else { // further movement down the heap is required
                if (*x == 0) {
                    current_node = current_node->get_left_child();
                }
                else {
                    current_node = current_node->get_right_child();
                }
            }
        }

        heapify(current_node);
        size_ += 1;
    }

    PQueueNodePtr top() const override {
        return root;
    }

    PQueueNodePtr pop() override {
        // find the leftmost node at the bottom of the heap
        SinglyLinkedList<int> bit_list;

        for (int dec = size_ + 1; dec > 1; dec /= 2) { // finding the leftmost free spot at the bottom of the heap
            bit_list.insert_front(dec % 2);
        }

        PQueueNodePtr current_node = root;
        for (auto x = bit_list.get_front(); x != nullptr; x++) {
            bit_list.remove_front();
            if (bit_list.get_size() == 0) { // the node can now be inserted at the correct position
                if (*x == 0) {
                    current_node->get_left_child()->set_left_child(root->get_left_child());
                    current_node->get_left_child()->set_left_child(root->get_right_child());
                    root = current_node->get_left_child();
                    current_node->set_left_child(nullptr);
                }
                else {
                    current_node->get_right_child()->set_left_child(root->get_left_child());
                    current_node->get_right_child()->set_left_child(root->get_right_child());
                    root = current_node->get_right_child();
                    current_node->set_right_child(nullptr);
                }
                size_--;
            }
            else { // further movement down the heap is required
                if (*x == 0) {
                    current_node = current_node->get_left_child();
                }
                else {
                    current_node = current_node->get_right_child();
                }
            }
        }
        // some sort of heapify() call
    }

private:

    /**
     * @brief Handles pointer resetting to restore heap property if violated
     * @param node Starting node. Needs to be bottom-level in order to ensure heap property after the method call
     */
    void heapify(PQueueNodePtr node) {
        while ((node != root) & (node->get_data() > node->get_parent()->get_data())) { // heap property violated
            node->get_parent()->set_left_child(node->get_left_child());
            node->get_parent()->set_right_child(node->get_right_child());
            if (node->get_parent() == root) {
                root = node;
            }
            else { // ensures the existence of the parent node's parent
                if (node->get_parent()->get_parent()->get_left_child() == node->get_parent()) { // if the parent node is the left child of its own parent node, set its parent node's child to the current node
                    node->get_parent()->get_parent()->set_left_child(node);
                }
                else {
                    node->get_parent()->get_parent()->set_right_child(node);
                }
            }
        }
    }

    size_t size_;
    PQueueNodePtr root;
};