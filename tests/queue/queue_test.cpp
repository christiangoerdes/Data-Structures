#include <gtest/gtest.h>
#include "../../include/container/queue/queue.hpp"

// Unit tests for Queue
TEST(QueueTest, InsertionAndRemoval) {
    Queue<int> queue;
    ASSERT_EQ(queue.get_size(), 0);
    ASSERT_EQ(queue.is_empty(), true);

    queue.push(5);
    ASSERT_EQ(queue.pop(), 5);

    queue.push(6);
    queue.push(7);
    ASSERT_EQ(queue.pop(), 6);
    ASSERT_EQ(queue.pop(), 7);

    queue.push(42);
    ASSERT_EQ(queue.is_empty(), false);
    ASSERT_EQ(queue.pop(), 42);

    queue.push(33);
    queue.push(77);
    queue.push(44);
    ASSERT_EQ(queue.get_size(), 3);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
