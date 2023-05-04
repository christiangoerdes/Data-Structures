#include <gtest/gtest.h>
#include "../../include/container/priorityQueue/priorityQueue.hpp"

TEST(PriorityQueueTest, InsertionAndRemoval) {
PriorityQueue<int> queue;

// Empty initialization
ASSERT_EQ(queue.get_size(), 0);

// Insert an element
queue.push(1);
ASSERT_EQ(queue.get_size(), 1);
ASSERT_EQ(queue.top(), 1);

// Insert elements of higher priority
queue.push(2);
queue.push(3);
ASSERT_EQ(queue.get_size(), 3);
ASSERT_EQ(queue.top(), 3);

// Insert an element of lower priority
queue.push(0);
ASSERT_EQ(queue.top(), 3);

// Remove elements with highest priority
queue.pop();
ASSERT_EQ(queue.top(), 2);
queue.pop();
ASSERT_EQ(queue.top(), 1);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}