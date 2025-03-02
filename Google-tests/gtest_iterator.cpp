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

TEST_F(ListIteratorTest, BasicIteration) {
    auto it = list.begin();

    EXPECT_EQ(*it, 10);

    ++it;
    EXPECT_EQ(*it, 20);

    ++it;
    EXPECT_EQ(*it, 30);

    ++it;
    EXPECT_EQ(it, list.end());
}
TEST_F(ListIteratorTest, ForIterator) {
    auto it = list.begin();
    int i = 0;
    for (it = list.begin(); it!=list.end(); ++it, i++)
    {
        switch (i) {
        case 0:
            EXPECT_EQ(*it, 10);
            break;
        case 1:
            EXPECT_EQ(*it, 20);
            break;
        case 2:
            EXPECT_EQ(*it, 30);
            break;
        }
    }
    i = 0;
    for (int& el : list) {
        switch (i) {
        case 0:
            EXPECT_EQ(el, 10);
            break;
        case 1:
            EXPECT_EQ(el, 20);
            break;
        case 2:
            EXPECT_EQ(el, 30);
            break;
        }
        i++;
    }
}
TEST_F(ListIteratorTest, ComparisonOperators) {
    auto it1 = list.begin();
    auto it2 = list.begin();

    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 != it2);

    ++it1;
    EXPECT_TRUE(it1 != it2);
    EXPECT_FALSE(it1 == it2);
}
TEST_F(ListIteratorTest, PointerOperator) {
    Monom m = Monom{3.0, 1, 2, 0};
    TList<Monom> structList;
    structList.insLast(m);

    auto it = structList.begin();
    EXPECT_EQ(*it, m);
}
TEST_F(ListIteratorTest, ArrowOperator) {
    Monom m = Monom{ 3.0, 1, 2, 0 };
    TList<Monom> structList;
    structList.insLast(m);

    auto it = structList.begin();
    EXPECT_EQ(it->coeff, 3.0);
    EXPECT_EQ(it->x, 1);
    EXPECT_EQ(it->y, 2);
    EXPECT_EQ(it->z, 0);
}

TEST_F(ListIteratorTest, IteratorCopy) {
    auto it1 = list.begin();
    auto it2(it1);

    EXPECT_EQ(*it1, *it2);
    ++it1;
    EXPECT_NE(*it1, *it2);
}

TEST_F(ListIteratorTest, EndIterator) {
    list.reset();
    auto it = list.begin();
    while (it != list.end()) {
        ++it;
        list.goNext();
    }
    EXPECT_EQ(list.isEnd(), it == list.end());
}