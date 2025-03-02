#include "../TasksList/Polinom.h"
#include "gtest.h"


TEST(TList, can_create_empty_list) {
    ASSERT_NO_THROW(TList<int> list);
    TList<int> list;
    EXPECT_TRUE(list.isEmpty());
}

TEST(TList, can_create_copied_list) {
    TList<int> list;
    ASSERT_NO_THROW(TList<int> q_copy(list));
    TList<int> q_copy(list);
    EXPECT_TRUE(q_copy.isEmpty());
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
    ASSERT_NO_THROW(list.insFirst(10));
}
TEST(TList, can_move_to_next_element_in_list) {
    TList<int> list;
    list.insFirst(10);
    list.insFirst(9);
    list.insFirst(8);

    list.reset();
    list.goNext();
}
TEST(TList, can_get_curr_elements_in_list) {
    TList<int> list;
    list.insFirst(10);
    list.reset();
    EXPECT_EQ(list.getCurr(), 10);

    list.insLast(1);
    list.goNext();
    EXPECT_EQ(list.getCurr(), 1);
}
TEST(TList, can_start_custom_iterator_in_list) {
    TList<int> list;
    list.insFirst(10);
    list.insFirst(9);
    list.reset();
    list.goNext();
    list.goNext();
    EXPECT_TRUE(list.isEnd());
    list.reset();
    EXPECT_EQ(list.getCurr(), 9);

}
TEST(TList, can_iterate_with_curr_element_in_list) {
    TList<int> list;
    list.insFirst(10);
    list.insFirst(9);
    list.insFirst(8);
    
    list.reset();
    EXPECT_EQ(list.getCurr(), 8);

    list.goNext();
    EXPECT_EQ(list.getCurr(), 9);

    list.goNext();
    EXPECT_EQ(list.getCurr(), 10);

    list.goNext();
    EXPECT_TRUE(list.isEnd());
    
    for ( list.reset(); !list.isEnd(); list.goNext() )
    {
        ASSERT_NO_THROW(list.getCurr());
    }
}
TEST(TList, index_operator) {
    TList<int> list;
    list.insLast(10);
    list.insLast(30);
    list.insLast(20);
    ASSERT_ANY_THROW(list[-1]);
    ASSERT_ANY_THROW(list[4]);
    EXPECT_EQ(list[0], 10);
    EXPECT_EQ(list[1], 30);
    EXPECT_EQ(list[2], 20);
}
TEST(TList, can_delete_element) {
    TList<int> list;
    list.insLast(10);
    list.insLast(30);
    list.insLast(20);

    list.delLast();
    auto it = list.begin();

    EXPECT_EQ(*it, 10);
    EXPECT_EQ(*(++it), 30);
}

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