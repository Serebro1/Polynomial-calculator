#include "gtest.h"
#include "../TasksList/polinom.cpp"
class PolinomTest : public ::testing::Test {
protected:
	Polinom p;
	void SetUp() override {
		p.insFirst(Monom(2.0, 0, 1, 2));
		p.insFirst(Monom(-3.0, 1, 1, 1));
		p.insFirst(Monom(2.0, 1, 2, 3));
	}
};
// Constructs
TEST(Polinom, default_constructor) {
	ASSERT_NO_THROW(Polinom p);
	Polinom p;
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, init_empty_polinom) {
	Monom* monom = {};
	ASSERT_NO_THROW(Polinom p(monom, 0));
	Polinom p(monom, 0);
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, init_constructor) {
	Monom* mons = new Monom[2];
	mons[0] = Monom(2.0, 1, 0, 0);
	mons[1] = Monom(3.0, 0, 1, 0);
	ASSERT_NO_THROW(Polinom p(mons, 2));
}
//----------------------------------------------------------------------------------------
// Mult assigment polinom * coeff

//TEST_F(PolinomTest, mult_monom_with_null_coeff) {
//	p *= 0.0;
//	EXPECT_TRUE(p.isEmpty());
//}
//TEST_F(PolinomTest, mult_monom_with_null_coeff) {
//	p *= 2.0;
//	auto it = p.begin();
//	EXPECT_EQ(*(it), Monom(4.0, 1, 2, 3));
//	++it;
//	EXPECT_EQ(*(it), Monom(-6.0, 1, 1, 1));
//	++it;
//	EXPECT_EQ(*(it), Monom(4.0, 0, 1, 2));
//}
//----------------------------------------------------------------------------------------
// Plus assigment monom
TEST(Polinom, can_use_operator_plus_assigment_monom) {
	Polinom p;
	ASSERT_NO_THROW(p += Monom(3.5, 2, 1, 0));
	EXPECT_FALSE(p.isEmpty());
	EXPECT_EQ(*(p.begin()), Monom(3.5, 2, 1, 0));
}
TEST(Polinom, operator_plus_assigment_null_monom) {
	Polinom p;
	ASSERT_NO_THROW(p += Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, operator_plus_assigment_negative_monom) {
	Polinom p;
	ASSERT_NO_THROW(p += Monom(-1.5, 2, 1, 0));

	EXPECT_EQ(*(p.begin()), Monom(-1.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_plus_assigment_delete_left_monom) {
	ASSERT_NO_THROW(p += Monom(-2.0, 1, 2, 3));
	EXPECT_NE(*(p.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(p.begin()), Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p.getSize(), 2);
}
TEST_F(PolinomTest, operator_plus_assigment_delete_right_monom) {
	ASSERT_NO_THROW(p += Monom(-2.0, 0, 1, 2));
	EXPECT_NE(p[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p.getSize(), 2);
}
TEST_F(PolinomTest, operator_plus_assigment_delete_central_monom) {
	ASSERT_NO_THROW(p += Monom(3.0, 1, 1, 1));
	EXPECT_NE(p[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p.getSize(), 2);
}
//----------------------------------------------------------------------------------------
// Multiply assigment monom
TEST_F(PolinomTest, can_use_operator_multiply_assigment_monom) {
	ASSERT_NO_THROW(p *= Monom(3.5, 0, 1, 0));
	EXPECT_EQ(*(p.begin()), Monom(7.0, 1, 3, 3));
}
TEST_F(PolinomTest, operator_multiply_assigment_null_monom) {
	EXPECT_FALSE(p.isEmpty());
	ASSERT_NO_THROW(p *= Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST_F(PolinomTest, operator_multiply_assigment_negative_monom) {
	ASSERT_NO_THROW(p *= Monom(-1.5, 2, 1, 0));
	auto it = p.begin();
	EXPECT_EQ((*it), Monom(-3.75, 3, 3, 3));
	++it;
	EXPECT_EQ((*it), Monom(4.5, 3, 2, 1));
	++it;
	EXPECT_EQ((*it), Monom(-3.0, 2, 2, 2));
}
//----------------------------------------------------------------------------------------
// Subtract assigment monom
TEST(Polinom, can_use_operator_minus_assigment_monom) {
	Polinom p;
	ASSERT_NO_THROW(p -= Monom(3.5, 2, 1, 0));
	EXPECT_FALSE(p.isEmpty());
	EXPECT_EQ(*(p.begin()), Monom(-3.5, 2, 1, 0));
}
TEST(Polinom, operator_minus_assigment_null_monom) {
	Polinom p;
	ASSERT_NO_THROW(p -= Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(p.isEmpty());
}
TEST(Polinom, operator_minus_assigment_negative_monom) {
	Polinom p;
	ASSERT_NO_THROW(p -= Monom(-1.5, 2, 1, 0));

	EXPECT_EQ(*(p.begin()), Monom(1.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_minus_assigment_delete_left_monom) {
	ASSERT_NO_THROW(p -= Monom(2.0, 1, 2, 3));
	EXPECT_NE(*(p.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(p.begin()), Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p.getSize(), 2);
}
TEST_F(PolinomTest, operator_minus_assigment_delete_right_monom) {
	ASSERT_NO_THROW(p -= Monom(2.0, 0, 1, 2));
	EXPECT_NE(p[1], Monom(2.0, 1, 2, 3));
	EXPECT_EQ(p[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p.getSize(), 2);
}
TEST_F(PolinomTest, operator_minus_assigment_delete_central_monom) {
	ASSERT_NO_THROW(p -= Monom(-3.0, 1, 1, 1));
	EXPECT_NE(p[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p.getSize(), 2);
}
//----------------------------------------------------------------------------------------
// plus assigment polinom
TEST_F(PolinomTest, can_use_operator_plus_assigment_polinom) {
	Polinom p1;
	p1 += Monom(3.5, 2, 1, 0);
	ASSERT_NO_THROW(p1 += p);
	ASSERT_EQ(p1.getSize(), 4);
}
TEST_F(PolinomTest, operator_plus_assigment_null_polinom) {
	Polinom p1;
	ASSERT_NO_THROW(p += p1);
}
TEST_F(PolinomTest, operator_plus_assigment_negative_polinom) {
	Polinom p1;
	p1 += Monom(-1.5, 1, 2, 3);
	ASSERT_NO_THROW(p1 += p);
	EXPECT_EQ(*(p1.begin()), Monom(0.5, 1, 2, 3));
}
TEST_F(PolinomTest, operator_plus_assigment_polinoms_delete_left_monom) {
	Polinom p1;
	p1 += Monom(-2.0, 1, 2, 3);
	ASSERT_NO_THROW(p1 += p);
	EXPECT_NE(*(p1.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(p1.begin()), Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p1.getSize(), 2);
}
TEST_F(PolinomTest, operator_plus_assigment_polinoms_delete_right_monom) {
	Polinom p1;
	p1 += Monom(-2.0, 0, 1, 2);
	ASSERT_NO_THROW(p1 += p);
	EXPECT_NE(p1[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p1[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p1.getSize(), 2);
}
TEST_F(PolinomTest, operator_plus_assigment_polinoms_delete_central_monom) {
	Polinom p1;
	p1 += Monom(3.0, 1, 1, 1);
	ASSERT_NO_THROW(p1 += p);
	EXPECT_NE(p1[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(p1[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p1.getSize(), 2);
}
//----------------------------------------------------------------------------------------
// mult assigment polinom
TEST_F(PolinomTest, can_use_operator_multiply_assigment_polinom) {
	Polinom p1;
	p1 += Monom(3.5, 0, 1, 0);
	ASSERT_NO_THROW(p *= p1);
	EXPECT_EQ(*(p.begin()), Monom(7.0, 1, 3, 3));
}
TEST_F(PolinomTest, operator_multiply_assigment_null_polinom) {
	Polinom p1;
	ASSERT_NO_THROW(p *= p1);
	EXPECT_TRUE(p.isEmpty());
}
TEST_F(PolinomTest, operator_multiply_assigment_negative_polinom) {
	Polinom p1;
	p1 += Monom(-1.5, 2, 1, 0);
	ASSERT_NO_THROW(p *= p1);
	auto it = p.begin();
	EXPECT_EQ((*it), Monom(-3.75, 3, 3, 3));
	++it;
	EXPECT_EQ((*it), Monom(4.5, 3, 2, 1));
	++it;
	EXPECT_EQ((*it), Monom(-3.0, 2, 2, 2));
}
//----------------------------------------------------------------------------------------
// minus assigment polinom
TEST_F(PolinomTest, can_use_operator_minus_assigment_polinom) {
	Polinom p1;
	p1 += Monom(3.5, 2, 1, 0);
	ASSERT_NO_THROW(p1 -= p);
	ASSERT_EQ(p1.getSize(), 4);
}
TEST_F(PolinomTest, operator_minus_assigment_null_polinom) {
	Polinom p1;
	ASSERT_NO_THROW(p -= p1);
}
TEST_F(PolinomTest, operator_minus_assigment_negative_polinom) {
	Polinom p1;
	p1 += Monom(-1.5, 1, 2, 3);
	ASSERT_NO_THROW(p1 -= p);
	EXPECT_EQ(*(p1.begin()), Monom(3.5, 1, 2, 3));
}
TEST_F(PolinomTest, operator_minus_assigment_polinoms_delete_left_monom) {
	Polinom p1;
	p1 += Monom(2.0, 1, 2, 3);
	ASSERT_NO_THROW(p1 -= p);
	EXPECT_NE(*(p1.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(p1.begin()), Monom(3.0, 1, 1, 1));
	EXPECT_EQ(p1.getSize(), 2);
}
TEST_F(PolinomTest, operator_minus_assigment_polinoms_delete_right_monom) {
	Polinom p1;
	p1 += Monom(2.0, 0, 1, 2);
	ASSERT_NO_THROW(p1 -= p);
	EXPECT_NE(p1[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(p1[1], Monom(3.0, 1, 1, 1));
	EXPECT_EQ(p1.getSize(), 2);
}
TEST_F(PolinomTest, operator_minus_assigment_polinoms_delete_central_monom) {
	Polinom p1;
	p1 += Monom(-3.0, 1, 1, 1);
	ASSERT_NO_THROW(p1 -= p);
	EXPECT_NE(p1[1], Monom(3.0, 1, 1, 1));
	EXPECT_EQ(p1[1], Monom(-2.0, 0, 1, 2));
	EXPECT_EQ(p1.getSize(), 2);
}
//----------------------------------------------------------------------------------------
// polinom + monom
TEST_F(PolinomTest, can_use_operator_polinom_plus_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(3.5, 2, 1, 0));
	EXPECT_EQ(*(res.begin()), Monom(3.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_polinom_plus_null_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(0.0, 0, 0, 0));
	auto itres = res.begin();
	auto itp = p.begin();
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
}
TEST_F(PolinomTest, operator_polinom_plus_negative_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(-1.5, 2, 1, 0));
	EXPECT_EQ(*(res.begin()), Monom(-1.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_polinom_plus_monom_delete_left_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(-2.0, 1, 2, 3));
	EXPECT_NE(*(res.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(res.begin()), Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res.getSize(), 2);
}
TEST_F(PolinomTest, operator_polinom_plus_monom_delete_right_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(-2.0, 0, 1, 2));
	EXPECT_NE(res[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(res[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res.getSize(), 2);
}
TEST_F(PolinomTest, operator_polinom_plus_monom_delete_central_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p + Monom(3.0, 1, 1, 1));
	EXPECT_NE(res[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(res.getSize(), 2);
}
//----------------------------------------------------------------------------------------
// polinom * monom
TEST_F(PolinomTest, can_use_operator_polinom_multiply_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p * Monom(3.5, 0, 1, 0));
	EXPECT_EQ(*(res.begin()), Monom(7.0, 1, 3, 3));
}
TEST_F(PolinomTest, operator_polinom_multiply_null_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p * Monom(0.0, 0, 0, 0));
	EXPECT_TRUE(res.isEmpty());
}
TEST_F(PolinomTest, operator_polinom_multiply_negative_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p * Monom(-1.5, 2, 1, 0));
	auto it = res.begin();
	EXPECT_EQ((*it), Monom(-3.75, 3, 3, 3));
	++it;
	EXPECT_EQ((*it), Monom(4.5, 3, 2, 1));
	++it;
	EXPECT_EQ((*it), Monom(-3.0, 2, 2, 2));
}
//----------------------------------------------------------------------------------------
// polinom - monom
TEST_F(PolinomTest, can_use_operator_polinom_minus_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(3.5, 2, 1, 0));
	EXPECT_EQ(*(res.begin()), Monom(-3.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_polinom_minus_null_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(0.0, 0, 0, 0));
	auto itres = res.begin();
	auto itp = p.begin();
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
}
TEST_F(PolinomTest, operator_polinom_minus_negative_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(-1.5, 2, 1, 0));
	EXPECT_EQ(*(res.begin()), Monom(1.5, 2, 1, 0));
}
TEST_F(PolinomTest, operator_polinom_minus_monom_delete_left_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(2.0, 1, 2, 3));
	EXPECT_NE(*(res.begin()), Monom(2.0, 1, 2, 3));
	EXPECT_EQ(*(res.begin()), Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res.getSize(), 2);
}
TEST_F(PolinomTest, operator_polinom_minus_monom_delete_right_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(2.0, 0, 1, 2));
	EXPECT_NE(res[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(res[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res.getSize(), 2);
}
TEST_F(PolinomTest, operator_polinom_minus_monom_delete_central_monom) {
	Polinom res;
	ASSERT_NO_THROW(res = p - Monom(-3.0, 1, 1, 1));
	EXPECT_NE(res[1], Monom(-3.0, 1, 1, 1));
	EXPECT_EQ(res[1], Monom(2.0, 0, 1, 2));
	EXPECT_EQ(res.getSize(), 2);
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
TEST_F(PolinomTest, empty_plus_polinom) {
	Polinom p2;
	Polinom res;
	ASSERT_NO_THROW(res = p + p2);
	auto itres = res.begin();
	auto itp = p.begin();
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
	++itp;
	++itres;
	EXPECT_EQ(*itres, *itp);
}
TEST_F(PolinomTest, polinom_plus_opposit_sign_polinom) {
	Polinom copy;
	copy.insFirst(Monom(-2.0, 0, 1, 2));
	copy.insFirst(Monom(3.0, 1, 1, 1));
	copy.insFirst(Monom(-2.0, 1, 2, 3));
	Polinom res;
	ASSERT_NO_THROW(res = p + copy);
	EXPECT_TRUE(res.isEmpty());
}
TEST_F(PolinomTest, simple_plus_polinoms) {
	Polinom p1;
	p1 += Monom(2.5, 1, 2, 3);
	p1 += Monom(1.5, 1, 3, 1);
	Polinom res;
	ASSERT_NO_THROW(res = p1 + p);
	EXPECT_TRUE(res.getSize(), 4);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(1.5, 1, 3, 1));
	++it;
	EXPECT_EQ(*(it), Monom(4.5, 1, 2, 3));
	++it;
	EXPECT_EQ(*(it), Monom(3.0, 1, 1, 1));
	++it;
	EXPECT_EQ(*(it), Monom(2.0, 0, 1, 2));
}
TEST_F(PolinomTest, plus_negative_polinoms) {
	Polinom p1;
	p1 += Monom(-3.0, 1, 1, 1);
	Polinom res;

	ASSERT_NO_THROW(res = p + p1);

	EXPECT_EQ(res[1], Monom(-6, 1, 1, 1));
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
TEST_F(PolinomTest, empty_mult_polinom) {
	Polinom p1;
	Polinom res;
	ASSERT_NO_THROW(res = p * p1);
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
TEST_F(PolinomTest, polinom_plus_same_opposit_sign_polinom) {
	Polinom copy;
	copy.insFirst(Monom(-2.0, 0, 1, 2));
	copy.insFirst(Monom(3.0, 1, 1, 1));
	copy.insFirst(Monom(-2.0, 1, 2, 3));
	Polinom res;
	ASSERT_NO_THROW(res = p - copy);
	auto it = res.begin();
	EXPECT_EQ(*(it), Monom(4.0, 1, 2, 3));
	++it;
	EXPECT_EQ(*(it), Monom(-6.0, 1, 1, 1));
	++it;
	EXPECT_EQ(*(it), Monom(4.0, 0, 1, 2));
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
TEST_F(PolinomTest, sub_negative_polinoms) {
	Polinom p1;
	p1 += Monom(-3.0, 1, 1, 1);
	Polinom res;

	ASSERT_NO_THROW(res = p - p1);

	EXPECT_NE(res[1], Monom(-6, 1, 1, 1));
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
    EXPECT_EQ(output.str(), "-1.4*x*z^2 - 2*x + 3*y");
}