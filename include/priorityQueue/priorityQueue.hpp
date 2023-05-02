#pragma once

#include "abstractPriorityQueue.hpp"
#include "priorityQueueNode.hpp"

template<typename T>
class PriorityQueue : public AbstractPriorityQueue {
    typedef std::shared_ptr<PriorityQueueNode<T>> PQueueNodePtr;
public:
    PriorityQueue() : 
    root(nullptr)
    {
        // nothing to do here
    }

    size_t size() const override {
        return size;
    }

    PriorityQueueIterator<T> get_front() const override {
        // noch implementieren
    }

    void push(const T& t) override {

        PQueueNodePtr new_node = std::make_shared<PriorityQueueNode<T>>(t);

        SinglyLinkedList<int> bit_list;

        for (dec = size+1; dec > 1; dec /= 2) { // finding the leftmost free spot at the bottom of the heap
            bit_list.insert_front(dec % 2)
        }

        PQueueNodePtr current_node = root;
        for (int x : bit_list.front()) { // do I really need to write "front" here? Gotta ask Chris
            bit_list.remove_front();
            if (bit_list.empty()) { // the node can now be inserted at the correct position
                if (x == 0) {
                    current_node->set_left_child(new_node);
                }
                else {
                    current_node->set_right_child(new_node);
                }
            }
            else { // further movement down the heap is required
                if (x == 0) {
                    current_node = current_node->get_left_child();
                }
                else {
                    current_node = current_node->get_right_child();
                }
            }
        }
    }

    PQueueNodePtr top() const override {
        return root;
    }

    PQueueNodePtr pop() const override {

    }

private:
    size_t size;
    PQueueNodePtr root;
};