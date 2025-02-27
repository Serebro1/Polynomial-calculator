#include "../TasksList/polinom.h"
#include "gtest.h"
class ListIteratorTest : public ::testing::Test {
protected:
    TList<int> list;

    void SetUp() override {
        list.insLast(10);
        list.insLast(20);
        list.insLast(30);
    }
};

// ���� 1: �������� ������� ���������������� ���������
TEST_F(ListIteratorTest, BasicIteration) {
    auto it = list.begin();

    ASSERT_EQ(*it, 10);

    ++it;
    ASSERT_EQ(*it, 20);

    ++it;
    ASSERT_EQ(*it, 30);

    ++it;
    ASSERT_EQ(it, list.end());
}

// ���� 2: �������� ���������� ���������
TEST_F(ListIteratorTest, ComparisonOperators) {
    auto it1 = list.begin();
    auto it2 = list.begin();

    ASSERT_TRUE(it1 == it2);
    ASSERT_FALSE(it1 != it2);

    ++it1;
    ASSERT_TRUE(it1 != it2);
    ASSERT_FALSE(it1 == it2);
}

// ���� 4: �������� ��������� ->
TEST_F(ListIteratorTest, ArrowOperator) {
    struct TestStruct { int a; };
    TList<TestStruct> structList;
    structList.insLast(TestStruct{ 42 });

    auto it = structList.begin();
    ASSERT_EQ(it->a, 42);
}

// ���� 5: �������� ����������� ���������
TEST_F(ListIteratorTest, IteratorCopy) {
    auto it1 = list.begin();
    auto it2(it1);

    ASSERT_EQ(*it1, *it2);
    ++it1;
    ASSERT_NE(*it1, *it2);
}

// ���� 6: �������� end() ���������
TEST_F(ListIteratorTest, EndIterator) {
    auto it = list.begin();
    while (it != list.end()) {
        ++it;
    }
    assert(++it);
}