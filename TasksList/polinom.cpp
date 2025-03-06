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
// Practice
void Polinom::operator+=(Polinom& p)
{
	reset();
	p.reset();
	while (!isEnd() && !p.isEnd()) {
		if (pCurr->val > p.pCurr->val) {
			goNext();
		}
		else if (pCurr->val < p.pCurr->val) {
			insCurr(p.pCurr->val);
			p.goNext();
		}
		else {
			Monom m(p.pCurr->val);
			m.coeff += pCurr->val.coeff;
			if (m.coeff == 0.0) {
				delCurr();
			}
			else {
				pCurr->val.coeff = m.coeff;
				goNext();
			}
			p.goNext();
		}
	}
}
void Polinom::operator*=(Polinom& p)
{
}
void Polinom::operator-=(Polinom& p)
{
}
Polinom Polinom::operator+(Polinom& p)
{
	Polinom res(*this);
	res.reset();
	p.reset();
	while (!res.isEnd() && !p.isEnd()) {
		if (res.pCurr->val > p.pCurr->val) {
			res.goNext();
		}
		else if (res.pCurr->val < p.pCurr->val) {
			res.insCurr(p.pCurr->val);
			p.goNext();
		}
		else {
			Monom m(p.pCurr->val);
			m.coeff += res.pCurr->val.coeff;
			if (m.coeff == 0.0) {
				res.delCurr();
			}
			else {
				res.pCurr->val.coeff = m.coeff;
				res.goNext();
			}
			p.goNext();
		}
	}
	while (!p.isEnd()) {
		res.insLast(p.pCurr->val);
		p.goNext();
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
	Polinom res(*this);
	res.reset();
	p.reset();
	while (!res.isEnd() && !p.isEnd()) {
		if (res.pCurr->val > p.pCurr->val) {
			res.goNext();
		}
		else if (res.pCurr->val < p.pCurr->val) {
			res.insCurr(-p.pCurr->val);
			p.goNext();
		}
		else {
			Monom m(p.pCurr->val);
			m.coeff -= res.pCurr->val.coeff;
			if (m.coeff == 0.0) {
				res.delCurr();
			}
			else {
				res.pCurr->val.coeff = m.coeff;
				res.goNext();
			}
			p.goNext();
		}
	}
	while (!p.isEnd()) {
		res.insLast(-p.pCurr->val);
		p.goNext();
	}
	return res;
}

Polinom Polinom::operator-()
{
	Polinom res;
	if (pFirst == nullptr) return res;
	for (Monom& m : *this) {
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
