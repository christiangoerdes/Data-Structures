#pragma once

#include <priorityQueue/abstractPriorityQueue.hpp>

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

    PriorityQueueIterator<T> get_front() const override {
        // noch implementieren
    }

    void push(const T& t) override {
        // noch falsch implementiert, da Heapify fehlt

        PQueueNodePtr new_node = std::make_shared<PriorityQueueNode<T>>(t);

        SinglyLinkedList<int> bit_list;

        for (int dec = size_ + 1; dec > 1; dec /= 2) { // finding the leftmost free spot at the bottom of the heap
            bit_list.insert_front(dec % 2);
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
        size_ += 1;
    }

    PQueueNodePtr top() const override {
        return root;
    }

    PQueueNodePtr pop() override {
        // noch falsch implementiert, da Heapify fehlt
        // find the leftmost node at the bottom of the heap
        SinglyLinkedList<int> bit_list;

        for (int dec = size_ + 1; dec > 1; dec /= 2) { // finding the leftmost free spot at the bottom of the heap
            bit_list.insert_front(dec % 2);
        }

        PQueueNodePtr current_node = root;
        for (int x : bit_list.front()) { // do I really need to write "front" here? Gotta ask Chris
            bit_list.remove_front();
            if (bit_list.empty()) { // the node can now be inserted at the correct position
                if (x == 0) {
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
                if (x == 0) {
                    current_node = current_node->get_left_child();
                }
                else {
                    current_node = current_node->get_right_child();
                }
            }
        }
    }
private:
    size_t size_;
    PQueueNodePtr root;
};