#include <gtest/gtest.h>
#include "../../include/container/linkedList/singlyLinkedList/singlyLinkedList.hpp"

// Unit tests for SinglyLinkedList
TEST(SinglyLinkedListTest, InsertionAndRemoval) {
    SinglyLinkedList<std::string> list;
    ASSERT_EQ(list.get_size(), 0);

    // Insert elements at the front of the list
    list.insert_front("1");
    ASSERT_EQ(list.get_size(), 1);
    ASSERT_EQ(*list.get_front(), "1");

    list.insert_front("2");
    ASSERT_EQ(list.get_size(), 2);
    ASSERT_EQ(*list.get_front(), "2");

    // Insert element after a given node
    auto iter = list.get_front();
    list.insert_after(iter, "3");
    ASSERT_EQ(list.get_size(), 3);
    ASSERT_EQ(*(++iter), "3");

    // Remove the element after a given node
    iter = list.get_front();
    list.remove_after(iter);
    ASSERT_EQ(list.get_size(), 2);
    ASSERT_EQ(*(++iter), "1");

    // Remove an element from the front of the list
    list.remove_front();
    ASSERT_EQ(list.get_size(), 1);
    ASSERT_EQ(*list.get_front(), "1");

    // Remove the last element from the list
    list.remove_front();
    ASSERT_EQ(list.get_size(), 0);
    ASSERT_TRUE(list.is_empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}