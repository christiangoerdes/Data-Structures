#include <gtest/gtest.h>
#include "../../include/container/linkedList/doublyLinkedList/doublyLinkedList.hpp"

// Unit tests for DoublyLinkedList
TEST(DoublyLinkedListTest, InsertionAndRemoval) {
DoublyLinkedList<std::string> list;
ASSERT_EQ(list.get_size(), 0);

// Insert elements at the front of the list
list.insert_front("1");
ASSERT_EQ(list.get_size(), 1);
ASSERT_EQ(*list.get_front(), "1");
ASSERT_EQ(*list.get_end(), "1");

list.insert_front("2");
ASSERT_EQ(list.get_size(), 2);
ASSERT_EQ(*list.get_front(), "2");
ASSERT_EQ(*list.get_end(), "1");

// Insert element after a given node
auto iter = list.get_front();
list.insert_after(iter, "3");
ASSERT_EQ(list.get_size(), 3);
ASSERT_EQ(*iter, "2");
ASSERT_EQ(*(++iter), "3");
ASSERT_EQ(*(++iter), "1");

// Remove an element from the front of the list
iter = list.get_front();
list.remove(iter);
ASSERT_EQ(list.get_size(), 2);
ASSERT_EQ(*list.get_front(), "3");
ASSERT_EQ(*list.get_end(), "1");

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