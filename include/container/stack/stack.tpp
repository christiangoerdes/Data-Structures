#pragma once

#include <iostream>
#include <cstddef>

template <typename T>
class Stack : public AbstractStack<T> { // Stack class inheriting from the AbstractStack class
public:
    Stack() : size(0) {} // Constructor initializing size to zero

    size_t get_size() const override { // Implementation of get_size() function of abstract class
        return size;
    }

    T pop() override { // Implementation of pop() function of abstract class
        if (list.get_size() < 1) { // Check if stack is empty
            return NULL; // Return null if stack is empty
        }
        T t = list.get_head()->get_data(); // Get data of the head node
        list.remove(list.get_head()); // Remove the head node from the list
        size--;
        return t; // Return the data of the head node
    }

    void push(const T& t) override { // Implementation of push() function of abstract class
        list.insert_front(t); // Insert the new element at the front of the list
        size++;
    }

    bool is_empty() const override { // Implementation of is_empty() function of abstract class
        return list.is_empty(); // Check if the list is empty
    }

private:
    size_t size; // Size of the stack
    DoublyLinkedList<T> list; // Doubly linked list used to implement the stack
};