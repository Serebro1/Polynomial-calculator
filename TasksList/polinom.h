#pragma once
#include "TList.h"
#include <cmath>
class Polinom : public TList<Monom> {
	
public:
	Polinom() {};
	Polinom(Monom* p, unsigned int size);
	
	void operator+=(const Monom m);
	void operator*=(double c);
	void operator*=(const Monom m);
	void operator-=(const Monom m);
	void operator+=(Polinom& p);
	void operator*=(Polinom& p);
	void operator-=(Polinom& p);
	Polinom operator+(Polinom& p);
	Polinom operator*(Polinom& p);
	Polinom operator-(Polinom& p);
	Polinom operator-();

	friend std::ostream& operator<<(std::ostream& out, const Polinom& p);
};
/*
* ����� ���������� ������.
* ������� ������� �� ��� �������
��� ��������� ��������
��������� ����� � ��������, ��������� � ������.

�������� ���������:
����� ���� �������� res, p
3 �������� ��������
������� ����� => ���������� ������������, ���� ��������� �� ����� 0, �� ��������� ���������,������� ��� ���������,
����� ������� ����� delCurr � ���������� ������ ��������� pCurr � p

������� �������� ������������� �������� ������ ���������������
����� �� ������ �������� ����� ����� ������� ��������������� � ������� ��������� pCurr � p.
���� �������� �� ������� pCurr � res

���� ���� �� ��� ����������, �� �� ������� �� ��������.
�������� � ����� ������ ����� ���������:
���� �� ��������� �������� � � ������� ������� ����� � p. ���������� ���������� ����� ��������������� ��������
���� �� ����� �� ����� � res, �� �� ������ �� ������.
*/