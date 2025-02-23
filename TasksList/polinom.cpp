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