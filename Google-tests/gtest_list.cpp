#include "../TasksList/polinom.h"
#include "gtest.h"


TEST(TList, can_create_empty_list) {
    ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_create_copied_list) {
    TList<int> list;
    ASSERT_NO_THROW(TList<int> q_copy(list));
}

TEST(TList, copied_list_is_equal_to_source) {
    TList<int> list;
    list.insFirst(1);
    list.insFirst(2);
    list.insFirst(3);

    TList<int> q_copy(list);

    EXPECT_EQ(list, q_copy);
}

TEST(TList, copied_list_has_its_own_memory) {
    TList<int> list;
    list.insFirst(1);
    list.insFirst(2);
    list.insFirst(3);

    TList<int> q_copy(list);
    list.clear();

    EXPECT_NE(list, q_copy);
}

TEST(TList, list_is_empty) {
    TList<int> list;
    ASSERT_TRUE(list.isEmpty());
}

TEST(TList, can_insert_element_in_empty_list) {
    TList<int> list;
    list.insFirst(10);
    ASSERT_FALSE(list.isEmpty());
    /*EXPECT_EQ(list.Front(), 10);
    EXPECT_EQ(list.Back(), 10);
    list.Push(1);
    EXPECT_NE(list.Front(), list.Back());*/
}
//TEST(TList, can_view_front_and_back_elements_in_list) {
//    TList<int> list;
//    list.insFirst(10);
//    EXPECT_EQ(list.Front(), 10);
//    EXPECT_EQ(list.Back(), 10);
//    list.Push(1);
//    EXPECT_EQ(list.Front(), 10);
//    EXPECT_EQ(list.Back(), 1);
//}
//
//TEST(TList, can_delete_element) {
//    TList<int> list;
//    list.Push(10);
//    list.Push(30);
//    list.Push(20);
//    EXPECT_EQ(list.Front(), 10);
//    EXPECT_EQ(list.Back(), 20);
//    list.Pop();
//    EXPECT_NE(list.Front(), 10);
//    EXPECT_EQ(list.Front(), 30);
//    EXPECT_EQ(list.Back(), 20);
//}

TEST(TList, no_throws_when_del_elem_from_empty_list) {
    TList<int> list;
    ASSERT_NO_THROW(list.delFirst());
    ASSERT_NO_THROW(list.delLast());
}

TEST(TList, list_becomes_empty_after_clearing) {
    TList<int> list;
    list.insFirst(1);
    list.insFirst(2);
    list.clear();

    ASSERT_TRUE(list.isEmpty());
}

TEST(TList, can_assign_list_to_itself) {
    TList<int> list;
    list.insFirst(1);
    list.insFirst(2);

    ASSERT_NO_THROW(list = list);
}


TEST(TList, assign_operator_list) {
    TList<int> l1, l2;
    l1.insFirst(1);
    l2.insFirst(2);
    l2 = l1;
    EXPECT_EQ(l1, l2);
}

TEST(TList, lists_are_equal) {
    TList<int> l1;
    TList<int> l2;

    l1.insFirst(1);
    l1.insFirst(2);
    l1.insFirst(3);
    l1.insFirst(4);
    l1.insFirst(5);


    l1.delLast();
    l1.delLast();

    l2.insFirst(3);
    l2.insFirst(4);
    l2.insFirst(5);

    EXPECT_EQ(l1, l2);
}

TEST(TList, move_list1_in_list2_assigment_operator_) {
    TList<int> l1;
    TList<int> l2;

    l1.insFirst(1);
    l1.insFirst(2);
    l1.insFirst(3);
    l1.insFirst(4);
    l1.insFirst(5);

    l2.insFirst(3);
    l2.insFirst(4);
    l2.insFirst(5);

    TList<int> l1_copy = l1;
    TList<int> l2_copy = l2;
    l2 = std::move(l1);
    EXPECT_EQ(l1, l2_copy);
}

TEST(TList, move_constructor_list1_in_list2) {
    TList<int> l1;

    l1.insFirst(1);
    l1.insFirst(2);
    l1.insFirst(3);
    l1.insFirst(4);
    l1.insFirst(5);
    TList<int>l1_copy = l1;
    TList<int>l2{ std::move(l1_copy) };
    EXPECT_EQ(l2, l1);
}

TEST(TList, can_swap_lists_with_std_swap) {
    TList<int> l1;
    TList<int> l2;

    l1.insFirst(1);
    l1.insFirst(2);
    l1.insFirst(3);
    l1.insFirst(4);
    l1.insFirst(5);

    l2.insFirst(3);
    l2.insFirst(4);
    l2.insFirst(5);

    TList<int> l1_copy = l1;
    TList<int> l2_copy = l2;
    std::swap(l1, l2);
    EXPECT_EQ(l1_copy, l2);
    EXPECT_EQ(l2_copy, l1);
}