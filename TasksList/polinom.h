#pragma once
#include "monom.h"
#include "TList.h"

class Polinom : public TList<Monom> {
	
public:
	Polinom(Monom* p, unsigned int size);
	
	void operator+=(Monom m);
	void operator*=(double c);
	Polinom operator+(Polinom& p);
	Polinom operator*(const Polinom& p);
	Polinom operator*(const Monom& m);
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