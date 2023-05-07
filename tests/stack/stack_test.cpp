#include <gtest/gtest.h>
#include "../../include/container/stack/stack.hpp"

// Unit tests for Stack
TEST(StackTest, InsertionAndRemoval) {
    Stack<int> stack;
    ASSERT_EQ(stack.get_size(), 0);
    ASSERT_EQ(stack.is_empty(), true);

    stack.push(5);
    ASSERT_EQ(stack.pop(), 5);

    stack.push(6);
    stack.push(7);
    ASSERT_EQ(stack.pop(), 7);
    ASSERT_EQ(stack.pop(), 6);

    stack.push(42);
    ASSERT_EQ(stack.is_empty(), false);
    ASSERT_EQ(stack.pop(), 42);

    stack.push(33);
    stack.push(77);
    stack.push(44);
    ASSERT_EQ(stack.get_size(), 3);

}