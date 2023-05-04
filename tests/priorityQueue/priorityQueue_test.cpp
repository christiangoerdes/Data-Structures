#include <gtest/gtest.h>
#include "../../include/container/linkedList/doublyLinkedList/doublyLinkedList.hpp"
#include "../../include/container/priorityQueue/priorityQueue.hpp"

TEST(PriorityQueueTest, InsertionAndRemoval) {
PriorityQueue<int> queue;

// Empty initialization
ASSERT_EQ(queue.get_size(), 0);

// Insert an element
queue.push(1);
ASSERT_EQ(queue.get_size(), 1);
ASSERT_EQ(*queue.get_front(), 1);
ASSERT_EQ(*queue.get_back(), 1);


// Insert elements of higher priority
queue.push(2);
queue.push(3);
ASSERT_EQ(queue.get_size(), 3);
ASSERT_EQ(*queue.get_front(), 3);

// Insert an element of lower priority
queue.push(0);
ASSERT_EQ()

// Remove the element after a given node
iter = list.get_front();
list.remove(iter.get_pointer() -> get_next());
ASSERT_EQ(list.get_size(), 1);
ASSERT_EQ(*list.get_front(), "3");
ASSERT_EQ(*list.get_end(), "3");

// Remove the last element from the list
list.remove(iter);
ASSERT_EQ(list.get_size(), 0);
ASSERT_TRUE(list.is_empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}