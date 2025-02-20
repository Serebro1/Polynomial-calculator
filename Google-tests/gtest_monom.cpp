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
    EXPECT_TRUE(m2 == m1);
    m1 = Monom(3.0, 3, 2, 2);
    m2 = Monom(2.0, 1, 2, 1);
    EXPECT_FALSE(m1 < m2);
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
TEST(Monom, DefaultConstructor) {
    Monom m;
    EXPECT_DOUBLE_EQ(m.coeff, 0.0);
    EXPECT_EQ(m.x, 0);
    EXPECT_EQ(m.y, 0);
    EXPECT_EQ(m.z, 0);
}

TEST(Monom, ParameterizedConstructor) {
    Monom m(3.5, 2, 3, 1);
    EXPECT_DOUBLE_EQ(m.coeff, 3.5);
    EXPECT_EQ(m.x, 2);
    EXPECT_EQ(m.y, 3);
    EXPECT_EQ(m.z, 1);
}

TEST(Monom, LessThanOperator) {
    // Случай меньшей степени
    Monom m1(3, 1, 2, 3);
    Monom m2(3, 2, 3, 4);
    EXPECT_TRUE(m1 < m2);

    // Случай большей степени
    Monom m3(3, 3, 0, 0);
    Monom m4(3, 2, 9, 9);
    EXPECT_FALSE(m3 < m4);

    // Равные степени
    Monom m5(3, 2, 3, 4);
    Monom m6(3, 2, 3, 4);
    EXPECT_FALSE(m5 < m6);
}

TEST(Monom, EqualityOperator) {
    // Равные степени, разные коэффициенты
    Monom m1(2.5, 1, 2, 3);
    Monom m2(3.0, 1, 2, 3);
    EXPECT_TRUE(m1 == m2);

    // Нулевые мономы
    Monom m3(0.0, 0, 0, 0);
    Monom m4(0.0, 0, 0, 0);
    EXPECT_TRUE(m3 == m4);

    // Разные степени
    Monom m5(1.0, 1, 0, 0);
    Monom m6(1.0, 0, 1, 0);
    EXPECT_FALSE(m5 == m6);
}

TEST(Monom, OutputOperator) {
    // Обычный случай
    Monom m1(2.5, 3, 0, 1);
    std::stringstream ss1;
    ss1 << m1;
    EXPECT_EQ(ss1.str(), "2.5*x^3*z^1");

    // Только коэффициент
    Monom m2(-4.0, 0, 0, 0);
    std::stringstream ss2;
    ss2 << m2;
    EXPECT_EQ(ss2.str(), "-4");

    // Нет x-компоненты
    Monom m3(1.5, 0, 2, 3);
    std::stringstream ss3;
    ss3 << m3;
    EXPECT_EQ(ss3.str(), "1.5*y^2*z^3");

    // Все компоненты
    Monom m4(-2.0, 1, 1, 1);
    std::stringstream ss4;
    ss4 << m4;
    EXPECT_EQ(ss4.str(), "-2*x^1*y^1*z^1");
}

TEST(Monom, InputOperator) {
    Monom m;
    std::stringstream ss("5.5 2 3 1");
    ss >> m;
    EXPECT_DOUBLE_EQ(m.coeff, 5.5);
    EXPECT_EQ(m.x, 2);
    EXPECT_EQ(m.y, 3);
    EXPECT_EQ(m.z, 1);

    // Проверка на некорректный ввод (опционально)
    Monom m2;
    std::stringstream ss2("abc 1 2 3");
    ss2 >> m2;
    EXPECT_TRUE(ss2.fail()); // Проверяем флаг ошибки
}