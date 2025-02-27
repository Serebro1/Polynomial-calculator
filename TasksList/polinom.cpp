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
	if (pFirst == nullptr || pFirst->val < m) insLast(m);
	else if (m < pLast->val) insLast(m);
	else {
		iterator it = begin();
		for (it = begin(); it != end(); ++it)
		{
			if (*it < m) {
				insCurr(m);
				return;
			}
			else if (*it == m) {
				double tmpCoeff = (*it).coeff + m.coeff;
				if (tmpCoeff != 0)
					(*it).coeff = tmpCoeff;
				else {
					delCurr();
				}
			}
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

Polinom Polinom::operator+(const Polinom& p)
{
	Polinom res(p);
	iterator it = begin();
	for (it = begin() ; it != end(); ++it)
		res += *it;
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