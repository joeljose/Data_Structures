#include <gtest/gtest.h>
#include <vector>
#include "linked_list.hpp"

class LinkedListTest : public ::testing::Test {
protected:
    LinkedList list;

    void SetUp() override {
        // This will run before each test
        list = LinkedList();
    }
};

TEST_F(LinkedListTest, AppendAndPrepend) {
    list.append(10);
    list.append(20);
    list.prepend(5);
    
    EXPECT_EQ(list.length(), 3);
    EXPECT_TRUE(list.contains(5));
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(20));
}

TEST_F(LinkedListTest, InsertAfter) {
    list.append(10);
    list.append(20);
    list.insert_after(list.find(10), 15);
    
    EXPECT_EQ(list.length(), 3);
    EXPECT_TRUE(list.contains(15));
}

TEST_F(LinkedListTest, DeleteValue) {
    list.append(10);
    list.append(20);
    list.append(30);
    list.delete_value(20);
    
    EXPECT_EQ(list.length(), 2);
    EXPECT_FALSE(list.contains(20));
}

TEST_F(LinkedListTest, DeleteAtPosition) {
    list.append(10);
    list.append(20);
    list.append(30);
    list.delete_at_position(1);
    
    EXPECT_EQ(list.length(), 2);
    EXPECT_FALSE(list.contains(20));
}

TEST_F(LinkedListTest, EmptyList) {
    EXPECT_EQ(list.length(), 0);
    EXPECT_FALSE(list.contains(5));
}

TEST_F(LinkedListTest, SingleElementList) {
    list.append(42);
    EXPECT_EQ(list.length(), 1);
    EXPECT_TRUE(list.contains(42));
    
    list.reverse();
    EXPECT_EQ(list.length(), 1);
    EXPECT_TRUE(list.contains(42));
}

TEST_F(LinkedListTest, Reverse) {
    list.append(10);
    list.append(20);
    list.append(30);
    list.reverse();
    
    std::vector<int> expected = {30, 20, 10};
    EXPECT_EQ(list.to_vector(), expected);
    EXPECT_EQ(list.length(), 3);
}