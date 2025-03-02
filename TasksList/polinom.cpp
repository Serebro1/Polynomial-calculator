/*
Функционал:
	Для отладки необходим констурктор полинома, который будет принимать массив мономов
	Считаем что если в полиноме ничего не то он пустой
	Реализует специфические методы, такие как:
	хранение по порядку, добавление по порядку, сложение, вычитание
	Реализацию функций полинома нужно писать в .cpp файле
*/
#include "polinom.h"
Polinom::Polinom(Monom* p, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		*this += p[i];
	}
}

void Polinom::operator+=(const Monom m)
{
	if (m.coeff == 0) return;
	if (pFirst == nullptr || pFirst->val < m) {
		insFirst(m);
		return;
	}
	if (m < pLast->val) {
		insLast(m);
		return;
	}
	for (reset(); !isEnd(); goNext())
	{
		Monom src = pCurr->val;
		if (src < m) {
			insCurr(m);
			return;
		}
		if (src == m) {
			double tmpCoeff = src.coeff + m.coeff;
			if (tmpCoeff != 0)
				pCurr->val.coeff = tmpCoeff;
			else {
				delCurr();
			}
			return;
		}
	}
}

void Polinom::operator*=(double val)
{
	if (val == 0.0) { clear(); } // удаляет все звенья списка
	iterator it = begin();
	for (it = begin(); it != end(); ++it)
		(*it).coeff *= val;
}

void Polinom::operator*=(const Monom m)
{
	if (m.coeff == 0.0) { clear(); return; }
	iterator it = begin();
	while (it != end()) {
		(*it) *= m; 
		++it;
	}
}

void Polinom::operator-=(const Monom m)
{
	if (m.coeff == 0.0) return;
	if (pFirst == nullptr || pFirst->val < m) {
		insFirst(-m);
		return;
	}
	if (m < pLast->val) {
		insLast(-m);
		return;
	}
	for (reset(); !isEnd(); goNext())
	{
		Monom src = pCurr->val;
		if (src < m) {
			insCurr(-m);
			return;
		}
		if (src == m) {
			double tmpCoeff = src.coeff - m.coeff;
			if (tmpCoeff != 0.0)
				pCurr->val.coeff = tmpCoeff;
			else {
				delCurr();
			}
			return;
		}
	}
}

Polinom Polinom::operator+(Polinom& p)
{
	if (pFirst == nullptr) return p;
	if (p.pFirst == nullptr) return *this;
	Polinom res;
	iterator it = begin();
	iterator pit = p.begin();
	while (it != end() && pit != p.end()) {
		if (*it == *pit) {
			res += *pit;
			res += *it;
			++it;
			++pit;
			continue;
		}
		if (*it < *pit){
			res += *pit;
			++pit;
			continue;
		}
		if (*pit < *it){
			res += *it;
			++it;
			continue;
		}
	}
	while (it != end()) {
		res += *it;
		++it;
	}
	while (pit != p.end()) {
		res += *pit;
		++pit;
	}
	return res;
}

Polinom Polinom::operator*(Polinom& p) // ask about perfomance
{
	Polinom res;
	if (pFirst == nullptr || p.pFirst == nullptr) return res;

	for (Monom& m1 : *this) {
		for (Monom& m2 : p) {
			res += (m1 * m2);
		}
	}
	return res;
}

Polinom Polinom::operator-(Polinom& p)
{
	Polinom res;
	if (pFirst == nullptr) return res = -p;
	if (p.pFirst == nullptr) return *this;
	iterator it = begin();
	iterator pit = p.begin();
	while (it != end() && pit != p.end()) {
		if (*it == *pit) {
			res -= *pit;
			res += *it;
			++it;
			++pit;
			continue;
		}
		if (*it < *pit) {
			res -= *pit;
			++pit;
			continue;
		}
		if (*pit < *it) {
			res += *it;
			++it;
			continue;
		}
	}
	while (it != end()) {
		res += *it;
		++it;
	}
	while (pit != p.end()) {
		res -= *pit;
		++pit;
	}
	return res;
}

Polinom Polinom::operator-()
{
	Polinom res;
	if (pFirst == nullptr) return res;
	for (const Monom& m : *this) {
		res += (-m);
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, const Polinom& p)
{
	if (p.pFirst == nullptr) return out;
	out << p.pFirst->val;
	auto it = p.begin();
	++it;
	for (;it != p.end(); ++it)
	{
		out << (it->coeff < 0.0 ? " - " : " + ");
		Monom tmp = *it;
		tmp.coeff = abs(tmp.coeff);
		out << tmp;
	}
}
