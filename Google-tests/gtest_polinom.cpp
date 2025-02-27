#include "gtest.h"
#include "../TasksList/polinom.cpp"


TEST(Polinom, test) {
	Monom* mons = new Monom[2];
	mons[0] = Monom(2.0, 1, 0, 0);
	mons[1] = Monom(3.0, 0, 1, 0);
	Polinom p(mons, 2);
}