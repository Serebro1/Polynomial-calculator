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
		
		for (reset(); !isEnd(); goNext())
		{
			if (pCurr->val < m) {
				Node<Monom>* tmp = new Node<Monom>();
				tmp->val = m;
				tmp->pNext = pCurr;
				pPrev->pNext = tmp;
				return;
			}
			else if (pCurr->val == m) {
				double tmpCoeff = pCurr->val.coeff + m.coeff;
				if (tmpCoeff != 0)
					pCurr->val.coeff = tmpCoeff;
				else {
					delCurr();
				}
			}
		}
	}
	
}