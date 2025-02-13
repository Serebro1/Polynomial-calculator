#include "../TasksList/monom.h"
#include "gtest.h"

TEST(Monom, can_create_empty_monom) {
    ASSERT_NO_THROW(Monom monom);
}
TEST(Monom, can_create_monom_with_params) {
    ASSERT_NO_THROW(Monom monom(1.2, 1, 2, 3));
}
TEST(Monom, can_compare_monoms) {
    Monom m1 = Monom(3.0, 3, 2, 1);
    Monom m2 = Monom(2.0, 3, 2, 1);
    EXPECT_TRUE(m2 <= m1);
    m1 = Monom(3.0, 3, 2, 2);
    m2 = Monom(2.0, 1, 2, 1);
    EXPECT_FALSE(m1 <= m2);
}
TEST(Monom, can_input_monom_with_params_and_output) {
    Monom monom;
    std::istringstream input("3 2 3 1");
    ASSERT_NO_THROW(input >> monom);
    EXPECT_EQ(monom.coeff, 3.0);
    EXPECT_EQ(monom.x, 2);
    EXPECT_EQ(monom.y, 3);
    EXPECT_EQ(monom.z, 1);
}
TEST(Monom, can_output_monom_with_params) {
    Monom monom;
    std::istringstream input("1.2 2 3 1");
    input >> monom;
    std::ostringstream output;
    ASSERT_NO_THROW(output << monom);
    EXPECT_EQ(output.str(), "1.2*x^2*y^3*z^1");
}