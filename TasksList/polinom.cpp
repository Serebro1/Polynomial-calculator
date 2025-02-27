/*
����������:
	��� ������� ��������� ����������� ��������, ������� ����� ��������� ������ �������
	������� ��� ���� � �������� ������ �� �� �� ������
	��������� ������������� ������, ����� ���:
	�������� �� �������, ���������� �� �������, ��������, ���������
	���������� ������� �������� ����� ������ � .cpp �����
*/
#include "polinom.h"
Polinom::Polinom(Monom* p, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		insLast(p[i]);
	}
}

void Polinom::operator+=(Monom m)
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
	iterator it = begin();
	for (it = begin(); it != end(); ++it)
	{
		if (*it < m) {
			insCurr(m);
			return;
		}
		if (*it == m) {
			double tmpCoeff = (*it).coeff + m.coeff;
			if (tmpCoeff != 0)
				(*it).coeff = tmpCoeff;
			else {
				delCurr();
			}
			return;
		}
	}
}
void Polinom::operator*=(double val)
{
	if (val == 0.0) { clear(); } // ������� ��� ������ ������
	iterator it = begin();
	for (it = begin(); it != end(); ++it)
		(*it).coeff *= val;
}

Polinom Polinom::operator+(Polinom& p)
{
	Polinom res;
	if (pFirst == nullptr) return res = p;
	iterator it = begin();
	iterator pit = p.begin();
	while (it != end() && pit != p.end()) {
		if (*it == *pit) {
			res += *pit;
			++it;
			++pit;
			continue;
		}
		if (*it < *pit){
			res += *pit;
			++pit;
			continue;
		}
		if (*it < *pit){
			res += *pit;
			++pit;
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
//Polinom Polinom::operator*(const Polinom& p)
//{
//	Polinom res(p), tmp(p);
//	iterator it = begin();
//	for (it = begin(); it != end(); ++it)
//		res += tmp * (*it);
//}
//Polinom Polinom::operator*(const Monom& m)
//{
//	
//}