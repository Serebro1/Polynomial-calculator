#include "gtest.h"
#include "../TasksList/polinom.cpp"

// Constructs
TEST(Polinom, default_constructor) {
	ASSERT_NO_THROW(Polinom p);
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, init_constructor) {
	Monom* mons = new Monom[2];
	mons[0] = Monom(2.0, 1, 0, 0);
	mons[1] = Monom(3.0, 0, 1, 0);
	Polinom p(mons, 2);
}
//----------------------------------------------------------------------------------------
// Plus assigment
TEST(Polinom, can_use_operator_plus_assigment_monom) {
	Polinom p;
	ASSERT_NO_THROW(p += Monom(3.5, 0, 1, 0));
	EXPECT_FALSE(p.isEmpty());
	EXPECT_EQ(*(p.begin()), Monom(3.5, 0, 1, 0));
}
TEST(Polinom, operator_plus_assigment_null_monom) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	ASSERT_NO_THROW(p += Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, operator_plus_assigment_negative_monom) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	ASSERT_NO_THROW(p += Monom(-1.5, 2, 1, 0));

	EXPECT_EQ(*(p.begin()), Monom(-1.5, 2, 1, 0));
}
TEST(Polinom, operator_plus_assigment_monoms_with_diff_sign_of_equal_coeff) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	p += Monom(-1.0, 2, 1, 0);
	p += Monom(1.0, 2, 1, 0);
	EXPECT_TRUE(p.isEmpty());
}
//----------------------------------------------------------------------------------------
// Multiply assigment
TEST(Polinom, can_use_operator_multiply_assigment_monom) {
	Polinom p;
	p += Monom(1.0, 0, 0, 0);
	ASSERT_NO_THROW(p *= Monom(3.5, 0, 1, 0));
	EXPECT_EQ(*(p.begin()), Monom(3.5, 0, 1, 0));
}
TEST(Polinom, operator_multiply_assigment_null_monom) {
	Polinom p;
	p += Monom(1.5, 1, 2, 0);
	EXPECT_FALSE(p.isEmpty());
	ASSERT_NO_THROW(p *= Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, operator_multiply_assigment_negative_monom) {
	Monom* mons = new Monom[2];
	mons[0] = Monom{ 1.0, 0, 0, 0 };
	mons[1] = Monom{ 2.5, 1, 3, 2 };
	Polinom p(mons, 2);
	ASSERT_NO_THROW(p *= Monom(-1.5, 2, 1, 0));
	auto it = p.begin();
	EXPECT_EQ((*it), Monom(-3.75, 3, 4, 2));
	++it;
	EXPECT_EQ((*it), Monom(-1.5, 2, 1, 0));

}
//----------------------------------------------------------------------------------------
// Subtract assigment
TEST(Polinom, can_use_operator_sub_assigment_monom) {
	Polinom p;
	ASSERT_NO_THROW(p -= Monom(3.5, 0, 1, 0));
	EXPECT_EQ(*(p.begin()), Monom(3.5, 0, 1, 0));
	ASSERT_NO_THROW(p -= Monom(-2.5, 1, 1, 0));
	EXPECT_EQ(*(p.begin()), Monom(2.5, 1, 1, 0));
}
TEST(Polinom, operator_sub_assigment_null_monom) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	ASSERT_NO_THROW(p -= Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, operator_sub_assigment_negative_monom) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	ASSERT_NO_THROW(p += Monom(-1.5, 2, 1, 0));

	EXPECT_EQ(*(p.begin()), Monom(-1.5, 2, 1, 0));
}
TEST(Polinom, operator_sub_assigment_monoms_with_diff_sign_of_equal_coeff) {
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
	p += Monom(1.0, 2, 1, 0);
	p -= Monom(-1.0, 2, 1, 0);
	EXPECT_EQ(*(p.begin()), Monom(2.0, 2, 1, 0));
	p -= Monom(2.0, 2, 1, 0);
	EXPECT_TRUE(p.isEmpty());
}
//----------------------------------------------------------------------------------------
// polinom + polinom
TEST(Polinom, empty_plus_empty) {
	Polinom p1;
	Polinom p2;
	ASSERT_NO_THROW(p1 + p2);
	ASSERT_NO_THROW(p2 + p1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 + p2);
	EXPECT_TRUE(res.isEmpty());
}
TEST(Polinom, empty_plus_polinom) {
	Polinom p1;
	p1 += Monom(2.5, 1, 3, 1);
	Polinom p2;
	Polinom res;
	ASSERT_NO_THROW(res = p1 + p2);
	EXPECT_EQ(*(p1.begin()), Monom(2.5, 1, 3, 1));
}
TEST(Polinom, polinom_plus_negative_polinom_that_are_equal) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p1 += Monom(1.5, 1, 3, 1);
	p2 += Monom(-2.5, 1, 2, 3);
	Polinom res;
	ASSERT_NO_THROW(res = p1 + p2);
	EXPECT_EQ(*(res.begin()), Monom(1.5, 1, 3, 1));
	res -= Monom(2, 1, 3, 1);
	EXPECT_EQ(*(res.begin()), Monom(-0.5, 1, 3, 1));
}
TEST(Polinom, simple_plus_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p2 += Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 + p2);
	auto it = res.begin();
	res += Monom(2.5, 1, 2, 3);
	EXPECT_EQ(*(it), Monom(5, 1, 2, 3));
	++it;
	EXPECT_EQ(*(it), Monom(1.5, 1, 3, 1));
}
TEST(Polinom, plus_negative_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 -= Monom(2.5, 1, 2, 3);
	p2 -= Monom(1.5, 1, 3, 1);
	Polinom res;

	ASSERT_NO_THROW(res = p1 + p2);

	auto it = res.begin();
	res += Monom(2.5, 1, 2, 3);
	EXPECT_EQ(*(it), Monom(-1.5, 1, 3, 1));
	++it;
	EXPECT_TRUE(it == res.end());
}
//----------------------------------------------------------------------------------------
// polinom * polinom
TEST(Polinom, empty_mult_empty) {
	Polinom p1;
	Polinom p2;
	ASSERT_NO_THROW(p1 * p2);
	ASSERT_NO_THROW(p2 * p1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 * p2);
	EXPECT_TRUE(res.isEmpty());
}
TEST(Polinom, empty_mult_polinom) {
	Polinom p1;
	p1 += Monom(2.5, 1, 3, 1);
	Polinom p2;
	Polinom res;
	ASSERT_NO_THROW(res = p1 * p2);
	EXPECT_TRUE(res.isEmpty());
}
TEST(Polinom, simple_mult_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p1 += Monom(2.0, 3, 2, 1);
	p2 += Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 * p2);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(3.0, 4, 5, 2));
	++it;
	EXPECT_EQ(*(it), Monom(3.75, 2, 5, 4));
}
TEST(Polinom, simple_mult_negative_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 -= Monom(2.5, 1, 2, 3);
	p1 -= Monom(2.0, 3, 2, 1);
	p2 -= Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 * p2);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(3.0, 4, 5, 2));
	++it;
	EXPECT_EQ(*(it), Monom(3.75, 2, 5, 4));
}
//----------------------------------------------------------------------------------------
// polinom - polinom
TEST(Polinom, empty_sub_empty) {
	Polinom p1;
	Polinom p2;
	Polinom res;
	ASSERT_NO_THROW(p1 - p2);
	ASSERT_NO_THROW(p2 - p1);
	res = p1 - p2;
	EXPECT_TRUE(res.isEmpty());
}
TEST(Polinom, empty_minus_polinom) {
	Polinom p1;
	p1 += Monom(2.5, 1, 3, 1);
	Polinom p2;
	Polinom res;
	ASSERT_NO_THROW(res = p1 - p2);
	EXPECT_EQ(*(p1.begin()), Monom(-2.5, 1, 3, 1));
}
TEST(Polinom, polinom_sub_negative_polinom_that_are_equal) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p1 += Monom(1.5, 1, 0, 1);
	p2 += Monom(-2.5, 1, 2, 3);
	Polinom res;
	ASSERT_NO_THROW(res = p1 - p2);
	EXPECT_EQ(*(res.begin()), Monom(5, 1, 2, 3));
	res -= Monom(5, 1, 2, 3);
	res -= Monom(2, 1, 0, 1);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(-0.5, 1, 0, 1));
	++it;
	EXPECT_TRUE(it == res.end());
}
TEST(Polinom, simple_sub_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p2 += Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 - p2);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(-1.5, 1, 3, 1));
	++it;
	EXPECT_EQ(*(it), Monom(2.5, 1, 2, 3));
}
TEST(Polinom, sub_negative_polinoms) {
	Polinom p1;
	Polinom p2;
	p1 -= Monom(2.5, 1, 2, 3);
	p2 -= Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 - p2);
	auto it = res.begin();
	res += Monom(2.5, 1, 2, 3);
	EXPECT_EQ(*(it), Monom(-1.5, 1, 3, 1));
	++it;
	EXPECT_TRUE(it == res.end());
}
//----------------------------------------------------------------------------------------
// Unar minus
TEST(Polinom, minus_empty) {
	Polinom p;
	p = -p;
}
TEST(Polinom, invers_sign_of_polinom) {
	Polinom p1;
	Polinom p2;
	p1 += Monom(2.5, 1, 2, 3);
	p2 -= Monom(1.5, 1, 3, 1);
	Polinom res = p1 - p2;
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(-1.5, 1, 3, 1));
	++it;
	EXPECT_EQ(*(it), Monom(2.5, 1, 2, 3));

	ASSERT_NO_THROW(res = -res);
	it = res.begin();
	EXPECT_EQ(*(it), Monom(1.5, 1, 3, 1));
	++it;
	EXPECT_EQ(*(it), Monom(-2.5, 1, 2, 3));
}
//----------------------------------------------------------------------------------------
// Output
TEST(Polinom, can_output_polinom_with_params) {
	Monom* mons = new Monom[3];
	mons[0] = Monom(-2.0, 1, 0, 0);
	mons[1] = Monom(3.0, 0, 1, 0);
	mons[2] = Monom(-1.4, 1, 0, 2);

	Polinom p(mons, 3);
    std::ostringstream output;
    ASSERT_NO_THROW(output << p);
    EXPECT_EQ(output.str(), "-1.4*x^1*z^2 - 2*x^1 + 3*y^1");
}