#pragma once

#include "abstractPriorityQueue.hpp"
#include <string>
#include <iostream>
#include <algorithm>

template<typename T>
class PriorityQueue : public AbstractPriorityQueue<T> {
    typedef std::shared_ptr<PriorityQueueNode<T>> PQueueNodePtr;
public:
    PriorityQueue() : size_(0) {
        root = nullptr;
    }

    size_t size() const override {
        return size_;
    }

    //PriorityQueueIterator<T> get_front() const override {
        // noch implementieren
    //}

    void push(const T& t) override {
        PQueueNodePtr new_node = std::make_shared<PriorityQueueNode<T>>(t, nullptr);

        if (size_ == 0) {
            root = new_node;
        }
        else {
            // placing new node at the leftmost free spot in the bottom layer of the heap
            PQueueNodePtr temp = root;
            std::string directions = toBinary(size_ + 1);
            size_t num_digits = directions.length();
            for (int i = 0; i < num_digits - 1; i++) {
                if (directions.at(i) == '0') {
                    temp = temp->get_left_child();
                } else {
                    temp = temp->get_right_child();
                }
            }
            if (directions.at(num_digits - 1) == '0') {
                temp->set_left_child(new_node);
            } else {
                temp->set_right_child(new_node);
            }
            new_node->set_parent(temp);

            // restoring the heap property if violated
            while (new_node != root) {
                if (new_node->get_data() > new_node->get_parent()->get_data()) { // heap property violated
                    swap(new_node->get_parent(), new_node);
                }
            }
        }
        size_++;
    }

    PQueueNodePtr top() const override {
        return root;
    }

    PQueueNodePtr pop() override {

        PQueueNodePtr save = root;

        if (!root) {
            // throw exception
        }
        else {
            // 1: Finding the leftmost (=last) node of the bottom layer of the heap
            PQueueNodePtr temp = root;
            std::string directions = toBinary(size_);
            size_t num_digits = directions.length();
            for (int i = 0; i < num_digits; i++) {
                if (directions.at(i) == '0'){
                    temp = temp->get_left_child();
                }
                else {
                    temp = temp->get_right_child();
                }
            }

            // 2: Replacing root with the last node
            temp->set_left_child(root->get_left_child());
            temp->set_right_child(root->get_right_child());
            if (temp->get_left_child()) {
                temp->get_left_child()->set_parent(temp);
            }
            if (temp->get_right_child()) {
                temp->get_right_child()->set_parent(temp);
            }
            root = temp;
            if (temp->get_parent()->get_left_child() == temp) {
                temp->get_parent()->set_left_child(nullptr);
            }
            else {
                temp->get_parent()->set_right_child(nullptr);
            }
            temp->set_parent(nullptr);

            // 3: restoring the heap property if violated
            while (temp->get_left_child()) { // if any child nodes exist
                if(temp->get_left_child() && temp->get_right_child()) { // if both child nodes exist

                    if (temp->get_left_child()->get_data() > temp->get_data()) { // if left child is of greater priority

                        if (temp->get_left_child()->get_data() > temp->get_right_child()->get_data()) { // if left child is of greatest priority
                            swap(temp, temp->get_left_child()); // swap positions with left child
                        }
                        else {
                            swap(temp, temp->get_right_child()); // swap positions with right child
                        }
                    }
                    else if (temp->get_right_child()->get_data() > temp->get_data()) {
                        swap(temp, temp->get_right_child()); // swap positions with right child
                    }
                    else {
                        break;
                    }
                }
                else if (temp->get_left_child()->get_data() > temp->get_data()) { // if left child is of greater priority
                    swap(temp, temp->get_left_child());
                }
                else {
                    break; // heap property restored
                }
            }
        }
        size_--;
        return save;
    }

private:

    /**
     * @brief Converts an integer to binary in string form. Necessary for finding the last node and/or empty space in the heap's bottom layer
     * @param n An integer
     * @return The binary representation of n in string form
     */
    std::string toBinary(int n) // convert integer to binary in string form
    {
        std::string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        r.erase(0,1);
        return r;
    }

    /**
     * @brief Swaps all relevant pointers between two adjacent nodes in the heap
     * @param x Parent node
     * @param y Child node
     */
    void swap(const PQueueNodePtr& x, const PQueueNodePtr& y) {

        if (x == root) { // reset the root node to y
            root = y;
        }
        else { // determine whether x is the left or right child of its parent and set its parent's new child accordingly
            if (x->get_parent()->get_left_child() == x) {
                x->get_parent()->set_left_child(y);
            }
            else {
                x->get_parent()->set_right_child(y);
            }
        }

        y->set_parent(x->get_parent());
        x->set_parent(y);

        if (y->get_left_child()) {
            y->get_left_child()->set_parent(x);
        }
        if (y->get_right_child()) {
            y->get_right_child()->set_parent(x);
        }

        PQueueNodePtr temp_left = x->get_left_child();
        PQueueNodePtr temp_right = x->get_right_child();

        x->set_left_child(y->get_left_child());
        x->set_right_child(y->get_right_child());

        if (temp_left == y) { // if y is the left child of x
            y->set_left_child(x);
            y->set_right_child(temp_right);
            if (y->get_right_child()) {
                y->get_right_child()->set_parent(y);
            }

        }
        else { // if y is the right child of x
            y->set_left_child(temp_left);
            y->set_right_child(x);
            if (y->get_left_child()) {
                y->get_left_child()->set_parent(y);
            }
        }
    }

    size_t size_;
    PQueueNodePtr root;
};