#include <gtest/gtest.h>
#include "../../include/container/queue/queue.hpp"

// Unit tests for Queue
TEST(QueueTest, InsertionAndRemoval) {
    Queue<std::string> queue;
    ASSERT_EQ(queue.get_size(), 0);
    ASSERT_EQ(queue.is_empty(), true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
