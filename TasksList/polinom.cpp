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

void Polinom::operator*=(double val)
{
	if (val == 0.0) { clear(); }
	for (Monom& m : *this) {
		m.coeff *= val;
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

void Polinom::operator*=(const Monom m)
{
	if (m.coeff == 0.0) { clear(); return; }
	for (Monom& elem : *this) {
		elem *= m;
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
void Polinom::operator+=(Polinom p)
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
void Polinom::operator*=(Polinom p)
{
	if (p.pFirst == nullptr) return;
	for (Monom& m : p) {
		*this *= m;
	}
}
void Polinom::operator-=(Polinom p)
{
	reset();
	p.reset();
	while (!isEnd() && !p.isEnd()) {
		if (pCurr->val > p.pCurr->val) {
			goNext();
		}
		else if (pCurr->val < p.pCurr->val) {
			insCurr(-p.pCurr->val);
			p.goNext();
		}
		else {
			Monom m(-p.pCurr->val);
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

Polinom Polinom::operator+(const Monom& m)
{
	Polinom res(*this);
	if (m.coeff == 0) return res;
	if (res.pFirst == nullptr || res.pFirst->val < m) {
		res.insFirst(m);
		return res;
	}
	if (m < res.pLast->val) {
		res.insLast(m);
		return res;
	}
	for (res.reset(); !res.isEnd(); res.goNext())
	{
		Monom src = res.pCurr->val;
		if (src < m) {
			res.insCurr(m);
			return res;
		}
		if (src == m) {
			double tmpCoeff = src.coeff + m.coeff;
			if (tmpCoeff != 0)
				res.pCurr->val.coeff = tmpCoeff;
			else {
				res.delCurr();
			}
			return res;
		}
	}
}

Polinom Polinom::operator*(const Monom& m)
{
	Polinom res;
	if (m.coeff == 0) return res;
	res = *this;
	for (Monom& elem : res) {
		elem *= m;
	}
	return res;
}

Polinom Polinom::operator-(const Monom& m)
{
	Polinom res(*this);
	if (m.coeff == 0) return res;
	if (res.pFirst == nullptr || res.pFirst->val < m) {
		res.insFirst(-m);
		return res;
	}
	if (m < res.pLast->val) {
		res.insLast(-m);
		return res;
	}
	for (res.reset(); !res.isEnd(); res.goNext())
	{
		Monom src = res.pCurr->val;
		if (src < m) {
			res.insCurr(-m);
			return res;
		}
		if (src == m) {
			double tmpCoeff = src.coeff - m.coeff;
			if (tmpCoeff != 0)
				res.pCurr->val.coeff = tmpCoeff;
			else {
				res.delCurr();
			}
			return res;
		}
	}
}

Polinom Polinom::operator+(Polinom p)
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

Polinom Polinom::operator*(Polinom p)
{
	Polinom res;
	if (pFirst == nullptr || p.pFirst == nullptr) return res;
	res = *this;
	for (Monom& m : p) {
		res *= p;
	}
	return res;
}

Polinom Polinom::operator-(Polinom p)
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
				res.pCurr->val.coeff = -m.coeff;
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
	Polinom res(*this);
	if (res.pFirst == nullptr) return res;
	for (Monom& m : res) {
		m = -m;
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, Polinom p)
{
	if (p.pFirst == nullptr) return out;
	out << p.pFirst->val;
	for (auto it = std::next(p.begin()); it != p.end(); ++it)
	{
		out << (it->coeff < 0.0 ? " - " : " + ");
		Monom tmp = *it;
		tmp.coeff = std::abs(tmp.coeff);
		out << tmp;
	}
}
