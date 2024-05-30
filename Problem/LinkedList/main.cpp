#include <gtest/gtest.h>
#include "SimpleList.h"

// Test fixture for LinkedList
class LinkedListTest : public ::testing::Test {
protected:
    LinkedList<int> singlyList;
    LinkedList<int> doublyList;
    LinkedList<int> circularList;

    LinkedListTest() 
        : singlyList(Singly), doublyList(Doubly), circularList(Circular) {}

    void SetUp() override {
        singlyList.ListAddNodeAtEnd(1);
        singlyList.ListAddNodeAtEnd(2);
        singlyList.ListAddNodeAtEnd(3);

        doublyList.ListAddNodeAtEnd(1);
        doublyList.ListAddNodeAtEnd(2);
        doublyList.ListAddNodeAtEnd(3);

        circularList.ListAddNodeAtEnd(1);
        circularList.ListAddNodeAtEnd(2);
        circularList.ListAddNodeAtEnd(3);
    }
};

TEST_F(LinkedListTest, ListAddNodeAtEnd) {
    singlyList.ListAddNodeAtEnd(4);
    doublyList.ListAddNodeAtEnd(4);
    circularList.ListAddNodeAtEnd(4);

    EXPECT_EQ(singlyList.getHead()->GetNext()->GetNext()->GetNext()->getData(), 4);
    EXPECT_EQ(doublyList.getHead()->GetNext()->GetNext()->GetNext()->getData(), 4);
    EXPECT_EQ(circularList.getHead()->GetNext()->GetNext()->GetNext()->getData(), 4);
}

TEST_F(LinkedListTest, ListAddNodeAtBeginning) {
    singlyList.ListAddNodeAtBeginning(0);
    doublyList.ListAddNodeAtBeginning(0);
    circularList.ListAddNodeAtBeginning(0);

    EXPECT_EQ(singlyList.getHead()->getData(), 0);
    EXPECT_EQ(doublyList.getHead()->getData(), 0);
    EXPECT_EQ(circularList.getHead()->getData(), 0);
}

TEST_F(LinkedListTest, ListRemoveNodeAtEnd) {
    singlyList.ListRemoveNodeAtEnd();
    doublyList.ListRemoveNodeAtEnd();
    circularList.ListRemoveNodeAtEnd();

    EXPECT_EQ(singlyList.getHead()->GetNext()->GetNext(), nullptr);
    EXPECT_EQ(doublyList.getHead()->GetNext()->GetNext(), nullptr);
    EXPECT_EQ(circularList.getHead()->GetNext()->GetNext(), nullptr);
}

TEST_F(LinkedListTest, ListRemoveNodeAtBeginning) {
    singlyList.ListRemoveNodeAtBeginning();
    doublyList.ListRemoveNodeAtBeginning();
    circularList.ListRemoveNodeAtBeginning();

    EXPECT_EQ(singlyList.getHead()->getData(), 2);
    EXPECT_EQ(doublyList.getHead()->getData(), 2);
    EXPECT_EQ(circularList.getHead()->getData(), 2);
}

TEST_F(LinkedListTest, CopyConstructor) {
    LinkedList<int> copyList(singlyList);

    EXPECT_EQ(copyList.getHead()->getData(), singlyList.getHead()->getData());
    EXPECT_EQ(copyList.getHead()->GetNext()->getData(), singlyList.getHead()->GetNext()->getData());
    EXPECT_EQ(copyList.getHead()->GetNext()->GetNext()->getData(), singlyList.getHead()->GetNext()->GetNext()->getData());
}

TEST_F(LinkedListTest, CopyAssignmentOperator) {
    LinkedList<int> copyList = singlyList;

    EXPECT_EQ(copyList.getHead()->getData(), singlyList.getHead()->getData());
    EXPECT_EQ(copyList.getHead()->GetNext()->getData(), singlyList.getHead()->GetNext()->getData());
    EXPECT_EQ(copyList.getHead()->GetNext()->GetNext()->getData(), singlyList.getHead()->GetNext()->GetNext()->getData());
}

TEST_F(LinkedListTest, MoveConstructor) {
    LinkedList<int> moveList(std::move(singlyList));

    EXPECT_EQ(moveList.getHead()->getData(), 1);
    EXPECT_EQ(moveList.getHead()->GetNext()->getData(), 2);
    EXPECT_EQ(moveList.getHead()->GetNext()->GetNext()->getData(), 3);
    EXPECT_EQ(singlyList.getHead(), nullptr);
}

TEST_F(LinkedListTest, MoveAssignmentOperator) {
    LinkedList<int> moveList = std::move(singlyList);

    EXPECT_EQ(moveList.getHead()->getData(), 1);
    EXPECT_EQ(moveList.getHead()->GetNext()->getData(), 2);
    EXPECT_EQ(moveList.getHead()->GetNext()->GetNext()->getData(), 3);
    EXPECT_EQ(singlyList.getHead(), nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
